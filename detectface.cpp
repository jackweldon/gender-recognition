#include "detectface.h"


using namespace cv;
using namespace std;

DetectFace::DetectFace()
{

}

IplImage DetectFace::returnFace(IplImage *cvimage){
try{
    vector<Rect> faces;
    Mat gray;
    Mat video_frame;
    video_frame = imageToMat(cvimage);

    //input , output
    cvtColor(video_frame, gray, CV_BGR2GRAY);

    //input , output
    equalizeHist(gray, gray);

    //input image, vec for faces ..
    face_cascade.detectMultiScale(gray, faces, 1.1, 2, 0 | 4, Size(30, 30));

    for (size_t i = 0; i < faces.size(); i++)
    {
        Mat faceROI = gray(faces[i]);
        /*Size is size of images used for fisher face model creation*/
        //resize(gray, faceROI, Size(130, 160)); // for feretfaces
        resize(gray, faceROI, Size(100,100)); // for fisherfaces 2nd
        //resize(gray, faceROI, Size(70,100));// mood

        //draw rectangle around face current face
        rectangle(video_frame, faces[i], CV_RGB(0, 255, 0), 1);
    }
    mymat = video_frame;
    img = matToImage(mymat);


    return img;

    }catch(cv::Exception e){
        cout << e.msg << endl;
    }
}

cv::Mat DetectFace::returnFace(cv::Mat video_frame){
    vector<Rect> faces;
    Mat gray;
    //input , output
    cvtColor(video_frame, gray, CV_BGR2GRAY);

    //input , output
    equalizeHist(gray, gray);

    //input image, vec for faces ..
    Globals::Instance()->getCascade().detectMultiScale(gray, faces, 1.1, 2, 0 | 4, Size(30, 30));

    for (size_t i = 0; i < faces.size(); i++)
    {
        //current face
        Mat faceROI = gray(faces[i]);
        Globals::Instance()->updateFaceCount();
        rectangle(video_frame, faces[i], CV_RGB(0, 255, 0), 2);

        gender = genderClassifier.classifyGender(faceROI);// classifyGender(faceROI);

        if(gender==0) {
            putText(video_frame, "Male", cvPoint(faces[i].x + (faces[i].width / 2), faces[i].y),
                    FONT_HERSHEY_SIMPLEX, 1.0, Scalar(0, 255, 0), 2, 8, false);
        }
        if(gender == 1) {

            putText(video_frame, "Female", cvPoint(faces[i].x + (faces[i].width / 2), faces[i].y),
                    FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255, 131, 250), 2, 8, false);
        }

    }
    return video_frame;
}
IplImage DetectFace::matToImage(Mat mat){
    IplImage image = mat;
    return image;
}

Mat DetectFace::imageToMat(IplImage *image){
    Mat imgMat(image);
    return imgMat;
}

QString DetectFace::returnGender(){
    if(gender == 1)
        return "Female";
    if(gender == 0)
        return "Male";
    else
        return "No Gender Detected";
}
