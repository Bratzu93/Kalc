#include "newpoliedro.h"

newPoliedro::newPoliedro(Controller *c, QWidget *parent):QWidget(parent),control(c)
{
    QGridLayout* form = new QGridLayout();
    QHBoxLayout* formX = new QHBoxLayout;
    QHBoxLayout* formY = new QHBoxLayout;
    QGridLayout* formFinal = new QGridLayout;

    QGroupBox* Group = new QGroupBox(tr("Creazione di un Poliedro"));
    altezza = new QLineEdit();
    list = new QListWidget;
//    for(int i=0;i<control->getVectorSize();++i)
//        list->addItem(control->PoligonoList(i));
    QPushButton* salva = new QPushButton(tr("salva"));

//    formX->addWidget(xFirst);
//    formX->addWidget(xLineEditfirst);
//    formY->addWidget(yFirst);
//    formY->addWidget(yLineEditfirst);

    form->addLayout(formX,0,0);
    form->addLayout(formY,1,0);
    form->addWidget(salva,2,0);
    Group->setLayout(form);
    formFinal->addWidget(Group);
    setLayout(formFinal);

    connect(salva,SIGNAL(clicked()),this,SLOT(save_item()));
}

void newPoliedro::save_item(){
//control->newPoliedro(altezza->text().toDouble(),list->selectedItems());
//altezza->setText("");
//list.selected(false)
//emit _salva();
}
