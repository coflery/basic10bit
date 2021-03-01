//
// Check30bit.cpp
//
// Main program that enumerates all attached displays and checks using NVAPI 
// which displays are 30bit color compatible
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

//Enumerates all atatched displays and fills the displayWinList array
//for use later in the window creation and 30-bit color compatibility query
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
			displayWinList[displayCount].print();
			displayCount++;
		}
		allDisplayCount++;
	} //while(enumdisplay);
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

//Iterates over all attached displays to check if they are 30-bit color compatible (have a 30-bit GPU & monitor)
//and fills the flags in DisplayWinList accordingly
void check30bitCompat() {

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

	//Loop through each display to check if its 30-bit color compatible
	for(unsigned int i=0; i<nvDisplayCount; i++)
	{
		//Get the GPU that drives this display
		NvPhysicalGpuHandle hGPU[NVAPI_MAX_PHYSICAL_GPUS] = {0}; //handle to gpu's
		NvU32 gpuCount = 0;
		nvapiStatus = NvAPI_GetPhysicalGPUsFromDisplay(hDisplay[i],hGPU,&gpuCount);
		nvapiCheckError(nvapiStatus);

		//We can safely assume that for most cases - 1 display can only be driven by 1 GPU, so gpuCount = 1;
		//and the gpu handle for this display is in hGPU[0]

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
		NvU32 curDisplayId;
		nvapiStatus = NvAPI_GetAssociatedDisplayOutputId(hDisplay[i],&curDisplayId);
		nvapiCheckError(nvapiStatus);

		//Get the display port info for this display
		NV_DISPLAY_PORT_INFO curDPInfo = {0};
		curDPInfo.version = NV_DISPLAY_PORT_INFO_VER;
		nvapiStatus = NvAPI_GetDisplayPortInfo(hDisplay[i], curDisplayId, &curDPInfo);
		nvapiCheckError(nvapiStatus);

		//if GPU & monitor both support 30-bit color AND they are connected by display port, set the color30bit flag
		if (curDPInfo.isDp &&(curDPInfo.bpc == NV_DP_BPC_10))
			displayWinList[i].color30bit = true;
		else 
			displayWinList[i].color30bit = false;
	}
}


int main(int argc, char* argv)
{

	//enumerate all displays and fill the displayWinList
	enumDisplaysGDI();
	//iterate over all displays to check which is 30-bit color compatible and set flag
	check30bitCompat();
	//init the WGL pixel format functions before creating any windows
	if (!CDisplayWin::initWGLExtensions()) {
		printf("Error getting 10bpc pixel format, reverting to 24-bit color...");
		//reset the color30bit flag, ie if a valid pfd was not obtained, they shouldnt have the flag
		for (int i=0; i< displayCount;i++) displayWinList[i].color30bit = false; 
	}
	//Now create windows on all the displays and just draw a dummy teapot
	//The event handler checks for when user moves or resizes windows and it spans across 30-bit color/non-30-bit color display
	//Its up to the app to handle however it wants - doing nothing is fine, but some apps like to restrict images to 30-bit color display
	for (int i=0;i<displayCount;i++) {
		//need both a valid 10bpc pixel format and 30bit display support to create a 30-bit color window
		if (displayWinList[i].color30bit)
			displayWinList[i].create30bitWin(100,100,500,500);
		else
			displayWinList[i].create24bitWin(100,100,500,500);

		displayWinList[i].print();
	}

	MSG msg;
	// Process application messages until the application closes
    while (BOOL bRet = GetMessage(&msg, NULL, 0, 0) != 0)
    {
        if (bRet == -1)
        {
            break;
        }
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
	return msg.wParam;

}




