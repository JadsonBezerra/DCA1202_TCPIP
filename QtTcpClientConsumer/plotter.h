#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <vector>

/**
 * @brief A classe plotter é a classe que plota os dados recebisdos do servidor
 */
class plotter : public QWidget
{
  Q_OBJECT
private:
    /**
     * @brief o parametro x é a quantidade de pontos a serem plotados
     */
  int x;
  /**
   * @brief vetor quee contemos valores em y
   */
  std::vector <float> pontos;
  /**
   * @brief vetor quee contemos valores em x
   */
  std::vector <int>time;
public:
  explicit plotter(QWidget *parent = nullptr);
  void paintEvent(QPaintEvent *event);
signals:
public slots:
  /**
   * @brief slot  que recebe os valores a serem plotados
   */
  void recebe(std::vector<float> _teste);
  /**
   * @brief slot  que recebe os valores a serem plotados no eixo do tempo
   */
  void recebeTime(std::vector<int> _teste);
};

#endif // PLOTTER_H




