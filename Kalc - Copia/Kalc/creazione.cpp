#include "creazione.h"

Creazione::Creazione(Controller *controller, QWidget *parent):QWidget(parent),control(controller){

    creazione = new QHBoxLayout();
    newpoint = new newPoint(control);
    newsegm = new newSegmento(control);
    new_poligono = new newPoligono(control);

    creazione->addWidget(newpoint);
    creazione->addWidget(newsegm);
    creazione->addWidget(new_poligono);

    setLayout(creazione);

connect(newpoint,SIGNAL(_salva()),this,SIGNAL(AddItem()));
connect(newsegm,SIGNAL(_salva()),this,SIGNAL(AddItem()));
connect(new_poligono,SIGNAL(_salva()),this,SIGNAL(AddItem()));

}

