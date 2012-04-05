#include "trackviewer.h"

#include <opencv2/opencv.hpp>

int main() {
    // Show some instructions
    std::cout << "Hey, you might wanna try out these keys..." << std::endl;
    std::cout << "  't' toggles thresholding" << std::endl;
    std::cout << "  'm' toggles morphing transformation" << std::endl;
    std::cout << "  'g' toggles greyscale conversion" << std::endl;
    std::cout << "  'q' quits" << std::endl;
    std::cout << std::endl;

    // Catch any OpenCV exceptions that may arise
    try {
        TrackViewer tv;
        tv.start();
    } catch (cv::Exception& e) {
        std::cerr << e.what();
    }

    return 0;
}
