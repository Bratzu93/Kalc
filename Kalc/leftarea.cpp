#include "leftarea.h"

LeftArea::LeftArea(Controller *c, QWidget *parent):QWidget(parent),control(c){

   struttura = new QVBoxLayout;
   _struttura = new QVBoxLayout;

    group = new QGroupBox(tr("Oggetti"),this);
    list = new QListWidget(group);
    dettagli = new Dettagli(control);
    tab = new QTabWidget(group);
    _creazione = new Creazione(control);
    tab->addTab(_creazione,"Crea");
    tab->addTab(dettagli,"Dettagli");

    struttura->addWidget(list,2);
    struttura->addWidget(tab,1);
    group->setLayout(struttura);
    _struttura->addWidget(group);
    setLayout(_struttura);

connect(list, SIGNAL(itemSelectionChanged()), this,SLOT(selected()));
connect(_creazione, SIGNAL(AddItem()), this, SLOT(itemAdded()));
}


void LeftArea::itemAdded(){
delete list;
    list=new QListWidget(group);
    connect(list, SIGNAL(itemSelectionChanged()), this,SLOT(selected()));
    connect(list, SIGNAL(itemClicked(QListWidgetItem*)), this,SLOT(selected()));
    connect(list, SIGNAL(currentRowChanged(int)), dettagli,SLOT(AggiornaDettagli(int)));
for(int i=0;i<control->getVectorSize();++i){
    list->addItem( QString::fromStdString(control->getTypeElem(i)) + " " + QString::number(i) );
struttura->removeWidget(tab);
struttura->addWidget(list,2);
struttura->addWidget(tab,1);
    }
}

void LeftArea::selected(){
    tab->setCurrentIndex(1);
}
