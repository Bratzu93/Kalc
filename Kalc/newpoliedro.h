#ifndef NEWPOLIEDRO_H
#define NEWPOLIEDRO_H
#include <QWidget>
#include<QLabel>
#include<QGridLayout>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QGroupBox>
#include<QPushButton>
#include<QLineEdit>
#include <QListWidget>
#include "controller.h"
class newPoliedro : public QWidget
{
    Q_OBJECT
private:
    Controller* control;
    QLineEdit* altezza;
    QListWidget* list;
public:
    newPoliedro(Controller* c , QWidget *parent = nullptr);
signals:
    void _salva();
public slots:
    void save_item();

};

#endif // NEWPOLIEDRO_H
