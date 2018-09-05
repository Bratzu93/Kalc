#include "controller.h"

Controller::Controller(){
    op1=nullptr;
    op2=nullptr;
    poligon=nullptr;
}

void Controller::setOp1(int i){
    op1=list[i];
}

void Controller::setOp2(int i){
        op2=list[i];
}
std::string Controller::stampaOp1()const{
    return stampa(op1);
}
std::string Controller::stampaOp2()const{
    return stampa(op2);
}
void Controller::newPunto(double x, double y) {
    Punto* l = new Punto(x,y);
    Controller::list.push_back(l);
}

std::string Controller::stampa(Object *p) const{
    if(dynamic_cast<Punto*>(p)){
       Punto* point = static_cast<Punto*>(p);
       return stampaPunto(*point);
    } else if(dynamic_cast<Segmento*>(p)){
    Segmento* segm = static_cast<Segmento*>(p);
    return stampaSegmento(*segm);
    }else{
     Poligono* pol = static_cast<Poligono*>(p);
     return stampaPoligono(*pol);
    }
}
std::string Controller::stampaPunto(const Punto& p)const{
    std::ostringstream strs;
    strs << "( " << p.get_x() << " , " << p.get_y() << " )";
    std::string str = strs.str();
    return str;
}
std::string Controller::stampaSegmento(const Segmento& p)const{
    std::ostringstream strs;
    strs << "( " << p.get_firstPoint().get_x() << " , " << p.get_firstPoint().get_y() << " ) , ("
         << p.get_secondPoint().get_x()<<" , "<<p.get_secondPoint().get_y()<<" )";
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

void Controller::newObject(){
    Punto* p = dynamic_cast<Punto*>(res);
    Segmento* s = dynamic_cast<Segmento*>(res);
    Base* poli = dynamic_cast<Base*>(res);

    if(p) newPunto(p->get_x(),p->get_y());
    else if(s) newSegm(s->get_firstPoint(),s->get_secondPoint());
    else if(poli) {
        poligon = new Base(*poli);
        base=*poligon;
        newPoligono();
    }
}

Object* Controller::getElement(int i)const{
return list[i];
}

std::string Controller::Somma(){

   Punto* p1 = dynamic_cast<Punto*>(op1);
   Punto* p2 = dynamic_cast<Punto*>(op2);
   Segmento* s1 = dynamic_cast<Segmento*>(op1);
   Segmento* s2 = dynamic_cast<Segmento*>(op2);
   Poligono* pol1 = dynamic_cast<Poligono*>(op1);
   Poligono* pol2 = dynamic_cast<Poligono*>(op2);


//somma fra due punti
    if(p1&&p2){
        punto = *p1 + *p2;
        res = &punto;
    }else if(s1&&s2){       //somma fra due segmenti
        segmento = *s1 + *s2;
        res = &segmento;
    }else if(p1&&s2){       //somma fra punto e segmento
        segmento = *p1 + *s2;
        res = &segmento;
    }else if(p2&&s1){       //somma fra segmento e punto
        segmento = *s1+*p2;
        res = &segmento;
    }else if(pol1&&pol2){   //somma fra poligoni
        poligono = *pol1 + *pol2;
        res = &poligono;
    } //fare somma fra altro


return stampa(res);
}
