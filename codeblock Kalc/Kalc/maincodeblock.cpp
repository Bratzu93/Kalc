#include "../../Kalc/model/Punto.h"
#include "../../Kalc/model/base.h"
#include "../../Kalc/model/Poligono.h"
#include "../../Kalc/model/segmento.h"
#include <iostream>
using namespace std;
int main()
{
Punto p(0,0);
Punto p1(0,2);
Punto p2(2,0);
Punto p3(2,4);
Punto p4(-1,-1);
Punto p5(3,3);
Punto p6(-8,-8);
Base b;
b.add(p);
b.add(p1);
b.add(p2);
b.add(p3);
Base b2;
b2.add(p);
b2.add(p3);
b2.add(p6);
cout<<endl;
Poligono pol1(b);
Poligono pol2(b2);
pol1.stampa();
cout<<endl;
pol2.stampa();
Poligono pol3(pol1+pol2);
cout<<endl;
pol3.stampa();
}
