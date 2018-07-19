#include <iostream>
#include <opencv2/opencv.hpp>
#include "EdgeDetect.h"
#include "EXTMat.h"
#include "Video.h"
#include "VideoShuffle.h"
#include "Graphic.h"
#include "Trackbar.h"

using namespace std;
using namespace cv;

int main(void) {

	Mat lenna = imread("lenna.png");

	//EdgeDetect ed;
	//ed.detectEdge(lenna, 50, 150);

	//EXTMat extmat;
	//extmat.createEXTMat();

	/*VideoCapture cap("video_dst.avi");
	Video v(cap);
	v.showVideo();
	
	VideoShuffle shuffle;
	shuffle.shuffle(cap);*/

	//Graphic graph;
	//graph.showGraph();

	Trackbar tb;
	tb.start();

	return 0;
}