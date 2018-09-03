#ifndef CREAZIONE_H
#define CREAZIONE_H

#include <QWidget>
#include <QPushButton>
#include<QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include "controller.h"
#include "newpoint.h"
#include "newsegmento.h"
#include "newpoligono.h"

class Creazione : public QWidget
{
    Q_OBJECT

public:
    explicit Creazione(Controller* controller,QWidget *parent = nullptr);
public slots:

signals:
    void AddItem();
private:
    QHBoxLayout* creazione;
    Controller* control;
    newPoint* newpoint;
    newSegmento* newsegm;
    newPoligono* new_poligono;

};

#endif // CREAZIONE_H
