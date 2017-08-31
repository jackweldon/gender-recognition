/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <qopencvwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QOpenCVWidget *cvwidget;
    QListWidget *iterationsList;
    QListWidget *listTotals;
    QGroupBox *groupBox;
    QPushButton *btnStop;
    QLabel *lblFisher;
    QComboBox *comboFisher;
    QComboBox *comboHaar;
    QLabel *lblHaar;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QCheckBox *chkAdverts;
    QLabel *lblDuration;
    QSlider *sliderDuration;
    QLabel *lblSize;
    QSlider *sliderSize;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(826, 702);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        cvwidget = new QOpenCVWidget(centralWidget);
        cvwidget->setObjectName(QStringLiteral("cvwidget"));
        cvwidget->setGeometry(QRect(20, 10, 531, 411));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cvwidget->sizePolicy().hasHeightForWidth());
        cvwidget->setSizePolicy(sizePolicy);
        cvwidget->setMinimumSize(QSize(400, 400));
        iterationsList = new QListWidget(centralWidget);
        iterationsList->setObjectName(QStringLiteral("iterationsList"));
        iterationsList->setGeometry(QRect(20, 440, 531, 161));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(iterationsList->sizePolicy().hasHeightForWidth());
        iterationsList->setSizePolicy(sizePolicy1);
        iterationsList->setMinimumSize(QSize(400, 150));
        listTotals = new QListWidget(centralWidget);
        listTotals->setObjectName(QStringLiteral("listTotals"));
        listTotals->setGeometry(QRect(570, 440, 241, 161));
        sizePolicy1.setHeightForWidth(listTotals->sizePolicy().hasHeightForWidth());
        listTotals->setSizePolicy(sizePolicy1);
        listTotals->setMinimumSize(QSize(240, 151));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(570, 10, 171, 221));
        btnStop = new QPushButton(groupBox);
        btnStop->setObjectName(QStringLiteral("btnStop"));
        btnStop->setGeometry(QRect(12, 28, 93, 28));
        lblFisher = new QLabel(groupBox);
        lblFisher->setObjectName(QStringLiteral("lblFisher"));
        lblFisher->setGeometry(QRect(12, 110, 88, 16));
        comboFisher = new QComboBox(groupBox);
        comboFisher->setObjectName(QStringLiteral("comboFisher"));
        comboFisher->setGeometry(QRect(12, 133, 131, 22));
        comboFisher->setLayoutDirection(Qt::LeftToRight);
        comboHaar = new QComboBox(groupBox);
        comboHaar->setObjectName(QStringLiteral("comboHaar"));
        comboHaar->setGeometry(QRect(12, 185, 132, 22));
        lblHaar = new QLabel(groupBox);
        lblHaar->setObjectName(QStringLiteral("lblHaar"));
        lblHaar->setGeometry(QRect(12, 162, 77, 16));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(570, 240, 138, 164));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        chkAdverts = new QCheckBox(groupBox_2);
        chkAdverts->setObjectName(QStringLiteral("chkAdverts"));

        gridLayout->addWidget(chkAdverts, 0, 0, 1, 1);

        lblDuration = new QLabel(groupBox_2);
        lblDuration->setObjectName(QStringLiteral("lblDuration"));

        gridLayout->addWidget(lblDuration, 1, 0, 1, 1);

        sliderDuration = new QSlider(groupBox_2);
        sliderDuration->setObjectName(QStringLiteral("sliderDuration"));
        sliderDuration->setMinimum(10);
        sliderDuration->setMaximum(30);
        sliderDuration->setSingleStep(2);
        sliderDuration->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sliderDuration, 2, 0, 1, 1);

        lblSize = new QLabel(groupBox_2);
        lblSize->setObjectName(QStringLiteral("lblSize"));

        gridLayout->addWidget(lblSize, 3, 0, 1, 1);

        sliderSize = new QSlider(groupBox_2);
        sliderSize->setObjectName(QStringLiteral("sliderSize"));
        sliderSize->setMinimum(100);
        sliderSize->setMaximum(200);
        sliderSize->setSingleStep(10);
        sliderSize->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sliderSize, 4, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 826, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Detection Tools", 0));
        btnStop->setText(QApplication::translate("MainWindow", "Start", 0));
        lblFisher->setText(QApplication::translate("MainWindow", "Fisherface File:", 0));
        comboFisher->clear();
        comboFisher->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "FERET Faces YML", 0)
         << QApplication::translate("MainWindow", "FERET Faces XML", 0)
         << QApplication::translate("MainWindow", "Nottingham Faces", 0)
         << QApplication::translate("MainWindow", "Combined ", 0)
        );
        comboHaar->clear();
        comboHaar->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Haar Face Default", 0)
         << QApplication::translate("MainWindow", "Harr Face Alt", 0)
         << QApplication::translate("MainWindow", "LPB Face", 0)
        );
        lblHaar->setText(QApplication::translate("MainWindow", "Cascade File:", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Advert Tools", 0));
        chkAdverts->setText(QApplication::translate("MainWindow", "Display Adverts", 0));
        lblDuration->setText(QApplication::translate("MainWindow", "Advert Duration", 0));
        lblSize->setText(QApplication::translate("MainWindow", "Advert Size", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
