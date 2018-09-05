#ifndef CONTROLLER_H
#define CONTROLLER_H
#include"model/object.h"
#include"model/Punto.h"
#include"model/poligono.h"
#include"model/segmento.h"
#include"model/base.h"
#include <typeinfo>
#include <sstream>
class Controller
{
private:
vector<Object*> list;
Base base;
Object* op1;
Object* op2;
Object* res;
Punto punto;
Segmento segmento;
Poligono poligono;

public:
    Controller();
    void newSegm(const Punto& first, const Punto& second);
    void newPunto(double x, double y);
    void newPoligono();
 //   void newPoligono(const Poligono&);
    void newObject();
    std::string stampa(Object* p)const;
    std::string stampaPunto(const Punto& p)const;
    std::string stampaSegmento(const Segmento& p)const;
    std::string stampaPoligono(const Poligono& p)const;
    int getVectorSize()const;
    std::string getTypeElem(int i)const;
    bool AddtoPol(const Punto&);
    Object* getElement(int i)const;
    void setOp1(int);
    void setOp2(int);
    std::string stampaOp1()const;
    std::string stampaOp2()const;
    std::string Somma();
    std::string Differenza();
};

#endif // CONTROLLER_H
