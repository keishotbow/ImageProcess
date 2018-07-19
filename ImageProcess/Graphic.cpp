#include "Graphic.h"

Graphic::Graphic()
{
}

Graphic::~Graphic()
{
}

void Graphic::showGraph()
{
	// F‚Ìİ’è
	Scalar red(0, 0, 255), green(0, 255, 0), blue(255, 0, 0); // ÔA—ÎAÂ
	Scalar gray = Scalar(128, 128, 128); // ƒOƒŒ[
	Scalar dgray = gray / 4;
	Scalar white = Scalar::all(255);
	Mat img(Size(640, 480), CV_8UC3, white); // •`‰æ—Ìˆæ

	// ’¼ü‚Æ–îˆó
	line(img, Point(50, 50), Point(150, 150), blue, 8, LINE_AA);
	arrowedLine(img, Point(50, 250), Point(150, 200), red, 8, LINE_4, 0, 0.3);

	// ”jü‚ÌŠiq–Ú·‚è
	for (int lx = 50; lx < 640; lx += 50) {
		for (int ly = 0; ly < 480; ly += 15) {
			line(img, Point(lx, ly), Point(lx, ly + 10), gray);
		}
	}

	for (int ly = 50; ly < 480; ly += 50) {
		for (int lx = 0; lx < 640; lx += 15) {
			line(img, Point(lx, ly), Point(lx + 10, ly), gray);
		}
	}

	rectangle(img, Point(200, 100), Point(300, 250), dgray, FILLED); // ’·•ûŒ`•`‰æ
	Rect waku(250, 50, 75, 100);
	rectangle(img, waku, green, 16);

	// ‘½ŠpŒ` (“à•”“h‚è‚Â‚Ô‚µ)
	vector<Point> points{ 
		Point(400, 100), 
		Point(475, 150),
		Point(400, 250), 
		Point(350, 200),
		Point(350, 150)};

	fillConvexPoly(img, points, Scalar(200, 0, 0));

	// ‘½ŠpŒ` (“à•”“h‚è‚Â‚Ô‚µ–³‚µ)
	vector<Point> poly{
		Point(130, 280),
		Point(550, 200),
		Point(420, 450)
	};
	polylines(img, poly, true, Scalar(0, 200, 255), 2);

	// ‰~‚Æ‘È‰~
	circle(img, Point(550, 200), 50, red, 5);
	ellipse(img, Point(550, 100), Size(60, 30), 30, 90, 360, green, FILLED);


	Rect val_rect = Rect(Point(img.cols * 0.1, img.rows * 0.1), Point(img.cols * 0.2, img.rows * 0.15));
	rectangle(img, val_rect, Scalar::all(255), FILLED);
	rectangle(img, val_rect, Scalar(0,0,0), 1, LINE_4);

	// •¶š
	putText(img, "Hello, world", Point(val_rect.x, val_rect.y + val_rect.height*0.8), FONT_HERSHEY_COMPLEX_SMALL, 1, blue, 1);

	imshow("Graphic", img);
	cvWaitKey(0);
	
}
