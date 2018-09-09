#include "controller.h"

Controller::Controller(){
    op1=nullptr;
    op2=nullptr;
    res=nullptr;
    base.clear();
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

std::string Controller::stampa(const Object *p) const{
    return p->OutPunti();
}

std::string Controller::IsEquilatero(const Poligono& pol)const{
if(pol.equilatero()) return std::string("Poligono equilatero");
else return std::string("Poligono non equilatero");
}

void Controller::clearBase(){
    base.clear();
}

int Controller::getVectorSize()const{
return list.size();
}

std::string Controller::getTypeElem(int i)const{
return typeid(*(list[i])).name();
}

bool Controller::AddtoPol(Punto p){
    Punto* point = new Punto(p);
    base.add(point);
if(base.get_vect().size()>2)
    return true;
else return false;
}

void Controller::newPunto(double x, double y) {
    Punto* l = new Punto(x,y);
    Controller::list.push_back(l);
}

void Controller::newSegm(const Punto& first, const Punto& second) {
    Segmento* l = new Segmento(first,second);
    Controller::list.push_back(l);
}

void Controller::newPoligono(){
        Controller::list.push_back(new Poligono(base));
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
        try{newPoligono();}catch(Punti_allineati){}
        catch(Poligono_con_meno_di_3_punti){}
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
void Controller::Trasla(const double& x, const double& y){
op1->trasla(x,y);
}
std::string Controller::Punto_piu_vicino(){
    Punto* point;
    if(!(dynamic_cast<Punto*>(op1))) throw PuntoExep();
    else point = static_cast<Punto*>(op1);
    if(dynamic_cast<Punto*>(op2)){
        res=op1;
        return stampa(res);
    }
        if(dynamic_cast<Segmento*>(op2)){
       punto = (static_cast<Segmento*>(op2))->Punto_piu_vicino(*point);
        res=&punto;
    }else if(dynamic_cast<Poligono*>(op2)){
         punto = (static_cast<Poligono*>(op2))->Punto_piu_vicino(*point);
         res=&punto;
    }
return stampa(res);
}

std::string Controller::Interno(){
    if(dynamic_cast<Poligono*>(op2) && dynamic_cast<Punto*>(op1)){
        Punto* point = static_cast<Punto*>(op1);
        Poligono* polygon = static_cast<Poligono*>(op2);
        if(polygon->interno(*point)) return std::string("il punto è interno al poligono");
            else return std::string("il punto è esterno al poligono");
    }else if(dynamic_cast<Poligono*>(op1) && dynamic_cast<Punto*>(op2)){
        Punto* point = static_cast<Punto*>(op2);
        Poligono* polygon = static_cast<Poligono*>(op1);
        if(polygon->interno(*point)) return std::string("il punto è interno al poligono");
            else return std::string("il punto è esterno al poligono");
    }
    else throw PoligonoInternoExep();

}

double Controller::SommaSegmenti(){
    double distanza=0;
    for(unsigned int i=0;i<list.size();++i){
        if(dynamic_cast<Segmento*>(list[i]))
            distanza += static_cast<Segmento*>(list[i])->lunghezza();
    }
    return distanza;
}







