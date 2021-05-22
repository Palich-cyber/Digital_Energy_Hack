#include "EnergyOracle.h"
#include "ui_EnergyOracle.h"

EnergyOracle::EnergyOracle(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EnergyOracle), visualSpaceCraftModel ( nullptr )
{
    ui->setupUi(this);

    visualSpaceCraftModel = new Scene;
   // visualSpaceCraftModel->resize (ui->gB_initialEiler->width()-20, ui->gB_initialEiler->height()-20);
    visualSpaceCraftModel->setModel( qApp->applicationDirPath() + "/Resources/textures/map.obj" );
    ui->vL_RotationModel->addWidget( visualSpaceCraftModel );
}

EnergyOracle::~EnergyOracle()
{
    delete ui;
}
