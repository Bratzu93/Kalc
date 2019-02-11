#include "kalc.h"
#include <QLineEdit>
#include <QGridLayout>

Kalc::Kalc(QWidget *parent) :QWidget(parent){
controller = new Controller();
left = new LeftArea(controller);
right = new RightArea(controller);
Aree = new QGridLayout;
Aree->addWidget(left,0,0);
Aree->addWidget(right,0,1);
setLayout(Aree);
resize(900,500);

connect(left, SIGNAL(_selected(int)), right,SLOT(selected(int)));
connect(right,SIGNAL(AddItem()),left,SLOT(itemAdded()));
}

