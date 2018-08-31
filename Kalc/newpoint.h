#ifndef NEWPOINT_H
#define NEWPOINT_H
#include <QWidget>
#include "controller.h"

class newPoint : public QWidget
{
private:

public:
    newPoint(Controller* c , QWidget *parent = nullptr);

};

#endif // NEWPOINT_H
