#include "segmento.h"

Segmento::Segmento(const Punto &_p1, const Punto &_p2):p1(_p1),p2(_p2){
    if(p1>p2)
        Scambia();
}

void Segmento::stampa()const{
    std::cout<<p1<<p2;
}

std::string Segmento::OutPunti()const{
        std::ostringstream strs;
        strs << p1<<p2;
        std::string str = strs.str();
        return str;
}


void Segmento::Scambia(){
    Punto point=p1;
    p1=p2;
    p2=point;
}

void Segmento::trasla(const double& _x,const double& _y){
p1.trasla(_x,_y);
p2.trasla(_x,_y);
}

Punto Segmento::Punto_medio()const{
    double x= (p1.get_x()+p2.get_x())/2;
    double y= (p1.get_y()+p2.get_y())/2;
return Punto(x,y);
}
double Segmento::coefficenteAngolare()const{
    if(p2.get_x()-p1.get_x()==0) throw SegmentoVerticale();
    else return (p2.get_y()-p1.get_y())/(p2.get_x()-p1.get_x());
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
    double m1 = coefficenteAngolare();
    double q=p1.get_y()-(m1*p1.get_x());
    double m2 = -1/m1;
    double q2= (p.get_y()-m2*p.get_x());
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

double Segmento::lunghezza()const{
    return Punto::distanza(p1,p2);
}

Segmento operator +(const Segmento& s1,const Segmento& s2){
    Segmento temporaneo;
        if(s1==s2){
        temporaneo=s1;
        }else if(s1<s2){
        if(s1>s2){
        Segmento temp(s1.p1,s1.p2);
        temporaneo=temp;}
        else{
        Segmento temp(s1.p1,s2.p2);
        temporaneo=temp;}
    }else if(s2<s1){
        if(s1>s2){
            Segmento temp(s2.p1,s1.p2);
            temporaneo=temp;}
        else{
            Segmento temp(s2.p1,s2.p2);
            temporaneo=temp;
        }
    }
    return temporaneo;
}

Segmento operator -(const Segmento& s1,const Segmento& s2){
    Segmento temporaneo;
        if(s1==s2){
        temporaneo=s1;
        }else if(s1>s2){
        if(s1<s2){
        Segmento temp(s1.p1,s1.p2);
        temporaneo=temp;}
        else{
        Segmento temp(s1.p1,s2.p2);
        temporaneo=temp;}
    }else if(s2>s1){
        if(s1<s2){
            Segmento temp(s2.p1,s1.p2);
            temporaneo=temp;}
        else{
            Segmento temp(s2.p1,s2.p2);
            temporaneo=temp;
        }
    }
    return temporaneo;
}

Segmento operator *(const Segmento& s1,const Segmento& s2){
    double dist = s2.lunghezza();
    Punto point((s1.p2).operator *(dist));
    Segmento temporaneo(s1.p1,point);
    return temporaneo;
}

Segmento operator /(const Segmento& s1,const Segmento& s2){
    double dist = s2.lunghezza();
    if(dist==0) throw DivisionePerZero();
    Punto point((s1.p2).operator /(dist));
    Segmento temporaneo(s1.p1,point);
    return temporaneo;
}


bool Segmento::operator<(const Segmento& s1) const{
    return (p1<s1.p1);
}
bool Segmento::operator>(const Segmento& s1) const{
    return (p1>s1.p1);
}

bool Segmento::operator==(const Segmento& s) const{
return (p1==s.p1 && p2==s.p2);
}
bool Segmento::operator!=(const Segmento& s)const{
	return (p1!=s.p1 || p2!=s.p2);
}
