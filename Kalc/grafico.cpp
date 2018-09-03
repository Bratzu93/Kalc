#include "grafico.h"

Grafico::Grafico(Controller *controller, Object* obj, QWidget *parent):QWidget(parent),object(obj),control(controller)
{

//    Punto* punto=static_cast<Punto*>(obj);
//    QLabel* l=new QLabel;
//    QPicture* pi = new QPicture;
//    QPainter* painter = new QPainter(pi);
//    QVBoxLayout* form = new QVBoxLayout;
//    painter->setPen(QPen(Qt::black, 1));
//    painter->drawLine(100, 0, 100, 200);
//    painter->drawLine(0,100,200,100);
//    painter->setPen(QPen(Qt::black, 5, Qt::DashDotLine, Qt::RoundCap));
//    painter->drawPoint(100+(punto->get_x()*5),100-(punto->get_y()*5));
//    painter->end();
//    l->setPicture(*pi);
//    l->setMaximumWidth(300);
//    l->setMaximumHeight(300);
//    form->addWidget(l,2);
//    setLayout(form);

}
