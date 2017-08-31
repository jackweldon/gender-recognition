#ifndef GLOBALS_H
#define GLOBALS_H
#include "opencv/cv.h"
#include "opencv2/contrib/contrib.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <QElapsedTimer>

using namespace std;
using namespace cv;

class Globals
{
public:
   static Globals* Instance();
   String fisherPath ="fisherfiles/";
   String cascadePath = "cascades/";
   inline string getFisherFile(){ return fisher; }
   cv::Ptr<FaceRecognizer> getFisherModel();
   void setFisher(string fisherFace);

   int elapsedTime(){ return RunTime.elapsed()/1000;}
   void startElapsedTimer(){ RunTime.start();}

   inline void updateFaceCount(){ faceCount++;}
   inline int getFaceCount(){ return faceCount;}
   void setCascade(string cascade);
   CascadeClassifier getCascade();

   void updateMale(){male ++; maleTempCount++;}
   void updateFemale(){female++;femaleTempCount++;}

   void updateConfidence(double i){
       confidence = i;
       totalConfidence = i + totalConfidence;
   }

   int maleTempCount;
   int femaleTempCount;

   inline int returnMale(){return male;}
   inline int returnFemale(){return female;}
   inline double returnTotalConfidence(){return totalConfidence;}
   inline double returnConfidence(){return confidence;}

private:
   Globals(){}  // Private so that it can  not be called
   Globals(Globals const&){}            // copy constructor is privat
   Globals& operator=(Globals const&){}  // assignment operator is private
   static Globals* m_pInstance;
   string fisher;
   int faceCount=0 ;
   string cascade;
   int male =0 ;
   int female=0;

   QElapsedTimer RunTime;

   double confidence=0;
   double totalConfidence=0;

   cv::Ptr<FaceRecognizer> model ;
   CascadeClassifier face_cascade;

};


#endif // GLOBALS_H
