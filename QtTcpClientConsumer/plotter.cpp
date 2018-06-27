#include "plotter.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QColor>
#include <QMouseEvent>
#include <cmath>
#include <QDebug>

#define PI 3.1415

plotter::plotter(QWidget *parent) : QWidget(parent)
{
  x=0;
}

void plotter::recebe(std::vector<float> _teste)
{
    pontos=std::vector <float>(_teste);
    x=pontos.size();
}

void plotter::recebeTime(std::vector<int> _teste)
{
    time=std::vector <int>(_teste);
    repaint();
}

void plotter::paintEvent(QPaintEvent *event){
  QPainter painter(this);
  QBrush brush;
  QPen pen;
  painter.setRenderHint(QPainter::Antialiasing);

  brush.setColor(QColor(255,255,255));
  brush.setStyle(Qt::SolidPattern);
  painter.setBrush(brush);

  pen.setColor(QColor(0,0,0));

  painter.drawRect(0,0,width(), height());

  pen.setStyle(Qt::DashLine);
  pen.setWidth(1);
  painter.setPen(pen);

  for(int i=1;i<10;i++)
    painter.drawLine(0,i*height()/10,width(),i*height()/10);

  pen.setStyle(Qt::SolidLine);
  pen.setWidth(2);
  painter.setPen(pen);
  for(unsigned short i=1;i<pontos.size();i++){
      painter.drawLine(
                  (width()*time[i]/(time[pontos.size()-1]-1)),height()*(1-pontos[i]/100.0),
                  (width()*time[i-1]/(time[pontos.size()-1]-1)),height()*(1-pontos[i-1]/100.0));
  }
}


