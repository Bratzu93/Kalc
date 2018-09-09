#include "Poligono.h"

Poligono::Poligono(const Base& B):Base(B){
    l = Base::convex_hull(*this);
}
Poligono::Poligono(){}

Poligono::Poligono(const Poligono& p):Base(p){
l=Base::convex_hull(*this);
}

Poligono& Poligono::operator=(const Poligono& p){
    if(l==p.l)
        return *this;
    else
    l=p.l;
    return *this;
}

vector<Punto*> Poligono::get_vect()const{
    return l;
}
std::string Poligono::OutPunti()const{
std::ostringstream strs;
    for(auto it=l.begin(); it!=l.end();++it)
    strs << **it;
std::string str = strs.str();
return str;
}

Punto Poligono::PointfromPoligon(int i)const{
return *l[i];
}
Poligono::~Poligono(){}

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
    area+= ((*l[n-1]).get_x() * (*l[0]).get_y()) - ((*l[n-1]).get_y() * (*l[0]).get_x());
    return area/2;
}

double Poligono::perimetro()const{
    double perimetro=0;
    double n = l.size();
    for(int k=0;k<n-1;k++){
        perimetro +=  Punto::distanza(*l[k],*l[k+1]);
    }
    perimetro+= Punto::distanza(*l[0],*l[n-1]);
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

void Poligono::trasla(const double& _x,const double& _y){
for(unsigned int i=0;i<l.size();++i)
    (*l[i]).trasla(_x,_y);
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

Poligono operator+(const Poligono& pol1, const Poligono& pol2){
Base aux(pol1);
aux.append_vect(pol2);
Poligono* aus = new Poligono(aux);
return *aus;
}

Poligono operator +(const Poligono& pol, const Punto& p){
Base aux(pol);
aux.add(p);
Poligono* aus =new Poligono(aux);
return *aus;
}

Poligono operator +(const Poligono& pol, const Segmento& s){
Base aux(pol);
aux.add(s.get_firstPoint());
aux.add(s.get_secondPoint());
Poligono* aus =new Poligono(aux);
return *aus;
}


Poligono operator-(const Poligono& pol1, const Poligono& pol2){
    Base aux;
    if(pol1.l.size()>pol2.l.size()){
        for(unsigned int i=0; i<pol2.l.size();++i)
            if(*pol1.l[i] != *pol2.l[i])
            aux.add(*pol1.l[i] - *pol2.l[i]);
        for(unsigned int i=pol2.l.size();i<pol1.l.size();++i)
            aux.add(*pol1.l[i]);
    }else{
        for(unsigned int i=0; i<pol1.l.size();++i)
            if(*pol1.l[i] != *pol2.l[i])
            aux.add(*pol2.l[i] - *pol1.l[i]);
        for(unsigned int i=pol1.l.size();i<pol2.l.size();++i)
            aux.add(*pol2.l[i]);
    }
    Poligono* aus =new Poligono(aux);
    return *aus;
}

Poligono operator -(const Poligono& pol, const Punto& p){
Base aux(pol);
aux.remove(p);
Poligono* aus =new Poligono(aux);
return *aus;
}

Poligono operator -(const Poligono& pol, const Segmento& s){
Base aux(pol);
aux.remove(s.get_firstPoint());
aux.remove(s.get_secondPoint());
Poligono* aus =new Poligono(aux);
return *aus;
}

Poligono operator*(const Poligono& pol1, const Poligono& pol2){
    Base aux;
    if(pol1.l.size()>pol2.l.size()){
        for(unsigned int i=0; i<pol2.l.size();++i)
            aux.add(*pol1.l[i] * *pol2.l[i]);
    }else{
        for(unsigned int i=0; i<pol1.l.size();++i)
            aux.add((*pol2.l[i]) * (*pol1.l[i]));
    }
    Poligono* aus =new Poligono(aux);
    return *aus;
}

Poligono operator *(const Poligono& pol, const Punto& p){
Punto test(0,0);
Base aux;
    if(p==test && pol.l.size()>2)return pol;
for(unsigned int i=0; i<pol.l.size();++i){
    aux.add(*pol.l[i] * p);
}
Poligono* aus =new Poligono(aux);
return *aus;
}


Poligono operator *(const Poligono& pol, const Segmento& s){
Base aux;
int dist = s.lunghezza();
if(dist==0) return pol;
for(unsigned int i=0; i<pol.l.size();++i){
        aux.add(*pol.l[i] * dist);
}
Poligono*aus = new Poligono(aux);
return *aus;
}

Poligono operator/(const Poligono& pol1, const Poligono& pol2){
    Base aux;
    if(pol1.l.size()>pol2.l.size()){
        for(unsigned int i=0; i<pol2.l.size();++i)
            aux.add(*pol1.l[i] / *pol2.l[i]);
    }else{
        for(unsigned int i=0; i<pol1.l.size();++i)
            aux.add(*pol2.l[i] / *pol1.l[i]);
    }
    Poligono* aus =new Poligono(aux);
    return *aus;
}

Poligono operator /(const Poligono& pol, const Punto& p){
Base aux;
for(unsigned int i=0; i<pol.l.size();++i){
    aux.add(*pol.l[i] / p);
    }
Poligono* aus =new Poligono(aux);
return *aus;
}

Poligono operator /(const Poligono& pol, const Segmento& s){
Base aux;
int dist = s.lunghezza();
if(dist==0) throw DivisionePerZero();
for(unsigned int i=0; i<pol.l.size();++i){
    Punto x(pol.l[i]->get_x()/dist,pol.l[i]->get_y()/dist);
    aux.add(x);
}
Poligono* aus =new Poligono(aux);
return *aus;
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


