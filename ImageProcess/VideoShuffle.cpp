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

	// �r�f�I�����̎擾
	int frameWidth = (int)cap.get(CAP_PROP_FRAME_WIDTH); // �f���̕�
	int frameHeight = (int)cap.get(CAP_PROP_FRAME_HEIGHT); // �f���̍���
	int frameCount = (int)cap.get(CAP_PROP_FRAME_COUNT); // ���t���[����
	int fps = (int)cap.get(CAP_PROP_FPS); // �t���[�����[�g
	int wait = 1000 / fps; // �҂�����

	int fourcc = cap.get(CAP_PROP_FOURCC); // �r�f�I�`��
	int format = cap.get(CAP_PROP_FORMAT); // Mat�I�u�W�F�N�g

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
	cout << "�r�f�I���F" << frameCount << " (" << frameCount / fps << "s)" << endl;
	cout << "�r�f�I�`���F" << (int)fourcc << ", �^�F" << format << endl;

	bool loop = true;
	while (loop) {
		int pos = rand() % frameCount;
		int window = rand() % 30 + 10;
		int direction = 2 * (rand() % 2) - 1;
		cout << "�J�n�F" << pos << ", �R�}���F" << window << ", �����F" << direction << endl;

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
