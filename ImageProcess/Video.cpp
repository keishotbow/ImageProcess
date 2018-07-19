#include "Video.h"


Video::Video()
{
}

Video::~Video()
{
}

void Video::pause() {
	std::cout << "Press any key to finish this process.\n";
	std::cin.get();
}

void Video::showVideo()
{
	m_cap.open(0); // カメラオープン
	
	if (!m_cap.isOpened()) {
		cout << "Could not open the video file.\n";
		cin.get();
		return;
	}

	// ビデオ出力書き込み用
	//Size sizeRec(800, 600);
	Size sizeRec((int)m_cap.get(CAP_PROP_FRAME_WIDTH), (int)m_cap.get(CAP_PROP_FRAME_HEIGHT));
	VideoWriter rec("video_dst.avi"
		, VideoWriter::fourcc('X', 'V', 'I', 'D'), 30, sizeRec);
	
	Mat frame; // フレーム
	Mat gray, dst;
	Mat flip_dst; // 反転映像
	Mat moving; // 移動平均処理適用フレーム
	Mat gaussian; // ガウシアン処理適用フレーム
	Mat tmp;

	namedWindow("FlippedFrame", WINDOW_AUTOSIZE);
	//resizeWindow("FlippedFrame", Size(800, 600));

	while (true) {
		m_cap >> frame;
		if (frame.empty()) break; // フレームが空ならループ抜ける
		
		cvtColor(frame, gray, COLOR_BGR2GRAY);
		threshold(gray, gray, 128, 255, THRESH_BINARY);
		cvtColor(gray, dst, COLOR_GRAY2BGR);

		flip(frame, flip_dst, 1); // 反転

		//GaussianBlur(frame, tmp, Size(15, 15), 5.0, 5.0); // ガウシアンフィルタ
		//resize(tmp, gaussian, sizeRec);

		//blur(frame, tmp, Size(100, 5)); // 平滑化
		//resize(tmp, moving, sizeRec);

		imshow("frame", frame); // フレーム表示
		//imshow("dst", dst); // 二値化処理フレーム表示
		//imshow("FlippedFrame", flip_dst); // 反転映像
		//imshow("Gaussian", gaussian); // ガウシアン平滑化処理適用後
		//imshow("Moving", moving); // 移動平均平滑化処理適用後

		rec << dst; // 出力フレーム書き込み

		if (cvWaitKey(33) >= 0) break; // キーボード入力で抜ける

	}
}
