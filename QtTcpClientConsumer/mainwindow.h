#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include"plotter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
QString strIP,getIP;
int cont,timer;
std::vector<int> id;
public:
  explicit MainWindow(QWidget *parent = 0);
    void timerEvent(QTimerEvent *event);
  ~MainWindow();
      void getData();
  
signals:

  std::vector<int> passData(std::vector<int>);
  std::vector<int> passTime(std::vector<int>);
public slots:
  void update();
  void changeGetIp(QString _g);
  void tcpConnect();
  void tcpDisconnect();
        void setIP(QString);
  void ligaTimer();
  void desligaTimer();
  void setTimer(int _t);
private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
};

#endif // MAINWINDOW_H
