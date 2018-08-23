#include "Poligono.h"

Poligono::Poligono(const Base & B):Base(B){
l = Base::convex_hull(B);
//gestire caso con meno di 3 punti...
}

Poligono::Poligono(const Poligono& p):Base(p),l(p.l){}

Poligono& Poligono::operator=(const Poligono& p){
    if(l==p.l)
        return *this;
    else
    l=p.l;
    return *this;
}

Poligono::~Poligono(){
    for(auto it=l.begin();it!=l.end();++it){
        delete *it;
        it=l.erase(it);
        it--;
    }
}

void Poligono::stampa()const{
    for(auto cit=l.begin();cit!=l.end();++cit){
        (**cit).Punto::stampa();
    }
}

double Poligono::area()const{
    double area=0;
    double n = l.size();
    for(int k=0;k<n-1;k++){
        area += ((*l[k]).get_x() * (*l[k+1]).get_y()) - ((*l[k]).get_y() * (*l[k+1]).get_x());
    }
    return area/2;
// valutare se utilizzare friend per avere x e y
}

double Poligono::perimetro()const{
    double perimetro=0;
    double n = l.size();
    for(int k=0;k<n;k++){
        perimetro +=  Punto::distanza(*l[k],*l[k+1]);
    }
    return perimetro;
}

bool Poligono::equilatero()const{
    double n = l.size(), k=1;
        double d = Punto::distanza(*l[0],*l[1]);
    while(k<n-1){
        if(d != Punto::distanza(*l[k],*l[k+1]))
            return false;
   k++;
    }
return true;
}


bool Poligono::operator<(const Poligono& p) const{
    return (area()>p.area());
}
