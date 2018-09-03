#ifndef NEWPOLIGONO_H
#define NEWPOLIGONO_H
#include <QWidget>
#include<QLabel>
#include<QListWidget>
#include<QGridLayout>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QGroupBox>
#include<QPushButton>
#include<QLineEdit>
#include "controller.h"


class newPoligono : public QWidget
{
    Q_OBJECT
private:
    Controller* control;
    QLineEdit* xLineEditfirst;
    QLineEdit* yLineEditfirst;
    QListWidget* list;
    QPushButton* crea;
public:
    newPoligono(Controller* c , QWidget *parent = nullptr);
signals:
    void _salva();
public slots:
    void save_item();
    void AddtoPoligono();
};

#endif // NEWPOLIGONO_H
