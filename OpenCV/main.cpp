#include <string>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	string videoPath = "video.mp4";
	VideoCapture cap(videoPath);

	if(!cap.isOpened())
	{
		cerr << "Ошибка при загрузке видео" << endl;
		return -1;
	}

	int frameCount = cap.get(CAP_PROP_FRAME_COUNT);
	int frameWidth = cap.get(CAP_PROP_FRAME_WIDTH);
	int frameHeight = cap.get(CAP_PROP_FRAME_HEIGHT);
	int fps = cap.get(CAP_PROP_FPS);

	VideoWriter writer("output_video.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, Size(frameWidth, frameHeight));

	for(int i = 0; i < frameCount; ++i)
	{
		Mat frame;
		cap >> frame;

		if(frame.empty())
		{
			cerr << "Ошибка при чтении кадра" << endl;
			break;
		}

		string info = "Номер кадра: " + to_string(i) +
			" Разрешение: " + to_string(frameWidth) + "x" + to_string(frameHeight) +
			" Кодек: " + "MJPG";

		putText(frame, info, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 255, 255), 2);

		writer.write(frame);
	}

	cap.release();
	writer.release();

	return 0;
}
