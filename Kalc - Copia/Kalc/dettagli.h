#ifndef DETTAGLI_H
#define DETTAGLI_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QSlider>
#include "controller.h"
#include "newpoint.h"
#include "newsegmento.h"
#include "newpoligono.h"
#include <QPainter>
#include <QLabel>
#include <QPicture>
#include <QLCDNumber>

class Dettagli : public QWidget
{
    Q_OBJECT
private:
    Controller* control;
    QHBoxLayout* form;
    QLabel* _x;
    QLabel* _y;
    QLabel* _xbis;
    QLabel* _ybis;

    QLineEdit* x;
    QLineEdit* y;
    QLineEdit* xbis;
    QLineEdit* ybis;
    QLabel* prim;
    QLabel* sec;
    QLabel* l;
    QPicture* pi;
    QPainter* painter;
public:
    Dettagli(Controller* controller,QWidget *parent = nullptr);
    void DettagliPunto(const Punto& point);
    void DettagliSegmento(const Segmento& s);
    void DettagliPoligono(const Poligono &pol);
public slots:
    void AggiornaDettagli(int i);
signals:


};

#endif // DETTAGLI_H
