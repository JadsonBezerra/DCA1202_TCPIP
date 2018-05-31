#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent), ui(new Ui::MainWindow){
  ui->setupUi(this);
  socket = new QTcpSocket(this);

  connect(ui->pushButtonPut,
          SIGNAL(clicked(bool)),
          this,
          SLOT(putData()));
  connect(ui->SliderMax,
          SIGNAL(valueChanged(int)),
          this,
          SLOT(setMaxData(int)));
  connect(ui->SliderMin,
          SIGNAL(valueChanged(int)),
          this,
          SLOT(setMinData(int)));
  connect(ui->Connect,
          SIGNAL(clicked(bool)),
          this,
          SLOT(tcpConnect()));
  connect(ui->Disconnect,
          SIGNAL(clicked(bool)),
          this,
          SLOT(tcpDisconnect()));
  connect(ui->serverIP,
          SIGNAL(textChanged(QString)),
          this,
          SLOT(changeIP(QString)));
  strIP="127.0.0.1";
}

void MainWindow::tcpConnect(){
  socket->connectToHost(strIP,1234);
  if(socket->waitForConnected(3000)){
    qDebug() << "Connected";
  }
  else{
    qDebug() << "Disconnected";
  }
}

void MainWindow::tcpDisconnect()
{
    socket->disconnectFromHost();
    if(socket->waitForConnected(3000)){
      qDebug() << "Connected";
    }
    else{
      qDebug() << "Disconnected";
    }
}

void MainWindow::changeIP(QString _IP)
{
    strIP=QString (_IP);
}

void MainWindow::putData(){
  QDateTime datetime;
  QString str;
  qint64 msecdate;

  if(socket->state()== QAbstractSocket::ConnectedState){

    msecdate = QDateTime::currentDateTime().toMSecsSinceEpoch();
    str = "set "+ QString::number(msecdate) + " " + QString::number(minData+qrand()%(maxData-minData))+"\r\n";

      qDebug() << str;
      qDebug() << socket->write(str.toStdString().c_str()) << " bytes written";
      if(socket->waitForBytesWritten(3000)){
        qDebug() << "wrote";
      }
  }
}

void MainWindow::setMinData(int _min)
{
    minData=_min;
}

void MainWindow::setMaxData(int _max)
{
    maxData=_max;
}

MainWindow::~MainWindow(){
  delete socket;
  delete ui;
}
