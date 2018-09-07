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
    bool AddtoPol(const Punto&);
    void newObject();
    std::string stampa(Object* p)const;
    std::string stampaPunto(const Punto& p)const;
    std::string stampaSegmento(const Segmento& p)const;
    std::string stampaPoligono(const Poligono& p)const;
    std::string getTypeElem(int i)const;
    Object* getElement(int i)const;
    int getVectorSize()const;
    void clearBase();
    void setOp1(int);
    void setOp2(int);
    std::string stampaOp1()const;
    std::string stampaOp2()const;
    std::string stampaResult()const;
    std::string IsEquilatero(const Poligono&)const;
    std::string Somma();
    std::string Differenza();
    std::string Moltiplicazione();
    std::string Divisione();
    std::string Punto_piu_vicino();
    std::string Interno();
    void Trasla(const double&,const double&);
    double SommaSegmenti();
};

#endif // CONTROLLER_H
