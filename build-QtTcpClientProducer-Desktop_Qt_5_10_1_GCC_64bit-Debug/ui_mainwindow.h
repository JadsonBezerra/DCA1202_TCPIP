/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButtonPut;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QSlider *SliderMax;
    QLCDNumber *LCDMax;
    QSplitter *splitter_2;
    QSlider *SliderMin;
    QLCDNumber *LCDMin;
    QLineEdit *serverIP;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Connect;
    QPushButton *Disconnect;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(463, 252);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButtonPut = new QPushButton(centralWidget);
        pushButtonPut->setObjectName(QStringLiteral("pushButtonPut"));
        pushButtonPut->setGeometry(QRect(371, 73, 80, 25));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 120, 361, 56));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        splitter = new QSplitter(layoutWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        SliderMax = new QSlider(splitter);
        SliderMax->setObjectName(QStringLiteral("SliderMax"));
        SliderMax->setMinimum(1);
        SliderMax->setOrientation(Qt::Horizontal);
        splitter->addWidget(SliderMax);
        LCDMax = new QLCDNumber(splitter);
        LCDMax->setObjectName(QStringLiteral("LCDMax"));
        LCDMax->setProperty("intValue", QVariant(1));
        splitter->addWidget(LCDMax);

        verticalLayout->addWidget(splitter);

        splitter_2 = new QSplitter(layoutWidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        SliderMin = new QSlider(splitter_2);
        SliderMin->setObjectName(QStringLiteral("SliderMin"));
        SliderMin->setMinimum(1);
        SliderMin->setOrientation(Qt::Horizontal);
        splitter_2->addWidget(SliderMin);
        LCDMin = new QLCDNumber(splitter_2);
        LCDMin->setObjectName(QStringLiteral("LCDMin"));
        LCDMin->setProperty("intValue", QVariant(1));
        splitter_2->addWidget(LCDMin);

        verticalLayout->addWidget(splitter_2);


        horizontalLayout->addLayout(verticalLayout);

        serverIP = new QLineEdit(centralWidget);
        serverIP->setObjectName(QStringLiteral("serverIP"));
        serverIP->setGeometry(QRect(120, 40, 113, 25));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(280, 40, 172, 27));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        Connect = new QPushButton(widget);
        Connect->setObjectName(QStringLiteral("Connect"));

        horizontalLayout_2->addWidget(Connect);

        Disconnect = new QPushButton(widget);
        Disconnect->setObjectName(QStringLiteral("Disconnect"));

        horizontalLayout_2->addWidget(Disconnect);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 463, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(SliderMax, SIGNAL(valueChanged(int)), LCDMax, SLOT(display(int)));
        QObject::connect(SliderMin, SIGNAL(valueChanged(int)), LCDMin, SLOT(display(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonPut->setText(QApplication::translate("MainWindow", "putData", nullptr));
        label->setText(QApplication::translate("MainWindow", "MAX", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "MIN", nullptr));
        serverIP->setText(QApplication::translate("MainWindow", "127.0.0.1", nullptr));
        Connect->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        Disconnect->setText(QApplication::translate("MainWindow", "Disconnect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
