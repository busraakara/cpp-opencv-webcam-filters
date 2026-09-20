#pragma once
#include <opencv2/opencv.hpp>
#include <iostream>
#include <utility>

struct KeyboardResult 
{
    bool keepRunning; 
    int selectedFilter; 

}; 
KeyboardResult handleKeyboardInput(int currentSelectedFilter); 
void printControls(); 
bool openCamera(cv::VideoCapture& cap);
cv::Mat captureFrame(cv::VideoCapture& cap);
void showFrame(const cv::Mat& frame);
void runApplication();
