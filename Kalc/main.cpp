#include <QApplication>
#include <QHBoxLayout>
#include "kalc.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
Kalc mainwindow;
mainwindow.show();
    return a.exec();
}
