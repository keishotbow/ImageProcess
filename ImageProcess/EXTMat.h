#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class EXTMat
{
private:
	void printMatProperty(const string, Mat& m);

public:
	EXTMat();
	~EXTMat();

	void createEXTMat();
};

