#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QListWidgetItem>
#include <QVBoxLayout>
#include "QOpenCVWidget.h"
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "opencv2/highgui/highgui.hpp"
#include "detectface.h"
#include "globals.h"
#include "qtimer.h"
#include "advertutilities.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    void timerEvent(QTimerEvent*);
public:
    explicit MainWindow(CvCapture *cam, QWidget *parent = 0);
    ~MainWindow();
    int getRunTime();
private slots:
    void on_btnStop_clicked();
    void update();

private:
    QOpenCVWidget *cvwidget;
    CvCapture *camera;
    DetectFace detectFace;
    AdvertUtilities advertUtils;
    Ui::MainWindow *ui;
    int iteration;
    String fisher;
    String haarCascade;
    void updateTotalsList();
    void updateIterationList();
    void getSelectedFiles();
    void displayAdverts();
    QTimer *timer = new QTimer(this);


};

#endif // MAINWINDOW_H
