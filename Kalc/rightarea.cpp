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
    QGridLayout* funzioni = new QGridLayout;

    QLabel* _addFirst = new QLabel(tr("primo operando"));
    QLabel* _addSecond = new QLabel(tr("secondo operando"));

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
    _traslaX = new QLineEdit;
    _traslaY = new QLineEdit;
    traslaX = new QLabel(tr("Asse x:"));
    traslaY= new QLabel(tr("Asse Y:"));
    _trasla = new QPushButton(tr("salva"));
    _trasla->setVisible(false);
    _trasla->setEnabled(false);
    _traslaX->setVisible(false);
    traslaX->setVisible(false);
    _traslaY->setVisible(false);
    traslaY->setVisible(false);

    interno = new QPushButton(tr("interno"));
    puntoPiuVicino = new QPushButton(tr("Punto più vicino"));
    SommaSegm = new QPushButton(tr("Somma segmenti"));
    trasla->setEnabled(false);
    interno->setEnabled(false);
    puntoPiuVicino->setEnabled(false);
    SommaSegm->setEnabled(true);

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

    funzioni->addWidget(interno,0,0);
    funzioni->addWidget(puntoPiuVicino,0,1);
    funzioni->addWidget(SommaSegm,0,2);
    funzioni->addWidget(trasla,1,0);
    funzioni->addWidget(traslaX,1,1);
    funzioni->addWidget(_traslaX,1,2);
    funzioni->addWidget(_trasla,2,0);
    funzioni->addWidget(traslaY,2,1);
    funzioni->addWidget(_traslaY,2,2);

    itemsLayout->addLayout(OpLayout);
    itemsLayout->addLayout(ResultLayout);
    itemsLayout->addLayout(operatori);
    itemsLayout->addStretch(1);
    itemsLayout->addLayout(funzioni);
    itemsLayout->addStretch(2);
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
connect(_trasla,SIGNAL(clicked(bool)),this,SLOT(_traslaPress()));
connect(this,SIGNAL(AddItem()),this,SLOT(ClearPress()));
connect(puntoPiuVicino,SIGNAL(clicked(bool)),this,SLOT(Punto_VicinoPress()));
connect(interno,SIGNAL(clicked(bool)),this,SLOT(internoPress()));
connect(SommaSegm,SIGNAL(clicked(bool)),this,SLOT(SommaSegmPress()));
}
void RightArea::selected(int i){
    addFirst->setEnabled(true);
    indice = i;
}
void RightArea::addFirstPress(){
    SommaSegm->setEnabled(false);
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
    SommaSegm->setEnabled(false);
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
SommaSegm->setEnabled(true);
}

void RightArea::sommaPress(){
risultato->setText(QString::fromStdString(control->Somma()));
Save->setEnabled(true);
}
void RightArea::diffPress(){
    try{
    risultato->setText(QString::fromStdString(control->Differenza()));
    Save->setEnabled(true);
    }catch(Punti_allineati){
        QMessageBox* errorMsg= new QMessageBox();
        errorMsg->setInformativeText(QString(tr("I due poligoni sottratti non formano un poligono")));
        errorMsg->exec();
    }catch(Poligono_con_meno_di_3_punti){
        QMessageBox* errorMsg= new QMessageBox();
        errorMsg->setInformativeText(QString(tr("I due poligoni sottratti non formano un poligono")));
        errorMsg->exec();
    }
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
try{
        control->newObject();
        emit AddItem();
    }
    catch(Poligono_con_meno_di_3_punti){
        QMessageBox* errorMsg= new QMessageBox();
        errorMsg->setInformativeText(QString(tr("Poligono con meno di 3 punti")));
        errorMsg->exec();
    }catch(Punti_allineati){
        QMessageBox* errorMsg= new QMessageBox();
        errorMsg->setInformativeText(QString(tr("Errore!!! i punti sono allineati")));
        errorMsg->exec();
    }
}

void RightArea::traslaPress(){
    if(_trasla->isVisible()){
        _trasla->setVisible(false);
        _trasla->setEnabled(false);
        _traslaX->setVisible(false);
        traslaX->setVisible(false);
        _traslaY->setVisible(false);
        traslaY->setVisible(false);
    }else{
        SommaSegm->setEnabled(false);
        _trasla->setVisible(true);
        _trasla->setEnabled(true);
        _traslaX->setVisible(true);
        traslaX->setVisible(true);
        _traslaY->setVisible(true);
        traslaY->setVisible(true);
    }

}
void RightArea::_traslaPress(){
    control->Trasla(_traslaX->text().toDouble(),_traslaY->text().toDouble());
    traslaPress();
    _traslaX->setText("");
    _traslaY->setText("");
    emit AddItem();
}

void RightArea::Punto_VicinoPress(){
    try{
        risultato->setText(QString::fromStdString(control->Punto_piu_vicino()));
        Save->setEnabled(true);
    }
    catch(PuntoExep){
        QMessageBox* errorMsg= new QMessageBox();
        errorMsg->setInformativeText(QString(tr("Il primo operando deve essere un punto")));
        errorMsg->exec();
    }
}

void RightArea::internoPress(){
    try{risultato->setText(QString::fromStdString(control->Interno()));}
    catch(PoligonoInternoExep){
        QMessageBox* errorMsg= new QMessageBox();
        errorMsg->setInformativeText(QString(tr("Il primo operando deve essere un Punto e il secondo un Poligono")));
        errorMsg->exec();
    }
}
void RightArea::SommaSegmPress(){
    risultato->setText(QString::number(control->SommaSegmenti()));
}
