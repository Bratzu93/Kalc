#ifndef CREAZIONE_H
#define CREAZIONE_H

#include <QWidget>
#include <QPushButton>
#include<QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include "controller.h"
class Creazione : public QWidget
{
    Q_OBJECT

public:
    explicit Creazione(Controller* controller,QWidget *parent = nullptr);
public slots:
    void save_item();
signals:
    void _salva();
private:
    QGridLayout* creazione;
    QPushButton* salva;
    QLabel* xLabel;
    QLabel* yLabel;
    QLineEdit* xLineEdit;
    QLineEdit* yLineEdit;
    Controller* control;
};

#endif // CREAZIONE_H
