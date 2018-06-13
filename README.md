# SampleCMakeRobot
A sample FRC C++ robot project with CMake. The files found in the ```.vscode``` folder help VSCode figure out how to use CMake and where to find the headers (so all your ```#include``` are resolved). You'll also need some Extensions for things to run smoothly, please look below.

This project also uses Google Test, test file can be found in ```test``` directory. CMake is set up to download and build google test automatically.

## Requirements
You'll need CMake installed and on your PATH, as well as the FIRST FRC Toolchain, and the WPILib library installed in your home directory. The Eclipse plugin will handle downloading WPILib and putting it in the right place once you install it, so that is the current recommended way. If you already have been using Eclipse with the FRC plugin then everything should be set up correctly.

This project has been tested on Windows, but it should work on Linux/MacOS as well.

## VSCode
Visual Studio code support works quite well, all that is needed are the following plugins below. Please note that you need to select at the bottom the ```GCC ARM Cross Compile``` kit and also press the ```build``` button, restart VSCode in order for it to find the necessary information so Intellisense will work.

You'll need two extensions for everything to work correctly, those are:

- [C/C++ Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
- [CMake Tools](https://marketplace.visualstudio.com/items?itemName=vector-of-bool.cmake-tools)

I would also suggest you install the following:
- [This CMake plugin, for syntax highlighting](https://marketplace.visualstudio.com/items?itemName=twxs.cmake)
- [Native Debug](https://marketplace.visualstudio.com/items?itemName=webfreak.debug) for debugging C/C++ code.
