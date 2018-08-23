#include "base.h"

Base::Base(){}

Base::~Base(){
    for(auto it=v.begin();it!=v.end();++it){
        delete *it;
        it=v.erase(it);
        it--;
    }
}
Base& Base::operator=(const Base& B){
    if(v==B.v)
        return *this;
    else
    v=B.v;
    return *this;
}

vector<const Punto*> Base::get_vect()const{
    return v;
}

void Base::add(const Punto& p){
    v.push_back(&p);
}


void Base::remove(const Punto& p){
    for(auto cit=v.begin();cit!=v.end();++cit){
        if ((**cit)== p){
            delete (*cit);
            cit=v.erase(cit);
            cit--;
        }
    }

}

void Base::trasla_asseX(const double& _x){
    for(auto cit=v.begin();cit!=v.end();++cit){
(const_cast<Punto*>(*cit))->trasla_ascissa(_x);
    }
}

void Base::trasla_asseY(const double& _y){
    for(auto cit=v.begin();cit!=v.end();++cit){
(const_cast<Punto*>(*cit))->trasla_ordinata(_y);
    }
}


void Base::trasla(const double& _x,const double& _y){
    trasla_asseX(_x);
    if(_y!=0) trasla_asseY(_y);
}

void Base::stampa()const{
    for(auto cit=v.begin();cit!=v.end();++cit){
        (**cit).stampa();
    }
}


vector<const Punto*> Base::convex_hull(const Base& P){

    double n = P.v.size(), k = 0;
        if (n < 3) return std::vector<const Punto*>() ;
        vector<const Punto*> H(2*n);
        Base aux = const_cast<Base&>(P);
        sort(aux.v.begin(), aux.v.end());

         for (double i = 0; i < n; ++i) {
                 while (k >= 2 && Punto::angolo(H[k-2], H[k-1], aux.v[i]) <= 0) k--;
                 H[k++] = aux.v[i];
             }

             // Build upper hull
             for (size_t i = n-1, t = k+1; i > 0; --i) {
                 while (k >= t && Punto::angolo(H[k-2], H[k-1], aux.v[i-1]) <= 0) k--;
                 H[k++] = aux.v[i-1];
             }

             H.resize(k-1);
             return H;
}
