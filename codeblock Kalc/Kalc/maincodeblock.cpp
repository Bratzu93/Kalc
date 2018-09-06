#include "../../Kalc/model/Punto.h"
#include "../../Kalc/model/base.h"
#include "../../Kalc/model/Poligono.h"
#include "../../Kalc/model/segmento.h"
#include "../../Kalc/model/object.h"
#include "../../Kalc/controller.h"
#include <iostream>
using namespace std;
int main()
{
Controller* control = new Controller;
Punto p(0,0);
Punto p1(5,5);
Punto p2(0,5);
Punto p3(5,0);
Punto p4(3,3);
Punto p5(6,6);
Punto p6(-8,-8);
Base b;
b.add(p);
b.add(p1);
b.add(p2);
b.add(p3);

b.stampa();
cout<<endl;
b.trasla(2,2);
b.stampa();
cout<<endl;
Poligono pol1(b);
pol1.stampa();
cout<<endl;
pol1.trasla(3,3);
pol1.stampa();
/*
control->newPunto(p1.get_x(),p1.get_y());
control->newSegm(p,p1);
control->AddtoPol(p);
control->AddtoPol(p1);
control->AddtoPol(p2);
control->AddtoPol(p3);
control->newPoligono();
control->newSegm(p4,p5);
control->setOp1(2);
control->setOp2(3);
cout<<control->Somma();
control->stampaResult();
control->newObject();
*/
}
