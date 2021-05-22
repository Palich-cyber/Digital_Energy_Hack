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

bool creatConnection( QSqlDatabase &&dataBaseValue, ValueConnectionDBStruct *dataBaseNameValue, const dataBaseType &dataBaseTypeValue ) noexcept{

    dataBaseValue = QSqlDatabase::addDatabase("QPSQL");

    dataBaseValue.setHostName(dataBaseNameValue->hostDB);
    dataBaseValue.setPort(dataBaseNameValue->portDB);
    dataBaseValue.setUserName(dataBaseNameValue->userDB);
    dataBaseValue.setPassword(dataBaseNameValue->passwDB);
    if (dataBaseTypeValue == dataBaseType::Input) dataBaseValue.setDatabaseName(dataBaseNameValue->DBNameInput);
        else
        {dataBaseValue.setDatabaseName(dataBaseNameValue->DBNameOutput);
        qDebug() << "dataBaseValue.setDatabaseName" << dataBaseNameValue->DBNameOutput;
    }

    if(!dataBaseValue.open()){
//       Attation attantionWindow;
//       attantionWindow.SetError ("Невозможно подключиться к базе данных.\n "
//                                  "Проверьте состояние сервера Postgres и корректность таблиц БД");
        dataBaseValue.close();

        return false;
    }

    return true;
}
