#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  socket = new QTcpSocket(this);
    cont=1;
    timer=1;
    connect(ui->sliderTiming,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(setTimer(int)));
    connect(ui->startButton,
             SIGNAL(clicked(bool)),
             this,
             SLOT(ligaTimer()));
    connect(ui->stopButton,
            SIGNAL(clicked(bool)),
            this,
            SLOT(desligaTimer()));
  connect(ui->pushButtonGet,
          SIGNAL(clicked(bool)),
          this,
          SLOT(getData()));
  connect(ui->connectButton,
          SIGNAL(clicked(bool)),
          this,
          SLOT(tcpConnect()));
  connect(ui->disconnectButoon,
          SIGNAL(clicked(bool)),
          this,
          SLOT(tcpDisconnect()));

  connect(this,
          SIGNAL(passData(std::vector<int>)),
          ui->widget,
          SLOT(recebe(std::vector<int>)));
  connect(ui->lineIP,
          SIGNAL(textChanged(QString)),
          this,
          SLOT(setIP(QString)));
  strIP="127.0.0.1";
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    cont++;
    getData();
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

void MainWindow::setIP(QString _IP)
{
    strIP=QString (_IP);
}


void MainWindow::ligaTimer()
{
    if(id.size()==0){
       id.push_back(startTimer(10*timer));
    }
    else{
        killTimer(id[0]);
        id[0]=startTimer(10*timer);
    }
}

void MainWindow::desligaTimer()
{
    killTimer(id[0]);
    cont=0;
}

void MainWindow::setTimer(int _t)
{
    timer=_t;
}


void MainWindow::getData(){
  QString str,aux;
  QByteArray array;
  QStringList list;
  qint64 thetime;
  std::vector <int>teste;
  qDebug() << "to get data...";
  if(socket->state() == QAbstractSocket::ConnectedState){
    if(socket->isOpen()){
      qDebug() << "reading...";
      aux=QString::fromStdString(std::to_string(cont));
      array=QByteArray("get "+strIP.toUtf8()+" "+aux.toUtf8()+"\r\n");
      socket->write(array);
      socket->waitForBytesWritten();
      socket->waitForReadyRead();
      qDebug() << socket->bytesAvailable();
      while(socket->bytesAvailable()){
        str = socket->readLine().replace("\n","").replace("\r","");
        list = str.split(" ");
        if(list.size() == 2){
          bool ok;
          str = list.at(0);
          thetime = str.toLongLong(&ok);
          str = list.at(1);
          teste.push_back(str.toInt());
          qDebug() << thetime << ": " << str;
        }
      }
    }
  }
  emit passData(teste);
}


MainWindow::~MainWindow()
{
  delete socket;
  delete ui;
}
