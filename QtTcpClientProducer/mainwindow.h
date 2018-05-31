#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QTimerEvent>
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
    int minData,maxData,timer;
    std::vector <int>id;
    QString strIP;
public:
  explicit MainWindow(QWidget *parent = 0);
  void timerEvent(QTimerEvent *event);
  ~MainWindow();
  void putData();
public slots:
  void tcpConnect();
  void tcpDisconnect();
  void changeIP(QString _IP);
  void setMinData(int _min);
  void setMaxData(int _max);
  void ligaTimer();
  void desligaTimer();
  void setTimer(int _t);
private slots:

private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
};

#endif // MAINWINDOW_H
