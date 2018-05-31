#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
    int minData,maxData;
    QString strIP;
public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  
public slots:
  void tcpConnect();
  void tcpDisconnect();
  void changeIP(QString _IP);
  void putData();
  void setMinData(int _min);
  void setMaxData(int _max);
private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
};

#endif // MAINWINDOW_H
