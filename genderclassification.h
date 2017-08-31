#ifndef GENDERCLASSIFICATION_H
#define GENDERCLASSIFICATION_H
#include "opencv/cv.h"
#include "opencv2/contrib/contrib.hpp"
#include "QString"
#include "QResource"
#include "QFile"
#include "globals.h"

using namespace cv;
class GenderClassification
{
public:
    GenderClassification();
    int classifyGender(Mat face);
private:
    double confidence;
};

#endif // GENDERCLASSIFICATION_H
