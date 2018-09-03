#ifndef NEWSEGMENTO_H
#define NEWSEGMENTO_H

#include <QWidget>
#include<QLabel>
#include<QGridLayout>
#include<QGroupBox>
#include<QPushButton>
#include<QLineEdit>
#include "controller.h"


class newSegmento : public QWidget
{
    Q_OBJECT
private:
    Controller* control;
    QLineEdit* xLineEditFirst;
    QLineEdit* yLineEditFirst;
    QLineEdit* xLineEditSecond;
    QLineEdit* yLineEditSecond;

public:
    newSegmento(Controller* c , QWidget *parent = nullptr);
signals:
    void _salva();
public slots:
    void save_item();

};

#endif // NEWSEGMENTO_H
