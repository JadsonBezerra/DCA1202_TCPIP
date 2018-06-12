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
/**
 * @brief A classe MainWindow é a classe que gera a janela principal
 */
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
  /**
   * @brief O métoodo putData joga os dados pro servidor
    */
  void putData();
public slots:
  /**
   * @brief O Metodo tcpConnect conecta a janela ao servidor
   */
  void tcpConnect();
  /**
   * @brief O Metodo tcpDisconnect desconecta a janela ao servidor
   */
  void tcpDisconnect();
  /**
   * @brief O Metodo changeIP muda o IP do servidor conectado
   */
  void changeIP(QString _IP);
  /**
   * @brief O Metodo setMinData muda o minimo dos dados aleatorios
   */
  void setMinData(int _min);
  /**
   * @brief O Metodo setMaxData muda o maximo dos dados aleatorios
   */
  void setMaxData(int _max);
  /**
   * @brief O Metodo ligaTimer liga o timer
   */
  void ligaTimer();
  /**
   * @brief O Metodo desligaTimer desliga o timer
   */
  void desligaTimer();
  /**
   * @brief O Metodo setTimer configura o timer
   */
  void setTimer(int _t);
private slots:

private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
};

#endif // MAINWINDOW_H
