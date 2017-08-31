#include "qopencvwidget.h"
#include "opencv2/highgui/highgui.hpp"
using namespace cv;
// Constructor
QOpenCVWidget::QOpenCVWidget(QWidget *parent) : QWidget(parent) {
    layout = new QVBoxLayout;
    imagelabel = new QLabel;
    QImage dummy(100,100,QImage::Format_RGB32);
    image = dummy;
    layout->addWidget(imagelabel);

    for (int x = 0; x < 100; x++) {
        for (int y =0; y < 100; y++) {
            image.setPixel(x,y,qRgb(x, y, y));
        }
    }
    imagelabel->setPixmap(QPixmap::fromImage(image));

    setLayout(layout);
}

QOpenCVWidget::~QOpenCVWidget(void) {

}
/*
 * Put Image Method for IplImage (c implementation)
 * */
void QOpenCVWidget::putImage(IplImage *cvimage){
    int cvIndex, cvLineStart;

    // switch between bit depths
    switch (cvimage->depth) {
    case IPL_DEPTH_8U:
        switch (cvimage->nChannels) {
        case 3:
            if ( (cvimage->width != image.width()) || (cvimage->height != image.height()) ) {
                QImage temp(cvimage->width, cvimage->height, QImage::Format_RGB32);
                image = temp;
            };

            cvIndex = 0; cvLineStart = 0;
            for (int y = 0; y < cvimage->height; y++) {

                unsigned char red,green,blue;
                cvIndex = cvLineStart;
                for (int x = 0; x < cvimage->width; x++) {
                    // DO it
                    red = cvimage->imageData[cvIndex+2];
                    green = cvimage->imageData[cvIndex+1];
                    blue = cvimage->imageData[cvIndex+0];

                    image.setPixel(x,y,qRgb(red, green, blue));
                    cvIndex += 3;
                }
                cvLineStart += cvimage->widthStep;
            }
            break;
        default:
            printf("This number of channels is not supported\n");
            break;
        }
        break;
    default:
        printf("This type of IplImage is not implemented in QOpenCVWidget\n");
        break;
        imagelabel->setPixmap(QPixmap::fromImage(image));

    }
}

void QOpenCVWidget::putImage(cv::Mat mat){

    QPixmap p;
    cv::Mat temp ;

    cvtColor(mat, temp,CV_BGR2RGB);

    QImage dest((const uchar *) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);

    dest.bits();

    p =QPixmap::fromImage(dest);

    imagelabel->setPixmap( p );
}
