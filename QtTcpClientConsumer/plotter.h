#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <vector>

class plotter : public QWidget
{
  Q_OBJECT
private:
  int x;
  std::vector <int> pontos;
public:
  explicit plotter(QWidget *parent = nullptr);
  void paintEvent(QPaintEvent *event);
signals:
  int mudaX(int);
  int mudaY(int);
public slots:
  void recebe(std::vector<int> _teste);
};

#endif // PLOTTER_H




