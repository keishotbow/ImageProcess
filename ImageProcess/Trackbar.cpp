#include "Trackbar.h"

double brightness = 0.0;


Trackbar::Trackbar()
{
}


Trackbar::~Trackbar()
{
}

int Trackbar::start()
{
	int val = 128; // トラックバー初期位置
	Mat src, gray, dst;

	bool mode = true;
	cout << "Type Y or N to continue the process or not." << endl;
	
	while (true) {
		auto start = cin.get();

		switch (start) {
		case 'y':
			cout << "you pressed y" << endl;
			break;
		case 'n':
			cout << "you pressed n" << endl;
			continue;
		default:
			continue;
		}

		break;
	}

	VideoCapture cap(0);
	namedWindow("Input");
	namedWindow("Binalization");

	// トラックバー生成
	createTrackbar("Threshold", "Binalization", &val, 255);
	createTrackbar("Brightness", "Input", NULL, 200, changeBrightness);
	setTrackbarPos("Brightness", "Input", 100);	

	while (1) {
		cap >> src;
		if (src.empty()) return -1;
		src *= brightness;
		cvtColor(src, gray, COLOR_BGR2GRAY);

		if (mode) {
			threshold(gray, dst, 128, 255, THRESH_BINARY);
		}
		else {
			threshold(gray, dst, NULL, 255, THRESH_BINARY | THRESH_OTSU);
		}

		imshow("Input", src);
		imshow("Binalization", dst);

		auto key = cvWaitKey(30);
		if (key == 27) {
			break;
		}
		else if (key == 'o') {
			if (mode == false) {
				cout << "Threshold is fixed\n";
				mode = true;
			}
			else {
				cout << "Threshold is changed automatically\n";
				mode = false;
			}
		}
	}

	return 0;
}

void Trackbar::changeBrightness(int position, void * userdata)
{
	brightness = (double)position / 100.0;
	cout << "明るさ倍率 = " << brightness << endl;
}
