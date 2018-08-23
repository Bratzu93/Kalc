#ifndef BASE_H
#define BASE_H
#include "Punto.h"
#include <vector>
#include<algorithm>
using std::vector;
using std::sort;

class Base
{
private:
    vector<const Punto*> v;
public:
    virtual ~Base();
    Base();
    Base& operator=(const Base&);
    vector<const Punto*> get_vect()const;
    void add(const Punto&);
    void remove(const Punto&);
    virtual void trasla_asseX(const double&);
    virtual void trasla_asseY(const double&);
    virtual void trasla(const double& _x,const double& _y=0);
    //virtual void rotea(const double& gradi);
    //virtual void coppia_piu_vicina(); //Da Fare   stampa la coppia di punti con distanza minima tra le n combinazioni
    static vector<const Punto*> convex_hull(const Base& P);
    virtual void stampa()const;
};

#endif // BASE_H
