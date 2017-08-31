#ifndef DETECTFACE_H
#define DETECTFACE_H
#include "opencv/cv.h"
#include "QString"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "genderclassification.h"
class DetectFace
{
public:
    DetectFace();
    void setFisher(String fisher);
    cv::Mat returnFace(cv::Mat video_frame);
    IplImage returnFace(IplImage *cvimage);
    void setCascade(String cascade);
    QString returnGender();

private:
    CascadeClassifier face_cascade;
    cv::Mat imageToMat(IplImage *image);
    IplImage matToImage(cv::Mat mat);
    int gender;
    IplImage img;
    cv::Mat mymat;
    GenderClassification genderClassifier;
    void loadCascades();
};

#endif // DETECTFACE_H
