/*
	C++ Program to convert at image to its OpenCV format .
	The user is required to pass the following instructions to run the program :

	g++ -ggdb `pkg-config --cflags --libs opencv` gray2.cpp -o gray2 -fopenmp -std=c++14
	./gray2 <filenames>

*/

#include <opencv2/opencv.hpp>
#include <iostream>
#include <memory>
#include <string>
#include <cmath>

using namespace cv;

// Defining the unique smart pointer function
template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

// Defining the Image class
class gray
{
	cv::Mat img;
	cv::Mat grayMat;
	String filename;

	public:
		gray(String str){ filename = str; }
		~gray(){};
		void convert2gray(String loc);
		void displayimg();
};

// Member function to convert the image to grayscale
void gray::convert2gray(String filename)
{
	img = cv::imread(filename);
	cvtColor(img,grayMat,cv::COLOR_BGR2GRAY); // Computing the gray image

}

// Member function to display the resulting image
void gray::displayimg()
{
	// Names of the windows
	cv::String window_original = "original";
	cv::String windwindow_gray = "gray";

	// Display the original image
	cv::namedWindow(window_original, cv::WINDOW_AUTOSIZE);
	cv::imshow(window_original,img);

	// Display the grayscale image
	cv::namedWindow(windwindow_gray, cv::WINDOW_AUTOSIZE);
	cv::mshow(windwindow_gray,grayMat);

	// Wait till user presses a key
	waitKey(0);

}

// Main function
int main(int argc, char** argv)
{

	// Check if required number of arguments are passed
	if ( argc < 2 )
    	{
        	printf("usage: DisplayImage.out <Image_Path>\n");
        	return -1;
    	}
	
	// Multithreading for multiple image files

	#pragma omp parallel for
	for(int i = 1; i<=argc; i++)
	{
		// Defining the smart pointer ( unique pointer in this case) to the class
		std::unique_ptr<gray> cnv = make_unique<gray>("tanush.jpg");

		Mat image;
    		image = imread( argv[i]);

		// Running the required functions
		// Convert the image to its grayscale with the argument passed at the location
		cnv->convert2gray(argv[i]);

		// Display the result
		cnv->displayimg();
        }

	return 0;
}
