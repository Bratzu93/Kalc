#include "Punto.h"

Punto::Punto(double _x, double _y):x(_x),y(_y){}
Punto::Punto(const Punto &p):x(p.x),y(p.y){}
Punto& Punto::operator=(const Punto& p){
    x=p.x;
    y=p.y;
    return *this;
}

Punto::~Punto(){std::cout<<"ho distrutto un punto"<<std::endl;}

// operazioni matematiche fra punti
bool Punto::operator<(const Punto& p)const{
    return x < p.x || (x == p.x && y < p.y);
}
bool Punto::operator>(const Punto& p)const{
    return x > p.x || (x == p.x && y > p.y);
}
bool Punto::operator ==(const Punto& p)const{
    return x==p.x && y==p.y;
}
bool Punto::operator!=(const Punto& p)const{
    return (x!=p.x || y!=p.y);
}


Punto& Punto::operator+(const Punto& p){
    x=x+p.x;
    y=y+p.y;
    return *this;
}
Punto& Punto::operator-(const Punto& p){
    x=x-p.x;
    y=y-p.y;
    return *this;
}
Punto& Punto::operator*(const double& p){
    x=x*p;
    y=y*p;
    return *this;
}
Punto& Punto::operator/(const double& p){
    x=x/p;
    y=y/p;
    return *this;
}

// metodi setter e getter
void Punto::set_x(const double& _x){
    x=_x;
}
void Punto::set_y(const double& _y){
    y=_y;
}
double Punto::get_x()const{
    return x;
}
double Punto::get_y()const{
    return y;
}

//altre funzioni
double Punto::aux_distance(const Punto &p1, const Punto &p2){
    return pow(p2.x-p1.x,2)+pow(p2.y-p1.y,2);
}
double Punto::angolo(const Punto& O, const Punto& A, const Punto& B){
        return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
double Punto::distanza(const Punto& first_point, const Punto& second_point){
return sqrt(aux_distance(first_point,second_point));
}

void Punto::trasla_ascissa(const double &_x){
    x=x+_x;
}
void Punto::trasla_ordinata(const double& _y){
y=y+_y;
}
void Punto::trasla(const double& _x, const double& _y){
    trasla_ascissa(_x);
    trasla_ordinata(_y);
}

void Punto::stampa() const{
    std::cout<<*this;
}

std::ostream& operator<<(std::ostream& os, const Punto& p){
    os<<"("<<p.x<<","<<p.y<<")";
    return os;
}
