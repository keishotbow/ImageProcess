#include "VideoShuffle.h"



VideoShuffle::VideoShuffle()
{
}


VideoShuffle::~VideoShuffle()
{
}

void VideoShuffle::shuffle(VideoCapture & cap)
{
	Mat src;

	// ビデオ属性の取得
	int frameWidth = (int)cap.get(CAP_PROP_FRAME_WIDTH); // 映像の幅
	int frameHeight = (int)cap.get(CAP_PROP_FRAME_HEIGHT); // 映像の高さ
	int frameCount = (int)cap.get(CAP_PROP_FRAME_COUNT); // 総フレーム数
	int fps = (int)cap.get(CAP_PROP_FPS); // フレームレート
	int wait = 1000 / fps; // 待ち時間

	int fourcc = cap.get(CAP_PROP_FOURCC); // ビデオ形式
	int format = cap.get(CAP_PROP_FORMAT); // Matオブジェクト

	try
	{
		if (frameWidth <= 0) throw exception("frameWidth <= 0");
		if (frameHeight <= 0) throw exception("frameHeight <= 0");
		if (frameCount <= 0) throw exception("frameCount <= 0");
		if (fps <= 0) throw exception("fps <= 0");
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
		cin.get();
		abort();
	}

	cout << "(width, height) = (" << frameWidth << ", " << frameHeight << ")\n";
	cout << "fps = " << fps << ", wait = " << wait << "ms" << endl;
	cout << "ビデオ長：" << frameCount << " (" << frameCount / fps << "s)" << endl;
	cout << "ビデオ形式：" << (int)fourcc << ", 型：" << format << endl;

	bool loop = true;
	while (loop) {
		int pos = rand() % frameCount;
		int window = rand() % 30 + 10;
		int direction = 2 * (rand() % 2) - 1;
		cout << "開始：" << pos << ", コマ数：" << window << ", 方向：" << direction << endl;

		for (int f = 0; f < window; f++) {
			cap.set(CAP_PROP_POS_FRAMES, pos);
			cap >> src;
			imshow("Shuffle", src);
			pos += direction;
			pos = min(pos, frameCount - 1);
			pos = max(pos, 0);
			if (cvWaitKey(wait) >= 0) {
				loop = false;
				break;
			}
		}
	}

	destroyAllWindows();

	cout << "Press any key to finish this process.\n";
	cin.get();
}
