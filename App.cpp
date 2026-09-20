#include "App.h"
#include "Filters.h"


void printControls() { 

	std::cout << "Keyboard controls:" << std::endl;
	std::cout << "q: Quit" << std::endl;
	std::cout << "0: Original image" << std::endl;
	std::cout << "1: Grayscale" << std::endl;
	std::cout << "2: Bilateral filter" << std::endl;
	std::cout << "3: Binary threshold" << std::endl;
	std::cout << "4: Canny edge detection" << std::endl;
	std::cout << "5: Sobel edge detection" << std::endl;
}

bool openCamera(cv::VideoCapture& cap) {

	cap.open(0);

	if (!cap.isOpened()) { 

		std::cout << "error: camera could not be opened" << std::endl;
		return false;

	}

	return true;
}

cv::Mat captureFrame(cv::VideoCapture& cap) {

	cv::Mat frame;

	cap >> frame;

	return frame;
}

void showFrame(const cv::Mat& frame) {

	cv::imshow("Webcam", frame);
} 

KeyboardResult handleKeyboardInput(int currentSelectedFilter) {
	KeyboardResult result; 
	result.keepRunning = true; 
	result.selectedFilter = currentSelectedFilter; 

	/*char keyboardInput = static_cast<char>(cv::pollKey());*/
	const int keyboardInput = cv::pollKey();
	switch (keyboardInput) {

	case 'q':
	case 'Q':
		result.keepRunning = false;
		break;
	
	case '0':
		result.selectedFilter = 0;
		break;
	
	case '1':
		result.selectedFilter = 1;
		break;
	
	case '2':
		result.selectedFilter = 2;
		break;
	
	case '3':
		result.selectedFilter = 3;
		break;
	
	case '4':
		result.selectedFilter = 4;
		break;
	
	case '5':
		result.selectedFilter = 5;
		break;
	
	default:
		break;
	}
	return result;
}
void runApplication() { 

	printControls(); 

	int selectedFilter = 0; 

	cv::VideoCapture cap; 

	if (!openCamera(cap)) { 

		std::cout << "Error: Camera could not be opened." << std::endl;
		return; 
	}

	cv::Mat frame; 

	bool keepRunning = true; 
	while (keepRunning) {

		frame = captureFrame(cap); 

		if (frame.empty()) { 
			break;
		} 
		
		frame = applySelectedFilter(selectedFilter, frame); 

		showFrame(frame);
		
		KeyboardResult result = handleKeyboardInput(selectedFilter); 
		keepRunning = result.keepRunning; 
		selectedFilter = result.selectedFilter;
	}
	cap.release();
	cv::destroyAllWindows();
}