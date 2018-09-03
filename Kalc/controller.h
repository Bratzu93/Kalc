#ifndef CONTROLLER_H
#define CONTROLLER_H
#include"model/object.h"
#include"model/Punto.h"
#include"model/poligono.h"
#include"model/segmento.h"
#include"model/poliedro.h"
#include"model/base.h"
#include <typeinfo>
#include <sstream>
class Controller
{
private:
vector<Object*> list;
Base base;

public:
    Controller();
    void newSegm(const Punto& first, const Punto& second);
    void newPunto(double x, double y);
    void newPoligono();
    std::string stampaPunto(const Punto& p)const;
    std::string stampaPoligono(const Poligono& p)const;
    int getVectorSize()const;
    std::string getTypeElem(int i)const;
    bool AddtoPol(const Punto&);
    Object* getElement(int i)const;

};

#endif // CONTROLLER_H
