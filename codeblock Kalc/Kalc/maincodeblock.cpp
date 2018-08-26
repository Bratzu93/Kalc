#include "../../Kalc/model/Punto.h"
#include "../../Kalc/model/base.h"
#include "../../Kalc/model/Poligono.h"
#include "../../Kalc/model/Poliedro.h"
#include "../../Kalc/model/segmento.h"
#include <iostream>
using namespace std;
int main()
{
Punto p(0,6);
Punto p1(5,6);
Punto p2(2,0);
Punto p3(0,0);
Punto p4(0,2);
Punto p5(2,2);
Base b;
b.add(p1);
b.add(p3);
b.add(p2);
b.add(p4);
b.stampa();
cout<<endl;
Segmento x(p,p1);
cout<<x.Punto_piu_vicino(p5);
}
