#include "rightarea.h"

RightArea::RightArea(QWidget *parent) : QWidget(parent)
{
    struttura = new QVBoxLayout(this);
    //operazioni unarie
    group = new QTabWidget();
    op = new QLineEdit("0");
    uguale = new QPushButton(tr("="));
    group->addTab(new QWidget(),"Operazioni unarie");
    group->addTab(new QWidget(),"Operazioni binarie");
    struttura->addWidget(group);
    setLayout(struttura);
setMinimumWidth(500);
}
