#include "newsegmento.h"

newSegmento::newSegmento(Controller *c, QWidget *parent):QWidget(parent),control(c)
{
    QHBoxLayout* form = new QHBoxLayout();
    QHBoxLayout* formXfirst = new QHBoxLayout;
    QHBoxLayout* formYfirst = new QHBoxLayout;
    QHBoxLayout* formXsecond = new QHBoxLayout;
    QHBoxLayout* formYsecond = new QHBoxLayout;
    QVBoxLayout* verticalFormFirst = new QVBoxLayout;
    QVBoxLayout* verticalFormSecond = new QVBoxLayout;
    QVBoxLayout* verticalFinal = new QVBoxLayout;
    QGridLayout* formFinal = new QGridLayout;


    QGroupBox* Group = new QGroupBox(tr("Creazione di un segmento"));

    QLabel* xFirst = new QLabel(tr("x: "));
    QLabel* yFirst = new QLabel(tr("y: "));
    QLabel* xSecond = new QLabel(tr("x: "));
    QLabel* ySecond = new QLabel(tr("y: "));
    QLabel* primo = new QLabel(tr("primo punto"));
    QLabel* secondo = new QLabel(tr("secondo punto"));

    xLineEditFirst = new QLineEdit();
    yLineEditFirst = new QLineEdit();
    xLineEditSecond = new QLineEdit();
    yLineEditSecond = new QLineEdit();

    QPushButton* salva = new QPushButton(tr("salva"));

    formXfirst->addWidget(xFirst);
    formXfirst->addWidget(xLineEditFirst);
    formYfirst->addWidget(yFirst);
    formYfirst->addWidget(yLineEditFirst);
    verticalFormFirst->addWidget(primo);
    verticalFormFirst->addLayout(formXfirst);
    verticalFormFirst->addLayout(formYfirst);

    formXsecond->addWidget(xSecond);
    formXsecond->addWidget(xLineEditSecond);
    formYsecond->addWidget(ySecond);
    formYsecond->addWidget(yLineEditSecond);
    verticalFormSecond->addWidget(secondo);
    verticalFormSecond->addLayout(formXsecond);
    verticalFormSecond->addLayout(formYsecond);

    form->addLayout(verticalFormFirst);
    form->addLayout(verticalFormSecond);
    verticalFinal->addLayout(form);
    verticalFinal->addWidget(salva);

    Group->setLayout(verticalFinal);
    formFinal->addWidget(Group);
    setLayout(formFinal);

    connect(salva,SIGNAL(clicked()),this,SLOT(save_item()));
}

void newSegmento::save_item(){
    Punto* first = new Punto(xLineEditFirst->text().toDouble(),yLineEditFirst->text().toDouble());
    Punto* second = new Punto(xLineEditSecond->text().toDouble(),yLineEditSecond->text().toDouble());
    control->newSegm(*first,*second);
xLineEditFirst->setText("");
yLineEditFirst->setText("");
xLineEditSecond->setText("");
yLineEditSecond->setText("");
    emit _salva();
}
