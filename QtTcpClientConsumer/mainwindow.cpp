#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  socket = new QTcpSocket(this);
    cont=2;
    timer=1;
    connect(this,
            SIGNAL(passTime(std::vector<int>)),
            ui->widget,
            SLOT(recebeTime(std::vector<int>)));
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
  connect(ui->listWidget,
          SIGNAL(currentTextChanged(QString)),
          this,
          SLOT(changeGetIp(QString)));

  strIP="127.0.0.1";
  getIP=strIP;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    getData();
}

void MainWindow::tcpConnect(){
  QString str;
  socket->connectToHost(strIP,1234);
  if(socket->waitForConnected(3000)){
    getIP=strIP;
    qDebug() << "Connected";
    socket->write("list");
    socket->waitForBytesWritten();
    socket->waitForReadyRead();
    while(socket->bytesAvailable()){
      str = socket->readLine().replace("\n","").replace("\r","");
      qDebug() << str;
      ui->listWidget->clear();
      ui->listWidget->addItem(str);
      }
    ui->label_con->setText("Connected to "+strIP);
  }
  else{
    qDebug() << "Disconnected";
        ui->label_con->setText("Connection Error");
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
          ui->label_con->setText("Disconnected");
    }
}

void MainWindow::setIP(QString _IP)
{
    strIP=QString (_IP);
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
    cont=0;
    id.clear();
}

void MainWindow::setTimer(int _t)
{
    timer=_t;
    if(id.size()){
        ligaTimer();
    }
}


void MainWindow::getData(){
  QString str,aux;
  QByteArray array;
  QStringList list;
  qint64 thetime;
  std::vector <int>valores,timeP;
  std::vector <long long>time;
  qDebug() << "to get data...";
  if(socket->state() == QAbstractSocket::ConnectedState){
    if(socket->isOpen()){
      qDebug() << "reading...";
      aux=QString::fromStdString(std::to_string(cont));
      array=QByteArray("get "+getIP.toUtf8()+" "+aux.toUtf8()+"\r\n");
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
          valores.push_back((int)str.toFloat());
          time.push_back((long long)thetime);
          qDebug() << thetime << ": " << str;
        }
      }
    }
  }

  for(int i=0;i<time.size();i++){
      timeP.push_back(-time[i]+time[time.size()-1]);
      qDebug()<<timeP[i];
  }
  cont=valores.size()+1;
  emit passData(valores);
  emit passTime(timeP);
}

void MainWindow::update()
{
    QString str;
    socket->write("list");
    socket->waitForBytesWritten();
    socket->waitForReadyRead();
    while(socket->bytesAvailable()){
      str = socket->readLine().replace("\n","").replace("\r","");
      qDebug() << str;
      ui->listWidget->clear();
      ui->listWidget->addItem(str);
      }
}

void MainWindow::changeGetIp(QString _g)
{
    getIP=_g;
}


MainWindow::~MainWindow()
{
  delete socket;
  delete ui;
}
