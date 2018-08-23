#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include "kalc.h"
#include"model/base.h"

Kalc::Kalc(QWidget *parent) :QWidget(parent)
{
QVBoxLayout* operandi = new QVBoxLayout();

QLabel* primo = new QLabel(tr("primo operando"),this);
QLineEdit* p1 = new QLineEdit("",this);
QPushButton* add_p = new QPushButton("aggiungi oggetto",this);
operandi->addWidget(primo);
operandi->addWidget(p1);
operandi->addWidget(add_p);
setLayout(operandi);
}
