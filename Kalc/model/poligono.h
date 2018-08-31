#ifndef Poligono_H
#define Poligono_H
#include "Punto.h"
#include "Base.h"
#include"segmento.h"
#include <vector>
using std::vector;

class Poligono :public Base
{
private:
    vector<Punto*> l;

public:
    Poligono(const Poligono&);
    Poligono(Base &);
    Poligono& operator=(const Poligono&);
    void stampa()const;
    virtual  double area()const;
    virtual  double perimetro()const;
    virtual  bool equilatero()const;
    //vector<Poligono>* triangolazione()const;   triangolazione: dato un poligono, determinare una sua partizione in triangoli.
    //bool equiangolo()const; // Da fare
    Punto Punto_piu_vicino(const Punto&)const;
    bool interno (const Punto &p)const;
    bool operator<(const Poligono& p) const;
    bool operator>(const Poligono&) const;
    bool operator==(const Poligono&)const;
    bool operator!=(const Poligono&)const;
    Poligono& operator+(const Poligono&);
    double operator-(const Poligono&)const;
    //Poligono& operator*(const double&);
    //Poligono& operator/(const double&);

};

#endif // Poligono_H
