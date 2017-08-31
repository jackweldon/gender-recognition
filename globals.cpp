#include "globals.h"

Globals* Globals::m_pInstance = NULL;
Globals* Globals::Instance()
{

    if (!m_pInstance) // Only allow one instance of class to be generated.
        m_pInstance = new Globals;

    return m_pInstance;
}
cv::Ptr<FaceRecognizer> Globals::getFisherModel(){

    return model;
}
void Globals::setFisher(string fisherFace){

    fisher = fisherFace;
    try{
        model = createFisherFaceRecognizer();
        model->load(fisher);
        printf("Fisher Model Loaded...\n");
    }
    catch(Exception e) {
        cout << e.msg << endl;
    }
}

void Globals::setCascade(string cascade){
    try{
        face_cascade.load(cascade);
        printf("Cascade Loaded.. \n");
    }
    catch (cv::Exception &e) {
        cout << e.msg << endl;
    }
}
CascadeClassifier Globals::getCascade(){
    return face_cascade;
}
