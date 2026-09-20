#include "Filters.h"

cv::Mat convertToGrayscale(cv::Mat& frame) {
	cv::Mat result;

	/*if (frame.channels() == 1) {
		return frame.clone();
	}*/

	cv::cvtColor(frame, result, cv::COLOR_BGR2GRAY);
	return result;
}

cv::Mat applyBilateralFilter(cv::Mat& frame) {
	cv::Mat result;
	
	cv::bilateralFilter(frame, result, 9, 75, 75);
	return result;
}

cv::Mat applyBinaryThreshold(cv::Mat& frame) {
	cv::Mat grayFrame, result;

	if (frame.channels() > 1) {
		cv::cvtColor(frame, grayFrame, cv::COLOR_BGR2GRAY);
	}
	else {
		grayFrame = frame;
	}

	cv::threshold(grayFrame, result, 127, 255, cv::THRESH_BINARY);
	return result; 
}

cv::Mat applyCannyFilter(cv::Mat& frame) {
	cv::Mat grayFrame, result;

	if (frame.channels() > 1) {
		cv::cvtColor(frame, grayFrame, cv::COLOR_BGR2GRAY);
	}
	else {
		grayFrame = frame;
	}

	cv::GaussianBlur(grayFrame, grayFrame, cv::Size(3, 3), 0);

	cv::Canny(grayFrame, result, 50, 150);
	return result;
}

cv::Mat applySobelFilter(cv::Mat& frame) {
	cv::Mat grayFrame, grad_x, grad_y, abs_grad_x, abs_grad_y, result;

	if (frame.channels() > 1) {
		cv::cvtColor(frame, grayFrame, cv::COLOR_BGR2GRAY);
	}
	else {
		grayFrame = frame;
	}

	cv::Sobel(grayFrame, grad_x, CV_16S, 1, 0, 3);
	cv::convertScaleAbs(grad_x, abs_grad_x);

	cv::Sobel(grayFrame, grad_y, CV_16S, 0, 1, 3);
	cv::convertScaleAbs(grad_y, abs_grad_y);

	cv::addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, result);
	return result;
}

cv::Mat applySelectedFilter(int filterChoice, cv::Mat& frame) { 
	switch (filterChoice) {

	case 0:
		return frame; 

	case 1:
		return convertToGrayscale(frame);

	case 2:
		return applyBilateralFilter(frame);

	case 3:
		return applyBinaryThreshold(frame);

	case 4:
		return applyCannyFilter(frame);

	case 5:
		return applySobelFilter(frame);

	default:
		std::cout << "Invalid key pressed. Press 'q' to quit or '0', '1', '2', '3', '4', '5' to select a filter." << std::endl;
		return frame;
	}
}

