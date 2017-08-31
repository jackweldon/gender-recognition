#ifndef ADVERTUTILITIES_H
#define ADVERTUTILITIES_H

#include "globals.h"
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "qtimer.h"

using namespace cv;
class AdvertUtilities
{
private slots:
    void adDuration();
private:
    int maleCount;
    int femaleCount;
    int size;
public:
    void updateDuration(int sec);
    AdvertUtilities();
    void displayAdvert();
    void getCommonGender();
    void setAdvertSize(int size);
    int getAdvertSize();
    Mat image;
};

#endif // ADVERTUTILITIES_H
