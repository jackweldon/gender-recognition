#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;

MainWindow::MainWindow(CvCapture *cam,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    connect(ui->sliderDuration,SIGNAL(valueChanged(int)),this,SLOT(updateDuration()));
    camera = cam;
    ui->setupUi(this);

    iteration = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent*) {
    IplImage *image=cvQueryFrame(camera);
    //convert IplImage to mat
    cv::Mat mat(image);
    //detect face in image and return with rectangle
    mat = detectFace.returnFace(mat);
    //display in opencvwidget
    ui->cvwidget->putImage(mat);
    iteration++;
    updateIterationList();
    updateTotalsList();
    mat.release();

}

void MainWindow::updateIterationList(){
    QString iterationString = "Iteration: "+QString::number(iteration);
    QString genderString = "   Gender: "+  detectFace.returnGender();
    QString confidence = "   Confidence: " + QString::number(Globals::Instance()->returnConfidence());
    ui->iterationsList->addItem(new QListWidgetItem(iterationString+ genderString+confidence));
    ui->iterationsList->scrollToBottom();
}

void MainWindow::updateTotalsList(){

    ui->listTotals->clear();
    QListWidgetItem *faceCount = new QListWidgetItem("Face Count: "+
                                                     QString::number(Globals::Instance()->getFaceCount()));
    QListWidgetItem *averageConfidence = new QListWidgetItem("Average Confidence: "+
                                              QString::number(Globals::Instance()->returnTotalConfidence()/iteration));
    QListWidgetItem *males = new QListWidgetItem("Males: "+
                                                 QString::number(Globals::Instance()->returnMale()));
    QListWidgetItem *females = new QListWidgetItem("Females: "+
                                                   QString::number(Globals::Instance()->returnFemale()));
    /*QListWidgetItem *runTime= new QListWidgetItem("Run Time: "+
                                                   QString::number(Globals::Instance()->elapsedTime() + " Seconds"));
*/
    ui->listTotals->addItem("Fisher: "+ui->comboFisher->currentText());
    ui->listTotals->addItem("Cascade: "+ui->comboHaar->currentText());
    ui->listTotals->addItem(males);
    ui->listTotals->addItem(females);
    ui->listTotals->addItem(averageConfidence);
    ui->listTotals->addItem(faceCount);
    //ui->listTotals->addItem(runTime);
}

void MainWindow::on_btnStop_clicked()
{
    if(ui->btnStop->isChecked())
    {
        ui->btnStop->setText("Start");
        ui->comboFisher->setEditable(true);
     }

    else{
        getSelectedFiles();
        startTimer(20);

        connect(timer, SIGNAL(timeout()), this, SLOT(update()));
        timer->start(ui->sliderDuration->value()*1000);

        Globals::Instance()->startElapsedTimer();

        ui->comboFisher->setEnabled(false);
        ui->comboHaar->setEnabled(false);
        ui->btnStop->setText("Stop");
    }
}
int MainWindow::getRunTime(){

}

void MainWindow::getSelectedFiles(){

    int indexFisher = ui->comboFisher->currentIndex();
    if(indexFisher == 0) {
        fisher= Globals::Instance()->fisherPath+"Feret.yml";

    } if(indexFisher==1) {
        fisher= Globals::Instance()->fisherPath+"Feret.xml";
    }
    if(indexFisher==2) {
            fisher= Globals::Instance()->fisherPath+"nottingham.xml";
        }
    if(indexFisher==3) {
            fisher= Globals::Instance()->fisherPath+"combined.xml";
        }
    Globals::Instance()->setFisher(fisher);

    int indexHaar = ui->comboHaar->currentIndex();

    if(indexHaar == 0) {
        haarCascade= Globals::Instance()->cascadePath+"haarcascade_frontalface_default.xml";


    } if(indexHaar==1) {
        haarCascade= Globals::Instance()->cascadePath+"haarcascade_frontalface_alt.xml";

    }
    if(indexHaar==2) {
        haarCascade= Globals::Instance()->cascadePath+"lbpcascade_frontalface.xml";

    }
    Globals::Instance()->setCascade(haarCascade);

}

void MainWindow::update(){

    cout<< "Update Advert" <<endl;
     if(ui->chkAdverts->isChecked()){
    advertUtils.setAdvertSize(ui->sliderSize->value());
    advertUtils.displayAdvert();
    }
     Globals::Instance()->femaleTempCount = 0;
     Globals::Instance()->maleTempCount =0;

}

