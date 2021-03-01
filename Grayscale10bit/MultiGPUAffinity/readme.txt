README for MultiGPUAffinity
- To run, just type
MultiGPUAffinity
This will open a window per display that is driven by the display's GPU.
So if the window is moved to a display driven by another GPU, no drawing happens.

If it is required for many physical GPU's -> 1 affinity GPU, 
just change the code in MultiGPUAffinity.GPP where the gpuMask is populated



