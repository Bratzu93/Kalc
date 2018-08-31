#ifndef KALC_H
#define KALC_H

#include <QObject>
#include <QWidget>
#include <QApplication>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "leftarea.h"
#include "rightarea.h"
#include "controller.h"

class Kalc : public QWidget
{
    Q_OBJECT
private:
    Controller* controller;
    QHBoxLayout* grid;
    LeftArea* left;
    RightArea* right;
public:
   explicit Kalc(QWidget *parent = nullptr);
public slots:

signals:

};

#endif // KALC_H
