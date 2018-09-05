#include "dettagli.h"

Dettagli::Dettagli(Controller *controller, QWidget *parent):QWidget(parent),control(controller)
{

    form = new QHBoxLayout;
    l = new QLabel;
    pi = new QPicture;
    painter = new QPainter(pi);

    _x= new QLabel;
    _y= new QLabel;
    x = new QLineEdit;
    y = new QLineEdit;
    _xbis= new QLabel;
    _ybis= new QLabel;
    xbis = new QLineEdit;
    ybis = new QLineEdit;
    prim = new QLabel;
    sec = new QLabel;

    setLayout(form);

}


void Dettagli::AggiornaDettagli(int i){
    Object* elem = control->getElement(i);
if(dynamic_cast<Punto*>(elem)){
    Punto* p = static_cast<Punto*>(elem);
    DettagliPunto(*p);
    }
else if(dynamic_cast<Segmento*>(elem)){
    Segmento* s = static_cast<Segmento*>(elem);
    DettagliSegmento(*s);
    }
else if(dynamic_cast<Poligono*>(elem)){
    Poligono* pol = static_cast<Poligono*>(elem);
    DettagliPoligono(*pol);
}

}
void Dettagli::DettagliPunto(const Punto& point){

    delete _x; delete _y; delete x; delete y;
    delete painter; delete pi; delete l;

    _x= new QLabel(tr("x: "));
    _y= new QLabel(tr("y: "));
    x = new QLineEdit;
    y = new QLineEdit;
    x->setText(QString::number(point.get_x()));
    y->setText(QString::number(point.get_y()));

        x->setEnabled(false);
        y->setEnabled(false);
        xbis->setVisible(false);
        _xbis->setVisible(false);
        ybis->setVisible(false);
        _ybis->setVisible(false);
        prim->setVisible(false);
        sec->setVisible(false);
        l = new QLabel;
        pi = new QPicture;
        painter = new QPainter(pi);
        painter->setPen(QPen(Qt::black, 1));
        painter->drawLine(100, 0, 100, 200);
        painter->drawLine(0,100,200,100);
        painter->setPen(QPen(Qt::black, 5, Qt::DashDotLine, Qt::RoundCap));
        painter->drawPoint(100+(point.get_x()*5),100-(point.get_y()*5));
        painter->end();
        l->setPicture(*pi);
        l->setMaximumHeight(200);
        l->setMaximumWidth(200);
        QHBoxLayout* linex = new QHBoxLayout;
        QHBoxLayout* liney = new QHBoxLayout;
        QVBoxLayout* det = new QVBoxLayout;

        linex->addWidget(_x);
        linex->addWidget(x);
        liney->addWidget(_y);
        liney->addWidget(y);
        det->addLayout(linex);
        det->addLayout(liney);
        form->addLayout(det);
        form->addWidget(l,3);

    setLayout(form);
}

void Dettagli::DettagliSegmento(const Segmento& s ){


    delete _x; delete _y; delete x; delete y;
    delete _xbis; delete _ybis; delete xbis; delete ybis; delete prim; delete sec;
    delete painter; delete pi; delete l;

    prim = new QLabel(tr("primo punto"));
    _x= new QLabel(tr("x: "));
    _y= new QLabel(tr("y: "));
    x = new QLineEdit;
    y = new QLineEdit;
    sec = new QLabel(tr("secondo punto"));
    _xbis= new QLabel(tr("x :"));
    _ybis= new QLabel(tr("y :"));
    xbis = new QLineEdit;
    ybis = new QLineEdit;


    x->setText(QString::number(s.get_firstPoint().get_x()));
    y->setText(QString::number(s.get_firstPoint().get_y()));
    xbis->setText(QString::number(s.get_secondPoint().get_x()));
    ybis->setText(QString::number(s.get_secondPoint().get_y()));
    x->setEnabled(false);
    y->setEnabled(false);
    xbis->setEnabled(false);
    ybis->setEnabled(false);

    l = new QLabel;
    pi = new QPicture;
    painter = new QPainter(pi);
    painter->setPen(QPen(Qt::black, 1));
    painter->drawLine(100, 0, 100, 200);
    painter->drawLine(0,100,200,100);
    painter->setPen(QPen(Qt::black, 3));

    painter->drawLine(100+(s.get_firstPoint().get_x()*5),100-(s.get_firstPoint().get_y()*5),100+(s.get_secondPoint().get_x()*5),100-(s.get_secondPoint().get_y()*5));
    painter->end();
    l->setPicture(*pi);
    l->setMaximumHeight(200);
    l->setMaximumWidth(200);

    QHBoxLayout* linex = new QHBoxLayout;
    QHBoxLayout* liney = new QHBoxLayout;
    QVBoxLayout* det = new QVBoxLayout;

    QHBoxLayout* secx = new QHBoxLayout;
    QHBoxLayout* secy = new QHBoxLayout;


    linex->addWidget(_x);
    linex->addWidget(x);
    liney->addWidget(_y);
    liney->addWidget(y);

    secx->addWidget(_xbis);
    secx->addWidget(xbis);
    secy->addWidget(_ybis);
    secy->addWidget(ybis);

    det->addWidget(prim);
    det->addLayout(linex);
    det->addLayout(liney);
    det->addWidget(sec);
    det->addLayout(secx);
    det->addLayout(secy);

    form->addLayout(det);
    form->addWidget(l,3);

setLayout(form);
}

void Dettagli::DettagliPoligono(const Poligono &pol){


    delete _x; delete _y; delete x; delete y;
    delete _xbis; delete _ybis; delete xbis; delete ybis;
    delete painter; delete pi; delete l;

    _x= new QLabel(tr("Punti:"));
    _y= new QLabel(tr("Area"));
    x = new QLineEdit;
    y = new QLineEdit;
    _xbis= new QLabel(tr("Perimetro: "));
    _ybis= new QLabel(tr("equilatero:"));
    xbis = new QLineEdit;
    ybis = new QLineEdit;
    x->setText(QString::fromStdString(control->stampaPoligono(pol)));
    y->setText(QString::number(pol.area()));
    xbis->setText(QString::number(pol.perimetro()));
    ybis->setText(QString::number(pol.equilatero()));
    x->setEnabled(false);
    y->setEnabled(false);
    xbis->setEnabled(false);
    ybis->setEnabled(false);
    prim->setVisible(false);
    sec->setVisible(false);

    l = new QLabel;
    pi = new QPicture;
    painter = new QPainter(pi);
    painter->setPen(QPen(Qt::black, 1));
    painter->drawLine(100, 0, 100, 200);
    painter->drawLine(0,100,200,100);
    painter->setPen(QPen(Qt::black, 3));
    unsigned int dim = pol.get_vect().size();
    for(unsigned int i =1; i<dim;++i){
    painter->drawLine(100+(pol.PointfromPoligon(i-1).get_x()*5),100-(pol.PointfromPoligon(i-1).get_y()*5),100+(pol.PointfromPoligon(i).get_x()*5),100-(pol.PointfromPoligon(i).get_y()*5));
    }
    painter->drawLine(100+(pol.PointfromPoligon(dim-1).get_x()*5),100-(pol.PointfromPoligon(dim-1).get_y()*5),100+(pol.PointfromPoligon(0).get_x()*5),100-(pol.PointfromPoligon(0).get_y()*5));
    painter->end();
    l->setPicture(*pi);
    l->setMaximumHeight(200);
    l->setMaximumWidth(200);
    QHBoxLayout* linex = new QHBoxLayout;
    QHBoxLayout* liney = new QHBoxLayout;
    QVBoxLayout* det = new QVBoxLayout;

    QHBoxLayout* secx = new QHBoxLayout;
    QHBoxLayout* secy = new QHBoxLayout;

    linex->addWidget(_x);
    linex->addWidget(x);
    liney->addWidget(_y);
    liney->addWidget(y);

    secx->addWidget(_xbis);
    secx->addWidget(xbis);
    secy->addWidget(_ybis);
    secy->addWidget(ybis);

    det->addLayout(linex);
    det->addLayout(liney);
    det->addLayout(secx);
    det->addLayout(secy);

    form->addLayout(det);
    form->addWidget(l,3);

setLayout(form);

}
