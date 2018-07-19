#include "EdgeDetect.h"

EdgeDetect::EdgeDetect()
{
}

EdgeDetect::~EdgeDetect()
{
}

Mat EdgeDetect::detectEdge(const Mat & src, const double & th1, const double & th2)
{
	Mat dst;

	try
	{
		if (src.empty()) throw exception("detectEdge(): src is empty.");
		
		int apertueSize = 3;
		Canny(src, dst, th1, th2, apertueSize, false); // Cannyエッジ検出

		if (dst.empty()) throw exception("detectEdge(): dst is empty.");
		
		imshow("src image", src);
		imshow("result", dst);

		imwrite("EdgedImage.png", dst); // エッジ検出画像書き込み
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
		cin.get();
	}

	// ピュアに鉛筆風なGrayScaleとカラー画像を出力する
	Mat pencil_sketch_dst1;
	Mat pencil_skecth_dst2;
	try
	{
		pencilSketch(src, pencil_sketch_dst1, pencil_skecth_dst2);
		if (pencil_sketch_dst1.empty() || pencil_skecth_dst2.empty()) {
			throw exception("pencil_sketch_dst is empty.");
		}

		imshow("pencilSkecth1", pencil_sketch_dst1);
		imshow("pencilSkecth2", pencil_skecth_dst2);
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
		cin.get();
	}

	return dst;
}

