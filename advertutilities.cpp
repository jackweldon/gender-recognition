#include "advertutilities.h"

AdvertUtilities::AdvertUtilities()
{

}
void AdvertUtilities::displayAdvert(){
    if(Globals::Instance()->femaleTempCount <= Globals::Instance()->maleTempCount){
    image = imread("MaleAd.jpg");
    imshow("Ad",image);
    }else{
        image = imread("FemaleAd.jpg");
       imshow("Ad",image);
    }

  resizeWindow("Ad",size,size);
}

void AdvertUtilities::setAdvertSize(int s){
    size = s;
}
int AdvertUtilities::getAdvertSize(){
    return size;
}

void AdvertUtilities::updateDuration(int sec){

}
void AdvertUtilities::adDuration(){

}
