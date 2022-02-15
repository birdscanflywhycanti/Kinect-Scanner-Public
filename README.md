# X-Box Kinect 3D Room scanner written in C++ with OpenGL

# Link to video:
https://youtu.be/sHo4lMAl32g 

## Kinect room scanner
Gif of product running: https://lasagna.cat/i/da55iuxo.gif
## Libraries used:
- Kinect SDK 1.8
- FreeGlut
- Glew
- GLM

## How to use:
Connect XBox 360 Kinect to device and run the program. A window will pop up that shows what the kinect sees. The program will attempt to use the depth data from the sensor along with the camera to plot all the points in 3d using OpenGL, thus creating a 3d model of what the camera sees. The program demonstartes this by rotating the camera (of the scene) around the plot. You are able to physically move the sensor and it will update in realtime.


## How does the program code work?
The program first starts by initializing the Kinect and creating two image streams. One to retrieve the depth data and another to retrieve the colour data. The software then loads the depth data and the colour data from the image streams and stores them into two buffer objects. Because the colour and depth sensors are physically separate sensors, the function `NuiImageGetColorPixelCoordinatesFromDepthPixelAtResolution` is used to align the position of each depth pixel with the correct corrisonding colour pixel. This Data is then drawn to the screen and updated in the `glutMainLoop`. The camera oscilates rotating an arc of 90 degrees around the model. This allows you to more clearly see the depth.


## How do the functions fit together
The program start off in the `main()` function. It first calls `KinectSetup()` This initialises the XBox 360 Kinect that is connected to the device and sets up sensor streams.
The `main()` function then calls `init()` which creates the output window and sets up the glut main loop. The `draw()` function is passed into both the `glutDisplayFunc()` and the `glutIdleFunc()`. This tells the program loop and call `draw()` to update the window output. 
The `draw()` function calls `drawKinectData()` and moves the back buffer forwards. 

The `drawKinectData()` function acts as the primary function that holds this software together. First it calls `getKinectData()` which updates the buffer data. Then, `rotateCamera()` is called which shifts the viewing position slightly. Finally it loads and draws the buffer data using `glDrawArrays()`. 

The function `getKinectData()` allocates some GPU memory and loads in data via the `getData()` function. This function is used to load in both the rbg data and the depth data.
`getData()` accesses the colour and depth data streams. The function branches depending on what type of data it is reading, `loadDepth()` if its depth, and `loadrgb()` if its colour data. These functions loops through every pixel in the current frame and stores the data into the correspnding buffer.


## What makes your program special and how does it compare to similar things?
Originally I had intended to use Kinect Fusion (https://www.microsoft.com/en-us/research/wp-content/uploads/2016/02/ismar2011.pdf) to model things the kinect sees in 3D. However, I later found that Kinect Fusion will **only** would with DirectX and not OpenGL. 
I came up with the idea for this project after exploring the Kinect Developer Toolkit Browser and seeing some of the showcase examples. All of the examples made use of DirectX rather than OpenGL. As such, I decided that I would pick a graphics example and recreate it from scratch using OpenGL. As the Kinect Fusion idea was not feasible, I decided to make use of a different approach to the project that would still fulfill my project pitch: To use individual point depth and colour data to plot what the kinect sees in 3D using OpenGL. 
I did not start with a given project, however I did make heavy use of the gettng started section of the Microsoft Kinect SDK1.8 documentation https://docs.microsoft.com/en-us/previous-versions/windows/kinect-1.8/hh855352(v=ieb.10) and used https://homes.cs.washington.edu/~edzhang/tutorials/kinect/kinect1.html for support with the OpenGL functionality. 
# Solution to be opened
There is only one solution file inside `/2020-comp3016-cw2-luckychan12-main` called `“Coursework2.sln”`

# How to run compiled exe:
(Ensure kinect 1.8 SDK is installed)
Program executable is ready to run after connecting a single Xbox 360 Kinect sensor.

# How to setup project for compiling in visual studio:
Ensure the Kinect SDK 1.8 is installed on the machine.
Set the include and library path of the project to the Kinect SDK files
![Screenshot of project properties](https://i.imgur.com/xWZ4Mlc.png)
Set the linker library location. 
Use *C:\Program Files\Microsoft SDKs\Kinect\v1.8\lib\amd64* for 64 bit machines and *...\lib\x86* for 32 bit machines
![Screenshot of linker properties](https://i.imgur.com/lKFWzIg.png)
Add *kinect10.lib* to linker dependencies 
![Screenshot of linker properties](https://i.imgur.com/SctoD8u.png)


