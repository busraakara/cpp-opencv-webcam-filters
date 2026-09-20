#pragma once
#include <opencv2/opencv.hpp>

cv::Mat convertToGrayscale(cv::Mat& frame);
cv::Mat applyBilateralFilter(cv::Mat& frame);
cv::Mat applyBinaryThreshold(cv::Mat& frame);
cv::Mat applyCannyFilter(cv::Mat& frame);
cv::Mat applySobelFilter(cv::Mat& frame);

cv::Mat applySelectedFilter(int filterChoice, cv::Mat& frame); 
