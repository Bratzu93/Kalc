#include "newpoint.h"

newPoint::newPoint(Controller *c, QWidget *parent):QWidget(parent),control(c)
{
    QGridLayout* form = new QGridLayout();
    QHBoxLayout* formX = new QHBoxLayout;
    QHBoxLayout* formY = new QHBoxLayout;
    QGridLayout* formFinal = new QGridLayout;

    QGroupBox* Group = new QGroupBox(tr("Creazione di un punto"));
    QLabel* xFirst = new QLabel(tr("x: "));
    QLabel* yFirst = new QLabel(tr("y: "));

    xLineEditfirst = new QLineEdit();
    yLineEditfirst = new QLineEdit();
    QPushButton* salva = new QPushButton(tr("salva"));
    salva->setAutoDefault(true);

    formX->addWidget(xFirst);
    formX->addWidget(xLineEditfirst);
    formY->addWidget(yFirst);
    formY->addWidget(yLineEditfirst);

    form->addLayout(formX,0,0);
    form->addLayout(formY,1,0);
    form->addWidget(salva,2,0);
    Group->setLayout(form);
    formFinal->addWidget(Group);
    setLayout(formFinal);

    connect(salva,SIGNAL(clicked()),this,SLOT(save_item()));
}

void newPoint::save_item(){
control->newPunto(xLineEditfirst->text().toDouble(),yLineEditfirst->text().toDouble());
xLineEditfirst->setText("");
yLineEditfirst->setText("");
emit _salva();
}
