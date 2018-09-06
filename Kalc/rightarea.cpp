#include "rightarea.h"

RightArea::RightArea(Controller *c, QWidget *parent):QWidget(parent),control(c)
{

    struttura = new QGridLayout;
    group = new QGroupBox(tr("Operazioni"));

    QVBoxLayout* FirstLayout = new QVBoxLayout;
    QVBoxLayout* SecondLayout = new QVBoxLayout;
    QHBoxLayout* OpLayout = new QHBoxLayout;
    QGridLayout* ResultLayout = new QGridLayout;
    QVBoxLayout* itemsLayout = new QVBoxLayout;
    QGridLayout* operatori = new QGridLayout;
    QHBoxLayout* funzioni = new QHBoxLayout;

    QLabel* _addFirst = new QLabel(tr("primo"));
    QLabel* _addSecond = new QLabel(tr("secondo"));

    first = new QLineEdit;
    second= new QLineEdit;
    risultato = new QLineEdit;
    first->setEnabled(false);
    second->setEnabled(false);
    risultato->setEnabled(false);

    addFirst = new QPushButton(tr("Add"));
    addSecond = new QPushButton(tr("Add"));
    Save = new QPushButton(tr("salva"));
    Clear = new QPushButton(tr("Clear"));
    addFirst->setEnabled(false);
    addSecond->setEnabled(false);
    Save->setEnabled(false);
    Clear->setEnabled(false);

    somma = new QPushButton(tr("+"));
    diff = new QPushButton(tr("-"));
    molt = new QPushButton(tr("*"));
    div = new QPushButton(tr("/"));
    somma->setEnabled(false);
    diff->setEnabled(false);
    molt->setEnabled(false);
    div->setEnabled(false);

    trasla = new QPushButton(tr("Trasla"));
    interno = new QPushButton(tr("interno"));
    puntoPiuVicino = new QPushButton(tr("Punto più vicino"));
    asd = new QPushButton(tr("Altro"));
    trasla->setEnabled(false);
    interno->setEnabled(false);
    puntoPiuVicino->setEnabled(false);
    asd->setEnabled(false);

    FirstLayout->addWidget(_addFirst);
    FirstLayout->addWidget(addFirst);
    FirstLayout->addWidget(first);

    SecondLayout->addWidget(_addSecond);
    SecondLayout->addWidget(addSecond);
    SecondLayout->addWidget(second);
    OpLayout->addLayout(FirstLayout);
    OpLayout->addLayout(SecondLayout);


    ResultLayout->addWidget(Clear,0,0);
    ResultLayout->addWidget(risultato,1,1,1,2);
    ResultLayout->addWidget(Save,1,0);

    operatori->addWidget(somma,0,0,Qt::AlignRight);
    operatori->addWidget(diff,0,1,Qt::AlignLeft);
    operatori->addWidget(molt,1,0,Qt::AlignRight);
    operatori->addWidget(div,1,1,Qt::AlignLeft);

    funzioni->addWidget(trasla);
    funzioni->addWidget(interno);
    funzioni->addWidget(puntoPiuVicino);
    funzioni->addWidget(asd);

    itemsLayout->addLayout(OpLayout);
    itemsLayout->addLayout(ResultLayout);
    itemsLayout->addLayout(operatori);
    itemsLayout->addLayout(funzioni);
    itemsLayout->addStretch(0);
    group->setLayout(itemsLayout);

    struttura->addWidget(group);
    setLayout(struttura);
setMinimumWidth(500);

connect(addFirst,SIGNAL(clicked(bool)),this,SLOT(addFirstPress()));
connect(addSecond,SIGNAL(clicked(bool)),this,SLOT(addSecondPress()));
connect(Clear,SIGNAL(clicked(bool)),this,SLOT(ClearPress()));
connect(somma,SIGNAL(clicked(bool)),this,SLOT(sommaPress()));
connect(diff,SIGNAL(clicked(bool)),this,SLOT(diffPress()));
connect(molt,SIGNAL(clicked(bool)),this,SLOT(moltPress()));
connect(div,SIGNAL(clicked(bool)),this,SLOT(divPress()));
connect(Save,SIGNAL(clicked(bool)),this,SLOT(savePress()));
connect(trasla,SIGNAL(clicked(bool)),this,SLOT(traslaPress()));
connect(this,SIGNAL(AddItem()),this,SLOT(ClearPress()));

}
void RightArea::selected(int i){
    addFirst->setEnabled(true);
    indice = i;
}
void RightArea::addFirstPress(){
    control->setOp1(indice);
    first->setText(QString::fromStdString(control->stampaOp1()));
    addSecond->setEnabled(true);
    trasla->setEnabled(true);
    Clear->setEnabled(true);
}
void RightArea::addSecondPress(){
    control->setOp2(indice);
    second->setText(QString::fromStdString(control->stampaOp2()));
    somma->setEnabled(true);
    diff->setEnabled(true);
    molt->setEnabled(true);
    div->setEnabled(true);
    trasla->setEnabled(false);
    interno->setEnabled(true);
    puntoPiuVicino->setEnabled(true);
    asd->setEnabled(true);
}

void RightArea::ClearPress(){
first->setText("");
second->setText("");
risultato->setText("");
addSecond->setEnabled(false);
somma->setEnabled(false);
diff->setEnabled(false);
molt->setEnabled(false);
div->setEnabled(false);
Clear->setEnabled(false);
Save->setEnabled(false);
trasla->setEnabled(false);
interno->setEnabled(false);
puntoPiuVicino->setEnabled(false);
asd->setEnabled(false);
}

void RightArea::sommaPress(){
risultato->setText(QString::fromStdString(control->Somma()));
Save->setEnabled(true);
}
void RightArea::diffPress(){
    risultato->setText(QString::fromStdString(control->Differenza()));
    Save->setEnabled(true);
}

void RightArea::moltPress(){
    risultato->setText(QString::fromStdString(control->Moltiplicazione()));
    Save->setEnabled(true);
}
void RightArea::divPress(){
    risultato->setText(QString::fromStdString(control->Divisione()));
    Save->setEnabled(true);
}


void RightArea::savePress(){
control->newObject();
emit AddItem();
}

void RightArea::traslaPress(){
//control->Trasla();
}
