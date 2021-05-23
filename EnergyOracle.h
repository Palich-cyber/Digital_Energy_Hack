#ifndef ENERGYORACLE_H
#define ENERGYORACLE_H

#include <QMainWindow>

#include "Libs/Visualisation/Scene.h"
#include "Libs/DataBase/DataBaseStructs.h"

class StrtegyInformer;

namespace Ui {

class EnergyOracle;

}

class EnergyOracle : public QMainWindow
{

    Q_OBJECT

public:

    explicit EnergyOracle( connectionStruct *connectionPointer = nullptr, QWidget *parent = 0 );
    ~EnergyOracle();

private slots:

    void onTimeout();

    void on_comboBox_activated(int index);

    void on_radioButton_clicked(bool checked);

    void on_radioButton_2_clicked(bool checked);

private:

    Ui::EnergyOracle *ui;

    Scene *visualSpaceCraftModel;

    connectionStruct *connection;

    StrtegyInformer *infoWindow;

    QTimer *timer;
};

#endif // ENERGYORACLE_H
