#ifndef Poligono_H
#define Poligono_H
#include "Punto.h"
#include "Base.h"
#include"segmento.h"
#include <vector>
#include <sstream>

using std::vector;

class Poligono :public Base
{
private:
    vector<Punto*> l;

public:
    Poligono(const Poligono&);
    Poligono(Base &);
    Poligono();
    ~Poligono();
    Poligono& operator=(const Poligono&);
    void stampa()const;
    std::string OutPunti()const;
    Punto PointfromPoligon(int i)const;
    vector<Punto*> get_vect()const;
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
    //Poligono& operator*(const double&);
    //Poligono& operator/(const double&);
friend Poligono operator +(const Poligono&,const Poligono&);
friend Poligono operator +(const Poligono&, const Punto&);
friend Poligono operator +(const Poligono&, const Segmento&);

friend Poligono operator -(const Poligono&,const Poligono&);
friend Poligono operator -(const Poligono&, const Punto&);
friend Poligono operator -(const Poligono&, const Segmento&);

};

#endif // Poligono_H
