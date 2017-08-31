#include "genderclassification.h"

using namespace cv;
using namespace std;

GenderClassification::GenderClassification()
{
    confidence = 0;
}

int GenderClassification::classifyGender(Mat face){

    int predictedLabel = -1;
    int predict = 0;

    /*Size is size of images used for fisher face model creation*/
    if(Globals::Instance()->getFisherFile() == Globals::Instance()->fisherPath+"Feret.yml")
    {
        resize(face, face, Size(100,100)); // for fisherfaces2nd.yml

    }
    if(Globals::Instance()->getFisherFile() == Globals::Instance()->fisherPath+"Feret.xml")
    {
                 resize(face,face, Size(130, 160)); // for feretfacesnottingham
    }
    if(Globals::Instance()->getFisherFile() == Globals::Instance()->fisherPath+"nottingham.xml")
    {
         resize(face,face, Size(180, 180)); // for nottingham
    }
    if(Globals::Instance()->getFisherFile() == Globals::Instance()->fisherPath+"combined.xml")
    {
          resize(face,face, Size(130, 160)); // for combined
    }

    //resize(face, face, Size(70,100));// mood

    predict = Globals::Instance()->getFisherModel()->predict(face);

    Globals::Instance()->getFisherModel()->predict(face, predictedLabel, confidence);
    Globals::Instance()->updateConfidence(confidence);

    if(confidence > 0.5) {
        if(predict == 0) {
            Globals::Instance()->updateMale();
            return 0;
        }
        if(predict == 1) {
          Globals::Instance()->updateFemale();
            return 1;
        }
    }
    else
        return 2;
}
