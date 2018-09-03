#include "Segmento.h"

Segmento::Segmento(const Punto &_p1, const Punto &_p2):p1(_p1),p2(_p2){}

void Segmento::trasla(const double& _x,const double& _y){
p1.trasla(_x,_y);
p2.trasla(_x,_y);
}

Punto Segmento::Punto_medio()const{
    double x= (p1.get_x()+p2.get_x())/2;
    double y= (p1.get_y()+p2.get_y())/2;
return Punto(x,y);
}

Punto Segmento::Punto_piu_vicino(const Punto& p)const{
    //segmento verticale
    if(p2.get_x()-p1.get_x()==0){
     if(p2>p1){
        if(p.get_y()>p2.get_y()) return p2;
        else if(p.get_y()<p1.get_y()) return p1;}
    if(p1>p2){
        if(p.get_y()>p1.get_y()) return p1;
        else if(p.get_y()<p2.get_y()) return p2;}
        return Punto(p1.get_x(),p.get_y());
    }
    //segmento orizzontale
    else if(p2.get_y()-p1.get_y()==0){
        if(p2>p1){
           if(p.get_x()>p2.get_x()) return p2;
           else if(p.get_x()<p1.get_x()) return p1;}
       if(p1>p2){
           if(p.get_x()>p1.get_x()) return p1;
           else if(p.get_x()<p2.get_x()) return p2;}
           return Punto(p.get_x(),p1.get_y());
    }
    //altri casi
    double m1 = (p2.get_y()-p1.get_y())/(p2.get_x()-p1.get_x());
    double q=p1.get_y()-(m1*p1.get_x());
    double m2 = -1/m1;
    double q2= (p.get_y()-m2*p.get_x());
//    std::cout<<"m1 "<<m1<<" q="<<q<<" m2="<<m2<<" q2="<<q2;
    double x= (q2-q)/(m1-m2);
    double y= m1*x+q;
    return Punto(x,y);
}

Punto Segmento::get_firstPoint()const{
    return p1;
}


Punto Segmento::get_secondPoint()const{
    return p2;
}
