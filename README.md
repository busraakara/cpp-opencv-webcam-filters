# C++ OpenCV Webcam Filters

A small C++ and OpenCV project built to practice C++ fundamentals through real-time webcam filtering and basic image processing.

## About the Project

I created this project while learning C++ to reinforce the concepts I have studied and gain experience working with an external library.

The application captures video from the webcam and allows different image processing filters to be applied in real time using OpenCV.

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

## Build With

* C++
* OpenCV
* Visual Studio
* vcpkg

## Requirements

* C++ compiler
* OpenCV
* vcpkg
* A webcam

OpenCV is managed through the project's `vcpkg.json` manifest.

## Build and Run

1. Clone the repository:

git clone https://github.com/busraakara/cpp-opencv-webcam-filters.git

2. Install the required dependencies using vcpkg:

vcpkg install

3. Build from Developer PowerShell for Visual Studio:

msbuild webcamFilters.vcxproj /p:Configuration=Release /p:Platform=x64

4. Run:

.\x64\Release\webcamFilters.exe

5. Use the number keys `0-5` to switch between filters.

## Purpose

This is a learning project created while studying C++. The main goal was to practice C++ fundamentals by building a small real-time application instead of only working on isolated exercises.