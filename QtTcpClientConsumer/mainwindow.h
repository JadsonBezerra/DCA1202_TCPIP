#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include"plotter.h"

namespace Ui {
class MainWindow;
}
/**
 * @brief A classe MainWindow é a classe que gera a janela principal
 */
class MainWindow : public QMainWindow
{
  Q_OBJECT
    /**
     * @brief A variavel QString guarda o IP do servidor e o IP da maquina que gerou os dados pro servidor
     */

QString strIP,getIP;
int cont,timer;
std::vector<int> id;
public:
  explicit MainWindow(QWidget *parent = 0);
    void timerEvent(QTimerEvent *event);
  ~MainWindow();
    /**
     * @brief o metodo getData realiza o processo necessário para receber dados do servidor
     */
      void getData();


signals:
      /**
       * @brief o sinal passData passa os dados
       */

  std::vector<float> passData(std::vector<float>);

  /**
   * @brief o sinal passTime passa o tempo
   */
  std::vector<int> passTime(std::vector<int>);
public slots:

  /**
   * @brief o metodo update atualiza os IPS das maquinas que geraram os dados
   */
  void update();

  /**
   * @brief o metodo changeGetIp modifica a variavel getIP
   */
  void changeGetIp(QString _g);

  /**
   * @brief O metodo tcpConnect conecta a mainWindow no servidor
   */
  void tcpConnect();

  /**
   * @brief O metodo tcpDisconnect desconecta a mainWindow no servidor
   */
  void tcpDisconnect();

  /**
   * @brief O metodo setIP modifica a variavel strIP
  */
  void setIP(QString);

  /**
   * @brief O metodo ligaTimer liga o timer
   */
  void ligaTimer();

  /**
   * @brief O metodo desligaTimer desliga o timer
   */
  void desligaTimer();

  /**
   * @brief O metodo setTimer modifica o tempo do timer
   */
  void setTimer(int _t);
private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
};

#endif // MAINWINDOW_H
