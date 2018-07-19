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
	m_cap.open(0); // �J�����I�[�v��
	
	if (!m_cap.isOpened()) {
		cout << "Could not open the video file.\n";
		cin.get();
		return;
	}

	// �r�f�I�o�͏������ݗp
	//Size sizeRec(800, 600);
	Size sizeRec((int)m_cap.get(CAP_PROP_FRAME_WIDTH), (int)m_cap.get(CAP_PROP_FRAME_HEIGHT));
	VideoWriter rec("video_dst.avi"
		, VideoWriter::fourcc('X', 'V', 'I', 'D'), 30, sizeRec);
	
	Mat frame; // �t���[��
	Mat gray, dst;
	Mat flip_dst; // ���]�f��
	Mat moving; // �ړ����Ϗ����K�p�t���[��
	Mat gaussian; // �K�E�V�A�������K�p�t���[��
	Mat tmp;

	namedWindow("FlippedFrame", WINDOW_AUTOSIZE);
	//resizeWindow("FlippedFrame", Size(800, 600));

	while (true) {
		m_cap >> frame;
		if (frame.empty()) break; // �t���[������Ȃ烋�[�v������
		
		cvtColor(frame, gray, COLOR_BGR2GRAY);
		threshold(gray, gray, 128, 255, THRESH_BINARY);
		cvtColor(gray, dst, COLOR_GRAY2BGR);

		flip(frame, flip_dst, 1); // ���]

		//GaussianBlur(frame, tmp, Size(15, 15), 5.0, 5.0); // �K�E�V�A���t�B���^
		//resize(tmp, gaussian, sizeRec);

		//blur(frame, tmp, Size(100, 5)); // ������
		//resize(tmp, moving, sizeRec);

		imshow("frame", frame); // �t���[���\��
		//imshow("dst", dst); // ��l�������t���[���\��
		//imshow("FlippedFrame", flip_dst); // ���]�f��
		//imshow("Gaussian", gaussian); // �K�E�V�A�������������K�p��
		//imshow("Moving", moving); // �ړ����ϕ����������K�p��

		rec << dst; // �o�̓t���[����������

		if (cvWaitKey(33) >= 0) break; // �L�[�{�[�h���͂Ŕ�����

	}
}
