#include "controller.h"

Controller::Controller(){
    op1=nullptr;
    op2=nullptr;
    res=nullptr;
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
std::string Controller::stampaResult()const{
    return stampa(res);
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
    Poligono* poli = dynamic_cast<Poligono*>(res);

    if(p) newPunto(p->get_x(),p->get_y());
    else if(s) newSegm(s->get_firstPoint(),s->get_secondPoint());
    else if(poli) {
        for(unsigned int i=0; i<poli->get_vect().size();++i)
            AddtoPol(poli->PointfromPoligon(i));
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

    if(p1&&p2){             //somma fra due punti
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
    }else if(p1&&pol2){     //somma fra punto e poligono
        poligono= *pol2 + *p1;
        res=&poligono;
    }else if(p2&&pol1){     //somma fra poligono e punto
        poligono= *pol1 + *p2;
        res=&poligono;
    }else if(s1&&pol2){     //somma fra segmento e poligono
        poligono= *pol2 + *s1;
        res=&poligono;
    }else if(s2&&pol1){     //somma fra poligono e segmento
        poligono= *pol1 + *s2;
        res=&poligono;
    }
return stampa(res);
}

std::string Controller::Differenza(){
   Punto* p1 = dynamic_cast<Punto*>(op1);
   Punto* p2 = dynamic_cast<Punto*>(op2);
   Segmento* s1 = dynamic_cast<Segmento*>(op1);
   Segmento* s2 = dynamic_cast<Segmento*>(op2);
   Poligono* pol1 = dynamic_cast<Poligono*>(op1);
   Poligono* pol2 = dynamic_cast<Poligono*>(op2);

    if(p1&&p2){             //differenza fra due punti
        punto = *p1 - *p2;
        res = &punto;
    }else if(s1&&s2){       //differenza fra due segmenti
        segmento = *s1 - *s2;
        res = &segmento;
    }else if(p1&&s2){       //differenza fra punto e segmento
        segmento = *p1 - *s2;
        res = &segmento;
    }else if(p2&&s1){       //differenza fra segmento e punto
        segmento = *s1 - *p2;
        res = &segmento;
    }else if(pol1&&pol2){   //differenza fra poligoni
        poligono = *pol1 - *pol2;
        res = &poligono;
    }else if(p1&&pol2){     //differenza fra punto e poligono
        poligono= *pol2 - *p1;
        res=&poligono;
    }else if(p2&&pol1){     //differenza fra poligono e punto
        poligono= *pol1 - *p2;
        res=&poligono;
    }else if(s1&&pol2){     //differenza fra segmento e poligono
        poligono= *pol2 - *s1;
        res=&poligono;
    }else if(s2&&pol1){     //differenza fra poligono e segmento
        poligono= *pol1 - *s2;
        res=&poligono;
    }
return stampa(res);
}

std::string Controller::Moltiplicazione(){
   Punto* p1 = dynamic_cast<Punto*>(op1);
   Punto* p2 = dynamic_cast<Punto*>(op2);
   Segmento* s1 = dynamic_cast<Segmento*>(op1);
   Segmento* s2 = dynamic_cast<Segmento*>(op2);
   Poligono* pol1 = dynamic_cast<Poligono*>(op1);
   Poligono* pol2 = dynamic_cast<Poligono*>(op2);

    if(p1&&p2){             //moltiplicazione fra due punti
        punto = *p1 * *p2;
        res = &punto;
    }else if(s1&&s2){       //moltiplicazione fra due segmenti
        segmento = *s1 * *s2;
        res = &segmento;
    }else if(p1&&s2){       //moltiplicazione fra punto e segmento
        segmento = *p1 * *s2;
        res = &segmento;
    }else if(p2&&s1){       //moltiplicazione fra segmento e punto
        segmento = *s1 * *p2;
        res = &segmento;
    }else if(pol1&&pol2){   //moltiplicazione fra poligoni
        poligono = *pol1 * *pol2;
        res = &poligono;
    }else if(p1&&pol2){     //moltiplicazione fra punto e poligono
        poligono= *pol2 * *p1;
        res=&poligono;
    }else if(p2&&pol1){     //moltiplicazione fra poligono e punto
        poligono= *pol1 * *p2;
        res=&poligono;
    }else if(s1&&pol2){     //moltiplicazione fra segmento e poligono
        poligono= *pol2 * *s1;
        res=&poligono;
    }else if(s2&&pol1){     //moltiplicazione fra poligono e segmento
        poligono= *pol1 * *s2;
        res=&poligono;
    }
return stampa(res);
}

std::string Controller::Divisione(){
   Punto* p1 = dynamic_cast<Punto*>(op1);
   Punto* p2 = dynamic_cast<Punto*>(op2);
   Segmento* s1 = dynamic_cast<Segmento*>(op1);
   Segmento* s2 = dynamic_cast<Segmento*>(op2);
   Poligono* pol1 = dynamic_cast<Poligono*>(op1);
   Poligono* pol2 = dynamic_cast<Poligono*>(op2);

    if(p1&&p2){             //divisione fra due punti
        punto = *p1 / *p2;
        res = &punto;
    }else if(s1&&s2){       //divisione fra due segmenti
        segmento = *s1 / *s2;
        res = &segmento;
    }else if(p1&&s2){       //divisione fra punto e segmento
        segmento = *p1 / *s2;
        res = &segmento;
    }else if(p2&&s1){       //divisione fra segmento e punto
        segmento = *s1 / *p2;
        res = &segmento;
    }else if(pol1&&pol2){   //divisione fra poligoni
        poligono = *pol1 / *pol2;
        res = &poligono;
    }else if(p1&&pol2){     //divisione fra punto e poligono
        poligono= *pol2 / *p1;
        res=&poligono;
    }else if(p2&&pol1){     //divisione fra poligono e punto
        poligono= *pol1 / *p2;
        res=&poligono;
    }else if(s1&&pol2){     //divisione fra segmento e poligono
        poligono= *pol2 / *s1;
        res=&poligono;
    }else if(s2&&pol1){     //divisione fra poligono e segmento
        poligono= *pol1 / *s2;
        res=&poligono;
    }
return stampa(res);
}
