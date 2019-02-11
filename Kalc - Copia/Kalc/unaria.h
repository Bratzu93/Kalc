#ifndef UNARIA_H
#define UNARIA_H
#include <QWidget>
#include "controller.h"

class Unaria : public QWidget
{
    Q_OBJECT
private:
    Controller* control;
public:
    Unaria(Controller* controller,QWidget *parent = nullptr);
};

#endif // UNARIA_H
