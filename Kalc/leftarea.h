#ifndef LEFTAREA_H
#define LEFTAREA_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QListWidget>
#include <QListView>
#include <QPushButton>
#include <QTabWidget>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include "creazione.h"
#include "controller.h"

class LeftArea : public QWidget
{
    Q_OBJECT


private:

    Controller* control;
    QGroupBox* group;
    QListWidget* l;
    QTabWidget* tab;
    QGroupBox* dettagli;
    Creazione* _creazione;
    QVBoxLayout* struttura;
    QVBoxLayout* _struttura;
public:
    LeftArea(Controller* c , QWidget *parent = nullptr);

signals:

public slots:
    void itemAdded();

};

#endif // LEFTAREA_H
