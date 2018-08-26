#ifndef POLIEDRO_H
#define POLIEDRO_H
#include "Punto.h"
#include "Base.h"
#include <vector>
#include "poligono.h"
using std::vector;

class Poliedro:public Poligono
{
private:
double altezza;

public:
Poliedro(double h=1);
Poliedro(const Base&);
Poliedro(const Poligono&);
Poliedro(const Poliedro&);
~Poliedro();
void stampa()const;
double area()const;             //
double perimetro()const;        //metodi virtuali
bool equilatero()const;         //
//void trasla(const double& _x=0,const double& _y=0);

//    bool operator<(const Poliedro&) const;
//    bool operator>(const Poliedro&) const;
//    bool operator==(const Poliedro&)const;
//    bool operator!=(const Poliedro&)const;
//    Poligono& operator+(const Poliedro&);
//    Poligono& operator-(const Poliedro&);
//    virtual  Poliedro& operator*(const double&);
//    virtual  Poliedro& operator/(const double&);

};

#endif // poliedro_H
