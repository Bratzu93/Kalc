#ifndef Poligono_H
#define Poligono_H
#include "Punto.h"
#include "Base.h"
#include <vector>
#include <list>
using std::list;
using std::vector;

class Poligono :public Base
{
private:
    vector<const Punto*> l;

public:
    Poligono(const Poligono&);
    Poligono(const Base&);
    Poligono& operator=(const Poligono&);
    ~Poligono();
    void stampa()const;
    virtual  double area()const;
    virtual  double perimetro()const;
    virtual  bool equilatero()const;
    //vector<Poligono>* triangolazione()const;   triangolazione: dato un poligono, determinare una sua partizione in triangoli.
    //bool equiangolo()const; // Da fare

    bool operator<(const Poligono& p) const;
//    bool operator>(const Poligono&) const;
//    bool operator==(const Poligono&)const;
//    bool operator!=(const Poligono&)const;
//    Poligono& operator+(const Poligono&);
//    Poligono& operator-(const Poligono&);
//    virtual  Poligono& operator*(const double&);
//    virtual  Poligono& operator/(const double&);

};

#endif // Poligono_H
