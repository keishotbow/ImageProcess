#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>
#include "Video.h"

using namespace std;
using namespace cv;

class Graphic
{
private:
	Video m_video;
public:
	Graphic();
	~Graphic();

	void showGraph();
};

