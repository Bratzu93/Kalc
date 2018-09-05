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
#include "dettagli.h"

class LeftArea : public QWidget
{
    Q_OBJECT


private:

    Controller* control;
    QGroupBox* group;
    QListWidget* list;
    QTabWidget* tab;
    Dettagli* dettagli;
    Creazione* _creazione;
    QVBoxLayout* struttura;
    QVBoxLayout* _struttura;
public:
    LeftArea(Controller* c , QWidget *parent = nullptr);

signals:
    void _selected(int);
public slots:
    void itemAdded();
    void selected();
};

#endif // LEFTAREA_H
