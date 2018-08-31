#include "../../Kalc/model/Punto.h"
#include "../../Kalc/model/base.h"
#include "../../Kalc/model/Poligono.h"
#include "../../Kalc/model/Poliedro.h"
#include "../../Kalc/model/segmento.h"
#include <iostream>
using namespace std;
int main()
{
Punto p(0,0);
Punto p1(0,2);
Punto p2(2,0);
Punto p3(2,2);
Punto p4(1,1);
Punto p5(3,3);
Base b;
b.add(p);
b.add(p1);
b.add(p2);
b.add(p3);
b.stampa();
cout<<endl;
Poligono pol(b);
pol.stampa();
cout<<endl;
Segmento s(p,p1);
cout<<pol.Punto_piu_vicino(p4);
}
