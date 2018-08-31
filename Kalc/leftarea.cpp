#include "leftarea.h"

LeftArea::LeftArea(Controller *c, QWidget *parent):QWidget(parent),control(c){

   struttura = new QVBoxLayout;
   _struttura = new QVBoxLayout;

    group = new QGroupBox(tr("Oggetti"),this);
    l = new QListWidget(group);
    dettagli = new QGroupBox(group);
    tab = new QTabWidget(group);
    _creazione = new Creazione(control);
    tab->addTab(_creazione,"crea");
    tab->addTab(dettagli,"Dettagli");

    struttura->addWidget(l,1);
    struttura->addWidget(tab,3);
    group->setLayout(struttura);
    _struttura->addWidget(group);
    setLayout(_struttura);


connect(_creazione, SIGNAL(_salva()), this, SLOT(itemAdded()));
}


void LeftArea::itemAdded(){
delete l;
    l=new QListWidget(group);
for(int i=0;i<control->getVectorSize();++i){
    l->addItem( control->getTypeElem(i) + " " + QString::number(i) );
struttura->removeWidget(tab);
struttura->addWidget(l,1);
struttura->addWidget(tab,3);
}


}
