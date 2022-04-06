#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main () {
    Mat frame;
    Mat ycrcbFrame;
    vector<Mat> channels;
    VideoCapture cap;
    cap.open("/Users/chenxuan/Downloads/OpenCV_Proj/test_video.mov");
    if (!cap.isOpened()) {
        cout << "File open failed..." << endl;
        return -1;
    }
    namedWindow("Output_src", WINDOW_AUTOSIZE);
    namedWindow("Output_dst", WINDOW_AUTOSIZE);
    while (cap.read(frame)) {
        imshow("Output_src", frame);
        cvtColor(frame, ycrcbFrame, COLOR_BGR2YCrCb);
        split(ycrcbFrame, channels);
        equalizeHist(channels[0], channels[0]);
        merge(channels, ycrcbFrame);
        cvtColor(ycrcbFrame, frame, COLOR_YCrCb2BGR);
        imshow("Output_dst", frame);
        char c = waitKey(50);
        if (c == 27)
            break;
    }
    cap.release();
    return 0;
}
