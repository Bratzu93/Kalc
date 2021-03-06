#ifndef BASE_H
#define BASE_H
#include "punto.h"
#include <vector>
#include<algorithm>
using std::vector;
using std::sort;

class Base : public Object
{
private:
    vector<Punto> v;
public:
    virtual ~Base();
    Base();
    Base(const Base&);
    Base& operator=(const Base&);
    vector<Punto> get_vect()const;
    void set_vect(Base);
    Base& append_vect(const Base&);
    void add(const Punto &);
    void add(Punto*);
    void remove(const Punto&);
    void clear();
    virtual void trasla_asseX(const double&);
    virtual void trasla_asseY(const double&);
    void trasla(const double& _x=0,const double& _y=0);
    //virtual void coppia_piu_vicina(); //Da Fare   stampa la coppia di punti con distanza minima tra le n combinazioni
    //cammino minimo
    static vector<Punto *> convex_hull(Base &P);
    virtual void stampa()const;
    std::string OutPunti()const;

};

#endif // BASE_H
