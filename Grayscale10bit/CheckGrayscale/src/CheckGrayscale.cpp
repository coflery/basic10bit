//
// CheckGrayscale.cpp
//
// Main program that enumerates all attached displays and checks using NVAPI 
// which displays are grayscale compatible
//
// Copyright (c) NVIDIA Corporation. All rights reserved.
////////////////////////////////////////////////////////////////////////////////

#include <windows.h>
#include <stdio.h>
#include <gl\gl.h>
#include <string>
#include <vector>
#include "CDisplayWin.h"
#include "nvapi.h"
using namespace std;

vector<string> grayMonitors; //array of grayscale monitor descriptor string
vector<string> grayGPUs ;  //array of grayscale compatible gpu string

//Enumerates all atatched displays and fills the displayWinList array
//for use later in the window creation and grayscale compatibility query
void enumDisplaysGDI() {
	DISPLAY_DEVICE  dispDevice;
	memset((void *)&dispDevice, 0, sizeof(DISPLAY_DEVICE));
	dispDevice.cb = sizeof(DISPLAY_DEVICE);

	DWORD allDisplayCount = 0; //including unnacttached and mirrrored displays	
	// loop through the displays and print out state
	while (EnumDisplayDevices(NULL,allDisplayCount,&dispDevice,0)) {
		//only process attached displays
		if (dispDevice.StateFlags & DISPLAY_DEVICE_ACTIVE) {
			strcpy(displayWinList[displayCount].gpuName,dispDevice.DeviceString);
			strcpy(displayWinList[displayCount].displayName, dispDevice.DeviceName);
			if (dispDevice.StateFlags & DISPLAY_DEVICE_PRIMARY_DEVICE)
				displayWinList[displayCount].primary = true;
			//get the display resolution etc
			DEVMODE devMode;
			memset((void *)&devMode, 0, sizeof(devMode));
			devMode.dmSize = sizeof(devMode);
			EnumDisplaySettings(dispDevice.DeviceName, ENUM_CURRENT_SETTINGS, &devMode);
			displayWinList[displayCount].setRect(devMode.dmPosition.x, devMode.dmPosition.y, devMode.dmPelsWidth, devMode.dmPelsHeight);	
			displayCount++;
		}
		allDisplayCount++;
	} //while(enumdisplay);
}

//Check if incoming fullstring matches with any of the grayMonitors entries
bool isGrayscaleMonitor(NvU8 fullstring[], unsigned int nStr) {
	for (int curMon=0;curMon<grayMonitors.size();curMon++) {
		const char* szGrayMonitor = grayMonitors[curMon].c_str();
		unsigned int nSubStr = strlen(szGrayMonitor);
		// Searching 
		for (int j = 0; j <= (nStr - nSubStr); ++j) {
			unsigned int i;
			for (i = 0; i < nSubStr && szGrayMonitor[i] == fullstring[i + j]; ++i);
			if (i >= nSubStr) {return true;}
		}
	}
	return false;
}

//Check if incoming gpuName matches with any of the grayGPUs entries
bool isGrayscaleGPU(char* gpuName) {
	string strGpuName(gpuName);
	for (int i=0;i<grayGPUs.size();i++)
		if(strGpuName.find(grayGPUs[i]) != string::npos)
			return true;
	return false;

}

//Error checking function to be called after NVAPI calls
bool nvapiCheckError(NvAPI_Status flag) {
	if (flag != NVAPI_OK)
	{
		NvAPI_ShortString string;
		NvAPI_GetErrorMessage(flag, string);
		printf("nvapiCheckError : %s\n", string);
		return false;
	}
	return true;
}

//Iterates over all attached displays to check if they are grayscale compatible (have a gray GPU & monitor)
//and fills the flags in DisplayWinList accordingly
void checkGrayscaleCompat() {
	//populate list of compatible GPU's and monitord
	//NDS Dome planar display
	grayMonitors.push_back("Dome E2"); //2MP
	grayMonitors.push_back("Dome E3"); //3MP
	grayMonitors.push_back("Dome E5"); //5MP
	grayMonitors.push_back("Dome Z10"); //Z10
	//Eizo Radiforce display
	grayMonitors.push_back("GS520"); //5MP
	//NEC Displays
	grayMonitors.push_back("MD205MG-1"); //5MP 
	grayMonitors.push_back("MD213MG"); //3MP 
	grayMonitors.push_back("MD21GS-3MP"); //3MP 
	grayMonitors.push_back("MD21GS-2MP"); //2MP 
	//Canvys/Wide display
	grayMonitors.push_back("IF2105PM"); //3MP 


	grayGPUs.push_back("1800");
	grayGPUs.push_back("3700");
	grayGPUs.push_back("3800");
	grayGPUs.push_back("4600");
	grayGPUs.push_back("4800");
	grayGPUs.push_back("5600");
	grayGPUs.push_back("5800");

	NvAPI_Status nvapiStatus;
	// Initialize NVAPI.
	nvapiStatus = NvAPI_Initialize();
	if (nvapiCheckError(nvapiStatus) == false) //error 
		return ;

	NvDisplayHandle hDisplay[NVAPI_MAX_DISPLAYS] = {0};
	NvU32 nvDisplayCount = 0;

	// Enumerate all display handles
	for(unsigned int i=0,nvapiStatus=NVAPI_OK; nvapiStatus == NVAPI_OK; i++)
	{
		nvapiStatus = NvAPI_EnumNvidiaDisplayHandle(i, &hDisplay[i]);
		if (nvapiStatus == NVAPI_OK) nvDisplayCount++;
	}

	//Loop through each display to check if its grayscale compatible
	for(unsigned int i=0; i<nvDisplayCount; i++)
	{
		//Get the GPU that drives this display
		NvPhysicalGpuHandle hGPU[NVAPI_MAX_PHYSICAL_GPUS] = {0}; //handle to gpu's
		NvU32 gpuCount = 0;
		nvapiStatus = NvAPI_GetPhysicalGPUsFromDisplay(hDisplay[i],hGPU,&gpuCount);
		nvapiCheckError(nvapiStatus);

		//Get the GPU's name as a string
		NvAPI_ShortString gpuName;
		NvAPI_GPU_GetFullName (hGPU[0], gpuName);
		nvapiCheckError(nvapiStatus);

		//Get the Display's name as a string
		NvAPI_ShortString displayName;
		NvAPI_GetAssociatedNvidiaDisplayName(hDisplay[i], displayName);
		nvapiCheckError(nvapiStatus);
		//assert that the gpuname is the same as what we got from wingdi
		if (strcmp(displayWinList[i].displayName,displayName) != 0)
			printf("Error: Display list has changed\n");

		//Get the display ID for this display handle
		NvU32 id;
		nvapiStatus = NvAPI_GetAssociatedDisplayOutputId(hDisplay[i],&id);
		nvapiCheckError(nvapiStatus);

		//Get the EDID for this display
		NV_EDID curDisplayEdid = {0};
		curDisplayEdid.version = NV_EDID_VER;
		nvapiStatus = NvAPI_GPU_GetEDID(hGPU[0],id,&curDisplayEdid);
		nvapiCheckError(nvapiStatus);

		//if GPU & monitor both support grayscale, set the grayFlags table
		if (isGrayscaleGPU(gpuName)&&isGrayscaleMonitor(curDisplayEdid.EDID_Data,NV_EDID_DATA_SIZE))
			displayWinList[i].grayscale = true;
		else 
			displayWinList[i].grayscale = false;
	}
}


int main(int argc, char* argv)
{
	//enumerate all displays and fill the displayWinList
	enumDisplaysGDI();
	//iterate over all displays to check which is grayscale compatible and set flag
	checkGrayscaleCompat();
	//Now create windows on all the displays and just draw a dummy teapot
	//The event handler checks for when user moves or resizes windows and it spans across gray/non-gray display
	//Its up to the app to handle however it wants - doing nothing is fine, but some apps like to restrict images to gray display
	for (int i=0;i<displayCount;i++) {
		displayWinList[i].createWin(100,100,500,500);
		displayWinList[i].print();
	}

	// Process application messages until the application closes
	MSG  msg;
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}




