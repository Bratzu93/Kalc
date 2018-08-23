#include "../../Kalc/model/Punto.h"
#include "../../Kalc/model/base.h"
#include "../../Kalc/model/Poligono.h"
#include "../../Kalc/model/Poliedro.h"
#include <iostream>
using namespace std;
int main()
{
Punto p(1,1);
Punto p1(2,2);
Punto p2(2,0);
Punto p3(0,0);
Punto p4(0,2);
Base b;
b.add(p);
b.add(p1);
b.add(p2);
b.add(p3);
b.add(p4);
vector<const Punto*> x = Base::convex_hull(b);
for(auto cit=x.begin();cit!=x.end();++cit){
        (**cit).stampa();
    }
}
