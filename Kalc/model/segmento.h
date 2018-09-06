#ifndef Segmento_H
#define Segmento_H
#include"Punto.h"

class Segmento : public Object
{
private:
    Punto p1;
    Punto p2;
public:
    Segmento(const Punto& _p1=(0), const Punto& _p2=(0));
    Punto Punto_medio()const;
    Punto Punto_piu_vicino(const Punto&)const;
    void trasla(const double& _x,const double& _y);
    Punto get_firstPoint()const;
    Punto get_secondPoint()const;
    double lunghezza()const;
    double coefficenteAngolare()const;
    void Scambia();
    void stampa()const;
    bool operator<(const Segmento&) const;
    bool operator>(const Segmento&) const;
    bool operator==(const Segmento&) const;

    friend Segmento operator +(const Segmento&,const Segmento&);
    friend Segmento operator -(const Segmento&,const Segmento&);
    friend Segmento operator *(const Segmento&,const Segmento&);
    friend Segmento operator /(const Segmento&,const Segmento&);
};

#endif // Segmento_H
