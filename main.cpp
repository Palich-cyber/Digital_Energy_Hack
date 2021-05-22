#include "EnergyOracle.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EnergyOracle w;
    w.show();

    return a.exec();
}
