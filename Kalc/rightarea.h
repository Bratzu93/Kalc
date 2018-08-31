#ifndef RIGHTAREA_H
#define RIGHTAREA_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QTabWidget>


class RightArea : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout* struttura;
    QTabWidget* group;
    QLineEdit* op;
    QPushButton* uguale;
    QLineEdit* risultato;
    QPushButton* saveButton;

public:
    explicit RightArea(QWidget *parent = nullptr);

};

#endif // RIGHTAREA_H
