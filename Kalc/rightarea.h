#ifndef RIGHTAREA_H
#define RIGHTAREA_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGroupBox>
#include <QMessageBox>
#include "unaria.h"

class RightArea : public QWidget
{
    Q_OBJECT
private:
    Controller* control;
    QGroupBox* group;
    QGridLayout* struttura;
    QPushButton* addFirst;
    QLineEdit* first;
    QLineEdit* second;
    QLineEdit* risultato;
    QPushButton* addSecond;
    QPushButton* Save;
    QPushButton* Clear;
    QPushButton* somma;
    QPushButton* diff;
    QPushButton* molt;
    QPushButton* div;
    QPushButton* trasla;
    QLabel* traslaX;
    QLabel* traslaY;
    QLineEdit* _traslaX;
    QLineEdit* _traslaY;
    QPushButton* _trasla;
    QPushButton* puntoPiuVicino;
    QPushButton* interno;
    QPushButton* SommaSegm;


    int indice;

public:
    RightArea(Controller* c , QWidget *parent = nullptr);

public slots:
    void selected(int i);
    void addFirstPress();
    void addSecondPress();
    void ClearPress();
    void savePress();
    void sommaPress();
    void diffPress();
    void moltPress();
    void divPress();
    void traslaPress();
    void _traslaPress();
    void internoPress();
    void Punto_VicinoPress();
    void SommaSegmPress();
signals:
    void AddItem();

};

#endif // RIGHTAREA_H
