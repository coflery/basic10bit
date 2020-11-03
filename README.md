### Windows OpenGL test program to check 10 bit support ###
### 用于测试10位支持的Windows OpenGL测试程序 ###  

Creates a window that shown a black to white gradient. The lower
half is forced to 8 bit precision, while no such limitation is
set on the top half.  
创建一个显示黑色到白色渐变的窗口。 下半部分被强制为8位精度，而上半部分没有
这个限制。

The opengl context will be initialized to 10 bit color, so if both
the monitor and graphics card support it, banding will be seen in the
bottom half of the window and a smooth gradient will be seen in the
top half.  
opengl上下文将被初始化为10位色彩范围（0-1023）。因此，如果显示器和显卡都
支持该模式，在窗口的下半部分将看到带状色阶，在上半部分将看到平滑的渐变。

Note that you must make sure that no dithering is enabled.
请注意，您必须确保没有启用抖动（Dither）功能。  
