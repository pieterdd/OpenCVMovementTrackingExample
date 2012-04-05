#ifndef TRACKVIEWER_H
#define TRACKVIEWER_H

#include "webcamtracker.h"

class TrackViewer
{
public:
    TrackViewer();

    void start();
private:
    WebcamTracker _wt;
};

#endif // TRACKVIEWER_H
