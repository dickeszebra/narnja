#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

namespace colors {
    const cv::Scalar red = cv::Scalar(0, 0, 255);
    const cv::Scalar green = cv::Scalar(0, 255, 0);
    const cv::Scalar blue = cv::Scalar(255, 0, 0);
}

int main(int argc, char** argv) {
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cout << "Could not open capture device" << std::endl;
        return -1;
    }

    cv::namedWindow("cam", CV_WINDOW_AUTOSIZE);
    while (true) {
        cv::Mat frame;
        cap >> frame;
        cv::imshow("cam", frame);
        if (cv::waitKey(10) >= 0) break;
    }

    return 0;
}