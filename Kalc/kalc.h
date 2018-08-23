#ifndef KALC_H
#define KALC_H

#include <QObject>
#include <QWidget>

class Kalc : public QWidget
{
    Q_OBJECT
public:
   explicit Kalc(QWidget *parent = nullptr);
};

#endif // KALC_H
