#include <QApplication>
#include <QFileInfo>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QColor>
#include <QDebug>
#include <QString>
#include <QTableWidget>
#include <QTableWidgetItem>

#include "DataBaseFunction.h"
#include "DataBaseConstants.h"

void removeConnection(QSqlDatabase &&dataBaseValue) noexcept{

    if (!dataBaseValue.connectionNames().isEmpty()){
        for (int i = 0; i < dataBaseValue.connectionNames().count(); ++i){
            dataBaseValue.removeDatabase(dataBaseValue.connectionNames().at(i));
        }
    }

    return;
}

bool creatConnection( QSqlDatabase &&dataBaseValue, connectionStruct *connectionPointer ) noexcept{

    if ( !connectionPointer ) return false;

    dataBaseValue = QSqlDatabase::addDatabase("QPSQL");

    if ( !dataBaseValue.isValid() ){

//        QMessageBox::information(nullptr, "Информация", "Подключение к БД отсутствует.\n"
//                                                        "Работа в автономном ржиме."
//                                 , QMessageBox::Ok);

        dataBaseValue = QSqlDatabase::addDatabase( SQLITE_DRIVER_NAME );

        if ( !dataBaseValue.isValid() ) return false;

        dataBaseValue.setDatabaseName( QString( "%1/%2" ).arg( qApp->applicationDirPath() ).arg( DEFAULT_DATABASE_NAME ) );
    }
    else{

        dataBaseValue.setHostName(connectionPointer->host);
        dataBaseValue.setPort(connectionPointer->port);
        dataBaseValue.setUserName(connectionPointer->user);
        dataBaseValue.setPassword(connectionPointer->password);
        dataBaseValue.setDatabaseName(connectionPointer->name);
    }

    if( !dataBaseValue.open() ){
//       Attation attantionWindow;
//       attantionWindow.SetError ("Невозможно подключиться к базе данных.\n "
//                                  "Проверьте состояние сервера Postgres и корректность таблиц БД");
//        dataBaseValue.close();

        return false;
    }

    return true;
}

bool isAutonomMode( QSqlDatabase &&dataBaseValue ) noexcept{

    if ( dataBaseValue.driverName() == SQLITE_DRIVER_NAME ) return true;

    return false;
}

void clearTable( const QString &tableNameValue ) noexcept{

    QSqlQuery query;
    query.exec( QString ( "DELETE FROM %1" ).arg( tableNameValue ) );

    return;
}
