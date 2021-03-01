README for 30bitdemo

Shows rendering various HDR texture formats
The OpenEXR lib from www.openexr.org is included in the project. Linking seems to generate a lot of warning but can be ignored.

INTERACTION
Space bar - to toggle between the different drawing modes
- A shaded quad with color interpolated from 0..1. Banding is prominent on 24-bit window when maximized
- 16 bit RGBA texture
- packed RGB10_A2 texture
- OpenEXR image loaded into half float texture

ESC - quit the app
Key F - toggles between off-screen rendering with dual viewports and on-screen