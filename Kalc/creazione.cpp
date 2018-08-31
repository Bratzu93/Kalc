#include "creazione.h"

Creazione::Creazione(Controller *controller, QWidget *parent):QWidget(parent),control(controller){

    creazione = new QGridLayout();
    QGridLayout* form = new QGridLayout;
    QGridLayout* form2 = new QGridLayout;
    QGridLayout* form3 = new QGridLayout;
    QGridLayout* form4 = new QGridLayout;
    QGroupBox* PointGroup = new QGroupBox;
    QGroupBox* SegmGroup = new QGroupBox;
    QGroupBox* PoligGroup = new QGroupBox;
    QGroupBox* PolieGroup = new QGroupBox;


    xLabel = new QLabel(tr("x: "));
    yLabel = new QLabel(tr("y: "));
    xLineEdit = new QLineEdit();
    yLineEdit = new QLineEdit();
    salva = new QPushButton(tr("salva"));

    form->addWidget(xLabel,0,0);
    form->addWidget(xLineEdit,0,1);
    form->addWidget(yLabel,1,0);
    form->addWidget(yLineEdit,1,1);
    form->addWidget(salva);
    PointGroup->setLayout(form);

    form2->addWidget(new QLabel(tr("x: ")),0,0);
    form2->addWidget(new QLineEdit(),0,1);
    form2->addWidget(new QLabel(tr("y: ")),1,0);
    form2->addWidget(new QLineEdit(),1,1);
    form2->addWidget(new QPushButton(tr("salva")));
    SegmGroup->setLayout(form2);

    form3->addWidget(new QLabel(tr("x: ")),0,0);
    form3->addWidget(new QLineEdit(),0,1);
    form3->addWidget(new QLabel(tr("y: ")),1,0);
    form3->addWidget(new QLineEdit(),1,1);
    form3->addWidget(new QPushButton(tr("salva")));
    PoligGroup->setLayout(form3);

    form4->addWidget(new QLabel(tr("x: ")),0,0);
    form4->addWidget(new QLineEdit(),0,1);
    form4->addWidget(new QLabel(tr("y: ")),1,0);
    form4->addWidget(new QLineEdit(),1,1);
    form4->addWidget(new QPushButton(tr("salva")));
    PolieGroup->setLayout(form4);


    creazione->addWidget(PointGroup,0,0);
    creazione->addWidget(SegmGroup,0,1);
    creazione->addWidget(PoligGroup,1,0);
    creazione->addWidget(PolieGroup,1,1);

    setLayout(creazione);
    connect(salva,SIGNAL(clicked()),this,SLOT(save_item()));
}

void Creazione::save_item(){
control->newPunto(xLabel->text().toDouble(),yLabel->text().toDouble());
    emit _salva();
}
