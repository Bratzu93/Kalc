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
    QGridLayout* Aree;
    LeftArea* left;
    RightArea* right;
public:
   explicit Kalc(QWidget *parent = nullptr);
};

#endif // KALC_H
