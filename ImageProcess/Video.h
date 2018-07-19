#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class Video
{
	VideoCapture m_cap;
public:
	Video(VideoCapture & capture) { m_cap = capture; };
	Video();
	~Video();
	void pause();
	void showVideo();
};

