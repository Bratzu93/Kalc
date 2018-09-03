#include "newpoligono.h"

newPoligono::newPoligono(Controller *c, QWidget *parent):QWidget(parent),control(c)
{
    list = new QListWidget;
    xLineEditfirst = new QLineEdit();
    yLineEditfirst = new QLineEdit();
    QPushButton* salva = new QPushButton(tr("Aggiungi Punto"));
    crea = new QPushButton(tr("Crea Poligono"));
    crea->setEnabled(false);

    QVBoxLayout* Verticalform = new QVBoxLayout();
    QHBoxLayout* formX = new QHBoxLayout;
    QHBoxLayout* formY = new QHBoxLayout;
    QGridLayout* formFinal = new QGridLayout;
    QHBoxLayout* form = new QHBoxLayout;

    QGroupBox* Group = new QGroupBox(tr("Creazione di un Poligono"));
    QLabel* xFirst = new QLabel(tr("x: "));
    QLabel* yFirst = new QLabel(tr("y: "));

    xLineEditfirst = new QLineEdit();
    yLineEditfirst = new QLineEdit();

    formX->addWidget(xFirst);
    formX->addWidget(xLineEditfirst);
    formY->addWidget(yFirst);
    formY->addWidget(yLineEditfirst);

    Verticalform->addLayout(formX);
    Verticalform->addLayout(formY);
    Verticalform->addWidget(salva);
    Verticalform->addWidget(crea);

    form->addLayout(Verticalform);
    form->addWidget(list);
    Group->setLayout(form);
    formFinal->addWidget(Group);
    setLayout(formFinal);



    connect(salva,SIGNAL(clicked(bool)),this,SLOT(AddtoPoligono()));
    connect(crea,SIGNAL(clicked()),this,SLOT(save_item()));
}

void newPoligono::AddtoPoligono(){
    Punto p(xLineEditfirst->text().toDouble(),yLineEditfirst->text().toDouble());
xLineEditfirst->setText("");
yLineEditfirst->setText("");
if(control->AddtoPol(p))
    crea->setEnabled(true);
list->addItem(QString::fromStdString(control->stampaPunto(p)));
}

void newPoligono::save_item(){
//      bisogna prendere la list di listWidget e passarla al control per creare la base
//    control->newPoligono(xLineEditfirst->text().toDouble(),yLineEditfirst->text().toDouble());
control->newPoligono();
    list->clear();
    emit _salva();
}
