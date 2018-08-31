#ifndef CONTROLLER_H
#define CONTROLLER_H
#include"model/object.h"
#include"model/Punto.h"
#include"model/poligono.h"
#include"model/segmento.h"
#include"model/poligono.h"
#include"model/base.h"
#include <QString>
#include <typeinfo>

class Controller
{
private:
vector<Object*> list;
Punto* punto;

public:
    Controller();
    void newPunto(double x, double y);
    int getVectorSize()const;
    QString getTypeElem(int i)const;

};

#endif // CONTROLLER_H
