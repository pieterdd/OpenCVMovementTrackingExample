#include "trackviewer.h"

TrackViewer::TrackViewer()
{
}

void TrackViewer::start()
{
    char key = ' ';

    cv::namedWindow("Current frame");
    cv::namedWindow("Diff frame");

    do {
        // Show the information on screen
        cv::imshow("Current frame", _wt.curFrame());
        cv::imshow("Diff frame", _wt.difFrame());

        // Check if a key was pressed and act accordingly
        key = cvWaitKey(1);
        switch (key) {
        case 't':
            _wt.toggleThreshold();
            break;
        case 'm':
            _wt.toggleMorphTransform();
            break;
        case 'g':
            _wt.toggleGreyscale();
            break;
        default:
            break;
        }

        // Move on to the next frame in line
        _wt.prepareNextFrame();
    } while (key != 'q');
}
