#ifndef Segmento_H
#define Segmento_H
#include"Punto.h"

class Segmento : public Object
{
private:
    Punto p1;
    Punto p2;
public:
    Segmento(const Punto& _p1, const Punto& _p2=0);
    Punto Punto_medio()const;
    Punto Punto_piu_vicino(const Punto &p)const;
    void trasla(const double& _x,const double& _y);

};

#endif // Segmento_H
