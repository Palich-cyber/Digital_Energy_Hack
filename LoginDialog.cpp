#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <qfileinfo.h>
#include <qtextcodec.h>
#include <qfiledialog.h>
#include <qsqlerror.h>
#include <qsettings.h>
#include <qcryptographichash.h>
#include <QGraphicsDropShadowEffect>

#include "LoginDialog.h"
#include "ui_LoginDialog.h"
#include "Libs/DataBase/DataBaseFunction.h"
#include "EnergyOracle.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginDialog), currentConnection ( nullptr ),
    strategyWindow ( nullptr )
{
    ui->setupUi(this);

    createStartData();
}

LoginDialog::~LoginDialog()
{
    delete ui;

    if ( currentConnection ){

        delete currentConnection;
        currentConnection = nullptr;
    }
}

void LoginDialog::createStartData () noexcept{

    ui->lE_host->setText( DEFAULT_CONNECTION[0] );
    ui->lE_port->setText( DEFAULT_CONNECTION[1] );
    ui->lE_DB_user->setText( DEFAULT_CONNECTION[2] );
    ui->lE_DB_passw->setText( DEFAULT_CONNECTION[3] );
    ui->lE_DB_input->setText( DEFAULT_CONNECTION[4] );

    return;
}

void LoginDialog::on_pushButton_clicked () noexcept{

    if ( currentConnection ){

        delete currentConnection;
        currentConnection = nullptr;
    }

    currentConnection = new connectionStruct( ui->lE_host->text(), ui->lE_port->text().toInt(), ui->lE_DB_user->text(),
                                              ui->lE_DB_passw->text(), ui->lE_DB_input->text() );


    QSqlDatabase db;
    removeConnection( std::move(db) );
    if ( !creatConnection( std::move(db), currentConnection ) ) return;

    if ( isAutonomMode( std::move(db) ) )

        if ( !strategyWindow ){

            strategyWindow = new EnergyOracle( currentConnection );
            connect( strategyWindow, SIGNAL( back() ), this, SLOT( closeMainDataMenu() ) );
        }
        strategyWindow->show();

    this->close();

    return;
}

void LoginDialog::closeMainDataMenu() noexcept{

    strategyWindow->hide();
    delete strategyWindow;
    strategyWindow = nullptr;

    this->show();

    return;
}
