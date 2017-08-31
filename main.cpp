#include "mainwindow.h"
#include <QApplication>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdio.h>
#include <assert.h>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include "QOpenCVWidget.h"
int main(int argc, char *argv[])
{
    CvCapture * camera = cvCreateCameraCapture(0);
    assert(camera);
    IplImage * image=cvQueryFrame(camera);
    assert(image);

    QApplication app(argc, argv);

    QFile qss("C:/Users/Jack/Documents/FinalYear/ProjectGUI/qdarkstyle/style.qss");
    qss.open(QFile::ReadOnly);
    app.setStyleSheet(qss.readAll());
    qss.close();

    MainWindow *mainWin = new MainWindow(camera);
    mainWin->setWindowTitle("Gender Classification");
    mainWin->show();

    int retval = app.exec();

    cvReleaseCapture(&camera);

    return retval;
}
