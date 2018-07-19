#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class Trackbar
{
public:
	Trackbar();
	~Trackbar();

	int start();
	static void changeBrightness(int position, void * userdata);

};

