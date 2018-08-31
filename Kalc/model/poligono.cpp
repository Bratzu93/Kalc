#include "Poligono.h"

Poligono::Poligono(Base& B):Base(B){
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

//Poligono::~Poligono(){
//    for(auto it=l.begin();it!=l.end();++it){
//        delete *it;
//        it=l.erase(it);
//        it--;
//    }
//}

//void Poligono::trasla(const double &_x, const double &_y){
//    // da fare
//}

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
    return (area()<p.area());
}

bool Poligono::operator>(const Poligono& p) const{
    return (area()>p.area());
}

bool Poligono::operator==(const Poligono& p)const{
return (area()==p.area());
}

bool Poligono::operator!=(const Poligono& p)const{
return (area()!=p.area());
}

Poligono& Poligono::operator+(const Poligono& p){
Poligono aux(append_vect(p));
*this=aux;
return *this;
}

double Poligono::operator-(const Poligono& p)const{
return area()-p.area();
}


bool Poligono::interno (const Punto& p) const{

   unsigned short intersections = 0;
   for ( auto it = l.begin(); it != l.end(); it++ ) {
      Punto p1 = **it;
      Punto p2;
      if ( it + 1 != l.end() )
         p2 = **(it + 1);
      else
         p2 = **(l.begin());

      if ( ( p.get_x() < p1.get_x() && p.get_x() < p2.get_x() ) ||
           ( p.get_x() > p1.get_x() && p.get_x() > p2.get_x() ) )
               continue;
      double y_int = p1.get_y() + ( p2.get_y() - p1.get_y() ) * ( p.get_x() - p1.get_x()) / ( p2.get_x() - p1.get_x() );
      if ( p.get_y() <= y_int  )
         intersections++;
   }
   if ( intersections % 2 )
      return true;
   else
      return false;
}

Punto Poligono::Punto_piu_vicino(const Punto& p)const{
    if(interno(p))return p;
    Punto x;
    double k=1;
    double distanza_minima;
    while(k<l.size()){
    Segmento s(*l[k-1],*l[k]);
    if(k==1){
        x=s.Punto_piu_vicino(p);
        distanza_minima = Punto::distanza(p,s.Punto_piu_vicino(p));
    }
    if(Punto::distanza(p,s.Punto_piu_vicino(p))<= distanza_minima)
    x=s.Punto_piu_vicino(p);
    ++k;
        }
    Segmento s(*l[0],*l[l.size()]);
    if(Punto::distanza(p,s.Punto_piu_vicino(p))<= distanza_minima)
    x=s.Punto_piu_vicino(p);
return x;
}
