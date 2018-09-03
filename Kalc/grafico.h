#ifndef GRAFICO_H
#define GRAFICO_H

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
#include <QScrollArea>


#include <QWidget>

class Grafico : public QWidget
{
    Q_OBJECT
private:
    Object* object;
    Controller* control;
public:
    Grafico(Controller* controller, Object *obj, QWidget *parent = nullptr);
};

#endif // GRAFICO_H
