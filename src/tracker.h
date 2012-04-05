#ifndef TRACKER_H
#define TRACKER_H

#include <opencv2/opencv.hpp>

/*
 * Interface for tracking implementations. This could be a live webcam capture
 * as well as prerecorded footage.
 */
class Tracker
{
public:
    Tracker();

    // Process the next frame, making the results available
    // through the aforementioned getters.
    virtual void prepareNextFrame() = 0;

    // Mandatory getters
    virtual cv::Mat curFrame() const = 0;
    virtual cv::Mat prvFrame() const = 0;
    virtual cv::Mat difFrame() const = 0;
};

#endif // TRACKER_H
