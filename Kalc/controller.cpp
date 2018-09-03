#include "controller.h"

Controller::Controller(){}

void Controller::newPunto(double x, double y) {
    Punto* l = new Punto(x,y);
    Controller::list.push_back(l);
}

std::string Controller::stampaPunto(const Punto& p)const{
    std::ostringstream strs;
    strs << "( " << p.get_x() << " , " << p.get_y() << " )";
    std::string str = strs.str();
    return str;
}

std::string Controller::stampaPoligono(const Poligono& p)const{
return p.OutPunti();
}


void Controller::newSegm(const Punto& first, const Punto& second) {
    Segmento* l = new Segmento(first,second);
    Controller::list.push_back(l);
}


int Controller::getVectorSize()const{
return list.size();
}

std::string Controller::getTypeElem(int i)const{
return typeid(*(list[i])).name();
}

bool Controller::AddtoPol(const Punto& p){
base.add(p);
if(base.get_vect().size()>2)
    return true;
else return false;
}

void Controller::newPoligono(){
Base* b = new Base(base);
Poligono* pol = new Poligono(*b);
Controller::list.push_back(pol);
base.clear();
}



Object* Controller::getElement(int i)const{
return list[i];
}
