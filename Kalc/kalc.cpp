#include "kalc.h"
#include <QLineEdit>
#include <QGridLayout>

Kalc::Kalc(QWidget *parent) :QWidget(parent){
controller = new Controller();
left = new LeftArea(controller);
right = new RightArea;
grid = new QHBoxLayout;

grid->addWidget(left);
grid->addWidget(right);
setLayout(grid);
resize(900,500);

connect(left, SIGNAL(itemAdded()), this, SLOT(addItem()));
connect(right, SIGNAL(itemAdded()), this, SLOT(addItem()));

}


