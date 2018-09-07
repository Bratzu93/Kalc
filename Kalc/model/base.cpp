#include "base.h"

Base::Base(){
   v = vector<Punto>() ;
}

Base::Base(const Base& B){
    for (unsigned int i=0; i<B.v.size(); ++i){
     Punto x = B.v[i];
        v.push_back(x);
    }
}

Base::~Base(){}

Base& Base::operator=(const Base& B){
    v=B.v;
  return *this;
}


vector<Punto> Base::get_vect()const{
    return v;
}

//void Base::set_vect(vector<Punto> B){
//v.clear();
//for(unsigned int i=0;i<B.size();++i){

//}
//}

Base& Base::append_vect(const Base& B){
v.insert(std::end(v), std::begin(B.v), std::end(B.v));
return *this;
}

void Base::add(const Punto& p){
    v.push_back(p);
}
void Base::add(Punto* p){
v.push_back(*p);
}


void Base::remove(const Punto& p){
    for(auto cit=v.begin();cit!=v.end();++cit){
        if ((*cit)== p){
            cit=v.erase(cit);
            cit--;
        }
    }

}

void Base::trasla_asseX(const double& _x){
    for(auto cit=v.begin();cit!=v.end();++cit){
(cit)->trasla_ascissa(_x);
    }
}

void Base::trasla_asseY(const double& _y){
    for(auto cit=v.begin();cit!=v.end();++cit){
(cit)->trasla_ordinata(_y);
    }
}


void Base::trasla(const double& _x,const double& _y){
    trasla_asseX(_x);
    if(_y!=0) trasla_asseY(_y);
}

void Base::stampa()const{
    for(auto cit=v.begin();cit!=v.end();++cit){
        (*cit).stampa();
    }
}
void Base::clear(){
    v.clear();
}

vector<Punto*> Base::convex_hull(Base &P){

    double n = P.v.size(), k = 0;

    bool allineati=true;
        if (n < 3) throw Poligono_con_meno_di_3_punti();
        for(int i=0;i<n && allineati;++i)
            for(int k=0;k<n && allineati;++k){
        if(Punto::angolo(P.v[0],P.v[i],P.v[k]))
            allineati=false;
        }
        if(allineati) throw Punti_allineati();

        vector<Punto*> H(2*n);
        sort(P.v.begin(), P.v.end());
         for (double i = 0; i < n; ++i) {
                 while (k >= 2 && Punto::angolo(*(H[k-2]), *(H[k-1]), P.v[i]) <= 0) k--;
                 H[k++] = &P.v[i];
             }

             // Build upper hull
             for (int i = n-1, t = k+1; i > 0; --i) {
                 while (k >= t && Punto::angolo(*(H[k-2]), *(H[k-1]), P.v[i-1]) <= 0) k--;
                 H[k++] = &P.v[i-1];
             }
             H.resize(k-1);
             return H;
}
