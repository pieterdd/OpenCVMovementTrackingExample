#include "webcamtracker.h"

#include <cassert>
#include <opencv2/opencv.hpp>

WebcamTracker::WebcamTracker()
    : _vidCap(0)
{
    _kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size2i(3, 3), cv::Point2i(1, 1));
    assert(_vidCap.isOpened());

    _threshold = true;
    _morphTransform = true;
    _greyscale = true;

    // Load initial frames
    _vidCap >> _curFrame;
    prepareNextFrame();
}

WebcamTracker::~WebcamTracker()
{
}

void WebcamTracker::prepareNextFrame()
{
    // Save the current image
    _prvFrame = _curFrame.clone();

    // Get a new image
    _vidCap >> _curFrame;

    // Subtract the two to create a diff image.
    cv::subtract(_curFrame, _prvFrame, _difFrame);

    // Evaluates the value of a single color channel on each pixel. If it is under
    // a certain threshold, the pixel value will be set to 0. Otherwise it will
    // be maxed out.
    if (_threshold)
        cv::threshold(_difFrame, _difFrame, 15, 255, CV_THRESH_BINARY);

    // This helps reduce the background noise that crops up after thresholding.
    if (_morphTransform)
        cv::morphologyEx(_difFrame, _difFrame, CV_MOP_OPEN, _kernel, cv::Point2i(-1, -1), 1);

    // Converts the diff image to grayscale.
    if (_greyscale)
        cv::cvtColor(_difFrame, _difFrame, CV_BGR2GRAY);
}

void WebcamTracker::toggleThreshold()
{
    _threshold = !_threshold;
    std::cout << "'Enable thresholding' is now " << boolToString(_threshold) << std::endl;
}

void WebcamTracker::toggleMorphTransform()
{
    _morphTransform = !_morphTransform;
    std::cout << "'Enable morph transformation' is now " << boolToString(_morphTransform) << std::endl;
}

void WebcamTracker::toggleGreyscale() {
    _greyscale = !_greyscale;
    std::cout << "'Enable greyscale conversion' is now " << boolToString(_greyscale) << std::endl;
}

