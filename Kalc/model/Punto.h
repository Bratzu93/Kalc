#ifndef Punto_H
#define Punto_H
#include<iostream>
#include <math.h>
class Punto
{
private:
double x,y;
protected:
static double aux_distance(const Punto&,const Punto&);
public:
Punto(const Punto& d); //costruttore di copia
    Punto(double _x=0, double _y=0); // costruttore standard che funge anche da costruttore ad un parametro
    virtual ~Punto(); //distruttore
    Punto& operator=(const Punto&); //assegnazione

    // operazioni matematiche fra punti
    bool operator<(const Punto&) const;
    bool operator>(const Punto&) const;
    bool operator==(const Punto&)const;
    bool operator!=(const Punto&)const;
    Punto& operator+(const Punto&);
    Punto& operator-(const Punto&);
    virtual  Punto& operator*(const double&);
    virtual  Punto& operator/(const double&);

    //metodi setter e getter
    void set_x(const double& _x);
    void set_y(const double& _y);
    double get_x()const;
    double get_y()const;

    // altre funzioni
    virtual void stampa()const;
    friend std::ostream& operator<<(std::ostream& os, const Punto& p);
    static double distanza(const Punto& first_point, const Punto& second_point);
    void trasla_ascissa(const double& _x=0);
    void trasla_ordinata(const double& _y=0);
    void trasla(const double& _x=0,const double& _y=0);
    static double angolo(const Punto* O, const Punto* A, const Punto* B);
    // Ritorna un valore positivo, se OAB fa una svolta in senso antiorario,
    // negativo per il senso orario e zero se i punti sono allineati.
};

#endif // Punto_H
