#ifndef DATABASESTRUCTS_H
#define DATABASESTRUCTS_H

#include <QString>

enum dataBaseType{

    Input  = 0,
    Output = 1
};

struct connectionStruct
{

    connectionStruct (){}
    connectionStruct ( connectionStruct *connectionPointer ) :
    host ( std::move( connectionPointer->host ) ), port ( std::move( connectionPointer->port ) ),
    user ( std::move( connectionPointer->user ) ), password ( std::move( connectionPointer->password ) ),
    name ( std::move( connectionPointer->name ) ){}
    connectionStruct( const QString &hostValue, const int &portValue, const QString &userValue,
                      const QString &passwordValue, const QString &nameValue ) :
    host ( std::move( hostValue ) ), port ( std::move( portValue ) ), user ( std::move( userValue ) ),
    password ( std::move( passwordValue ) ), name ( std::move( nameValue ) ){}

    QString host;
    int     port;
    QString user,
            password,
            name;
};

#endif // DATABASESTRUCTS_H

