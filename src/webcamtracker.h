#ifndef WEBCAMTRACKER_H
#define WEBCAMTRACKER_H

#include "tracker.h"
#include <opencv2/opencv.hpp>

/*
 * Lets you track live movement by diff'ing subsequent camera frames.
 */
class WebcamTracker : public Tracker
{
public:
    WebcamTracker();
    ~WebcamTracker();

    // Process the next frame, making the results available
    // through the aforementioned getters.
    void prepareNextFrame();

    // Frame getters
    cv::Mat curFrame() const { return _curFrame; }
    cv::Mat prvFrame() const { return _prvFrame; }
    cv::Mat difFrame() const { return _difFrame; }

    // Diff setting togglers
    void toggleThreshold();
    void toggleMorphTransform();
    void toggleGreyscale();
private:
    // Makes a boolean printable
    std::string boolToString(bool value) { return (value) ? "true" : "false"; }

    // Webcam capture
    cv::VideoCapture _vidCap;

    // Image storage
    cv::Mat _curFrame;
    cv::Mat _prvFrame;
    cv::Mat _difFrame;
    cv::Mat _kernel;

    // Diff settings
    bool _threshold;
    bool _morphTransform;
    bool _greyscale;
};

#endif // WEBCAMTRACKER_H
