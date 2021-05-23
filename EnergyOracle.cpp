#include <QTimer>

#include "EnergyOracle.h"
#include "ui_EnergyOracle.h"
#include "TacticLevel.h"
#include "StrtegyInformer.h"

EnergyOracle::EnergyOracle( connectionStruct *connectionPointer, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EnergyOracle), visualSpaceCraftModel ( nullptr ),
    connection ( connectionPointer ), infoWindow ( nullptr ), timer ( nullptr )
{
    ui->setupUi(this);

    visualSpaceCraftModel = new Scene;

    visualSpaceCraftModel->setModel( qApp->applicationDirPath() + "/Resources/textures/map.obj" );

    ui->vL_RotationModel->addWidget( visualSpaceCraftModel );

    ui->dateTimeEdit->setDateTime( QDateTime::currentDateTime() );
    ui->dateTimeEdit_2->setMinimumDateTime( QDateTime::currentDateTime() );
    ui->dateTimeEdit_2->setDateTime( QDateTime::currentDateTime() );

    timer = new QTimer(this);
    connect( timer, SIGNAL( timeout() ), this, SLOT( onTimeout() ) );
    timer->start(50);
}

EnergyOracle::~EnergyOracle()
{
    delete ui;
}

void EnergyOracle::onTimeout (){

    QApplication::processEvents();
    ui->dateTimeEdit->setDateTime( QDateTime::currentDateTime() );

    return;
}

void EnergyOracle::on_comboBox_activated ( int index ){

    TacticLevel *regionWindow = new TacticLevel ( nullptr, index );

    regionWindow->show();

    return;
}

void EnergyOracle::on_radioButton_clicked ( bool checked ){

   // QApplication::processEvents();
    if ( checked ){

        visualSpaceCraftModel->setColor( true );
        visualSpaceCraftModel->update();
    }

    return;
}

void EnergyOracle::on_radioButton_2_clicked( bool checked ){

    if ( checked ){

        infoWindow = new StrtegyInformer;
        infoWindow->show();

        visualSpaceCraftModel->setColor( false );
        visualSpaceCraftModel->update();
    }

    return;
}
