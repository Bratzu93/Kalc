#include "controller.h"

Controller::Controller()
{

}

void Controller::newPunto(double x, double y) {
    Punto* l = new Punto(x,y);
    Controller::list.push_back(l);
}

int Controller::getVectorSize()const{
return list.size();
}

QString Controller::getTypeElem(int i)const{
return typeid(*(list[i])).name();
}
