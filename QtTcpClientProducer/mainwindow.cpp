#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent), ui(new Ui::MainWindow){
  ui->setupUi(this);
  socket = new QTcpSocket(this);

  connect(ui->Start,
          SIGNAL(clicked(bool)),
          this,
          SLOT(ligaTimer()));
  connect(ui->Stop,
          SIGNAL(clicked(bool)),
          this,
          SLOT(desligaTimer()));
  connect(ui->sliderTiming,
          SIGNAL(valueChanged(int)),
          this,
          SLOT(setTimer(int)));
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
  timer=1;
  maxData=10;
  minData=1;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    putData();
}

void MainWindow::tcpConnect(){
  socket->connectToHost(strIP,1234);
  if(socket->waitForConnected(3000)){
      ui->textBrowser->append("Connected");
    qDebug() << "Connected";
      ui->labelConnect->setText("Connected to "+strIP);
  }
  else{
      ui->textBrowser->append("Connection error");
    qDebug() <<"Connection error";
    ui->labelConnect->setText("Connection error");
  }
}

void MainWindow::tcpDisconnect()
{
    socket->disconnectFromHost();
    if(socket->waitForConnected(3000)){
        ui->textBrowser->append("Connected");
      qDebug() << "Connected";
       ui->labelConnect->setText("Connected to "+strIP);
    }
    else{
        ui->textBrowser->append("Disconected");
      qDebug() << "Disconnected";
       ui->labelConnect->setText("Disconnected");
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
    str = "set "+ QString::number(msecdate) + " " + QString::number((float)minData+((float)qrand()/(float)RAND_MAX)*(float)(maxData-minData))+"\r\n";
    ui->textBrowser->append(str);
      qDebug() << str;
      qDebug() << socket->write(str.toStdString().c_str()) << " bytes written";
      if(socket->waitForBytesWritten(3000)){
        qDebug() << "wrote";
      }
  }
}

void MainWindow::setMinData(int _min)
{
    ui->SliderMax->setMinimum(_min);
    minData=_min;
}

void MainWindow::setMaxData(int _max)
{
    maxData=_max;
}

void MainWindow::ligaTimer()
{
    if(id.size()==0){
       id.push_back(startTimer(1000*timer));
    }
    else{
        killTimer(id[0]);
        id[0]=startTimer(1000*timer);
    }
}

void MainWindow::desligaTimer()
{
    killTimer(id[0]);
    id.clear();
}

void MainWindow::setTimer(int _t)
{
    timer=_t;
    if(id.size()){
        ligaTimer();
    }
}

MainWindow::~MainWindow(){
  delete socket;
  delete ui;
}
