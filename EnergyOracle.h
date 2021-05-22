#ifndef ENERGYORACLE_H
#define ENERGYORACLE_H

#include <QMainWindow>

#include "Libs/Visualisation/Scene.h"

namespace Ui {
class EnergyOracle;
}

class EnergyOracle : public QMainWindow
{
    Q_OBJECT

public:
    explicit EnergyOracle(QWidget *parent = 0);
    ~EnergyOracle();

private:
    Ui::EnergyOracle *ui;

    Scene *visualSpaceCraftModel;
};

#endif // ENERGYORACLE_H
