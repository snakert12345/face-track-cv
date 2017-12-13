#include <iostream>
#include <opencv2/opencv.hpp>
#include "gpio.h"

using namespace cv;

VideoCapture getCapture(int camNum)
{
	VideoCapture vcap;
	
	while(!vcap.open(camNum));

	return vcap;
}

int main(int argc, char* args[])
{
	namedWindow("win", CV_WINDOW_AUTOSIZE);
	VideoCapture vcap = getCapture(0);
	Mat img;
	while(vcap.read(img))
	{
		resize(img, img, Size(800, 600));
		rotate(img, img, 1.0f);

		imshow("win", img);
		
		// If escape is pressed we break;
		if (waitKey(10) == 27)
			break;			
	}	

	return 0;
}
