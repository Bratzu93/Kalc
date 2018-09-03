#ifndef NEWPOINT_H
#define NEWPOINT_H
#include <QWidget>
#include<QLabel>
#include<QGridLayout>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QGroupBox>
#include<QPushButton>
#include<QLineEdit>
#include "controller.h"

class newPoint : public QWidget
{
    Q_OBJECT
private:
    Controller* control;
    QLineEdit* xLineEditfirst;
    QLineEdit* yLineEditfirst;

public:
    newPoint(Controller* c , QWidget *parent = nullptr);
signals:
    void _salva();
public slots:
    void save_item();


};

#endif // NEWPOINT_H
