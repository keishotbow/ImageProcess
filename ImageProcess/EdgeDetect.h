#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class EdgeDetect
{

public:
	EdgeDetect();
	~EdgeDetect();

	Mat detectEdge(const Mat & src, const double & th1, const double & th2);
};

