#include "Graphic.h"

Graphic::Graphic()
{
}

Graphic::~Graphic()
{
}

void Graphic::showGraph()
{
	// 色の設定
	Scalar red(0, 0, 255), green(0, 255, 0), blue(255, 0, 0); // 赤、緑、青
	Scalar gray = Scalar(128, 128, 128); // グレー
	Scalar dgray = gray / 4;
	Scalar white = Scalar::all(255);
	Mat img(Size(640, 480), CV_8UC3, white); // 描画領域

	// 直線と矢印
	line(img, Point(50, 50), Point(150, 150), blue, 8, LINE_AA);
	arrowedLine(img, Point(50, 250), Point(150, 200), red, 8, LINE_4, 0, 0.3);

	// 破線の格子目盛り
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

	rectangle(img, Point(200, 100), Point(300, 250), dgray, FILLED); // 長方形描画
	Rect waku(250, 50, 75, 100);
	rectangle(img, waku, green, 16);

	// 多角形 (内部塗りつぶし)
	vector<Point> points{ 
		Point(400, 100), 
		Point(475, 150),
		Point(400, 250), 
		Point(350, 200),
		Point(350, 150)};

	fillConvexPoly(img, points, Scalar(200, 0, 0));

	// 多角形 (内部塗りつぶし無し)
	vector<Point> poly{
		Point(130, 280),
		Point(550, 200),
		Point(420, 450)
	};
	polylines(img, poly, true, Scalar(0, 200, 255), 2);

	// 円と楕円
	circle(img, Point(550, 200), 50, red, 5);
	ellipse(img, Point(550, 100), Size(60, 30), 30, 90, 360, green, FILLED);


	Rect val_rect = Rect(Point(img.cols * 0.1, img.rows * 0.1), Point(img.cols * 0.2, img.rows * 0.15));
	rectangle(img, val_rect, Scalar::all(255), FILLED);
	rectangle(img, val_rect, Scalar(0,0,0), 1, LINE_4);

	// 文字
	putText(img, "Hello, world", Point(val_rect.x, val_rect.y + val_rect.height*0.8), FONT_HERSHEY_COMPLEX_SMALL, 1, blue, 1);

	imshow("Graphic", img);
	cvWaitKey(0);
	
}
