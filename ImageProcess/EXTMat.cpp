#include "EXTMat.h"



EXTMat::EXTMat()
{
}


EXTMat::~EXTMat()
{
}

void EXTMat::printMatProperty(const string str, Mat & m)
{
	cout << "---- " << str << " ----" << endl;
	cout << "Size(attr): [" << m.cols << ", " << m.rows << "]" << endl;
	cout << "Dim(attr): " << m.dims << endl;
	cout << "Size(method): " << m.size() << endl; // 可読性の高い画像サイズを表示
	cout << "Total(method): " << m.total() << endl; // 総画素数を表示
	cout << "Channels(method): " << m.channels() << endl;
	cout << "Depth(method): " << m.depth() << endl;
	cout << "Type(method): " << m.type() << endl;
	imshow(str, m);
}

void EXTMat::createEXTMat()
{
	Mat img1(480, 640, CV_8UC1);
	printMatProperty("img1", img1);

	Size s2(640, 480);
	Mat img2(s2, CV_8UC1);
	printMatProperty("img2", img2);

	Scalar color(237, 149, 100);
	Mat img3(Size(400, 400), CV_8UC3, color);
	printMatProperty("img3", img3);

	Mat img4(s2 * 2, CV_8UC3, color);
	printMatProperty("img4", img4);

	Mat img5 = Mat::zeros(Size(320, 160), CV_8UC3);
	printMatProperty("img5", img5);

	Mat img6;
	img6.create(Size(300, 300), CV_32FC3);
	img6.setTo(Scalar(0.0, 1.0, 0.0));
	printMatProperty("img6", img6);

	Mat img7 = img3.clone();
	printMatProperty("img7", img7);

	Mat img8;
	img3.copyTo(img8);
	printMatProperty("img8", img8);
}
