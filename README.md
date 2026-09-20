# C++ OpenCV Webcam Filters

A small C++ and OpenCV project built to practice C++ fundamentals through real-time webcam filtering and basic image processing.

## About the Project

I created this project while learning C++ to reinforce the concepts I have studied and gain experience working with an external library.

The application captures video from the webcam and allows different image processing filters to be applied in real time using OpenCV.

## Features

The following filters can be selected using the keyboard:

* `0` - Original image
* `1` - Grayscale
* `2` - Bilateral Filter
* `3` - Binary Threshold
* `4` - Canny Edge Detection
* `5` - Sobel Edge Detection
* `Q` - Quit the application

## What I Practiced

While building this project, I practiced:

* C++ functions
* Header and source file separation
* Structs
* References and const references
* Switch statements
* Loops
* Basic error handling
* Code organization
* Working with an external C++ library
* Basic image processing concepts with OpenCV

## Technologies

* C++
* OpenCV
* Visual Studio
* vcpkg

## Project Structure

```text
cpp-opencv-webcam-filters/
├── App.cpp
├── App.h
├── Filters.cpp
├── Filters.h
├── main.cpp
├── vcpkg.json
└── webcamFilters.vcxproj
```

## Requirements

* C++ compiler
* OpenCV
* vcpkg
* A webcam

The project uses `vcpkg.json` to declare OpenCV as a dependency.

## Running the Project

1. Clone the repository.
2. Install the required dependencies using vcpkg.
3. Open the project in Visual Studio.
4. Build and run the application.
5. Use the number keys `0-5` to switch between filters.

## Purpose

This is a learning project created while studying C++. The main goal was to practice C++ fundamentals by building a small real-time application instead of only working on isolated exercises.
