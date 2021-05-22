#ifndef DATABASESTRUCTS_H
#define DATABASESTRUCTS_H

#include <QString>

enum dataBaseType{

    Input  = 0,
    Output = 1
};

struct ValueConnectionDBStruct
{

    ValueConnectionDBStruct(){}
    ValueConnectionDBStruct( ValueConnectionDBStruct *valueConnectionDBPointer ) :
    hostDB ( std::move( valueConnectionDBPointer->hostDB ) ), portDB ( std::move( valueConnectionDBPointer->portDB ) ),
    userDB ( std::move( valueConnectionDBPointer->userDB ) ), passwDB ( std::move( valueConnectionDBPointer->passwDB ) ),
    DBNameInput ( std::move( valueConnectionDBPointer->DBNameInput ) ), DBNameOutput ( std::move( valueConnectionDBPointer->DBNameOutput ) ){}
    ValueConnectionDBStruct( const QString &hostDBValue, const int &portDBValue, const QString &userDBValue,
                             const QString &passwDBValue, const QString &DBNameInput, const QString &DBNameOutput ) :
    hostDB ( std::move( hostDBValue ) ), portDB ( std::move( portDBValue ) ), userDB ( std::move( userDBValue ) ),
    passwDB ( std::move( passwDBValue ) ), DBNameInput ( std::move( DBNameInput ) ), DBNameOutput ( std::move( DBNameOutput ) ){}

    QString hostDB;
    int     portDB;
    QString userDB,
            passwDB,
            DBNameInput,
            DBNameOutput;
};

struct scenarioStruct{

    scenarioStruct() : spaceCraftCount (0), radiolocStationCount (0), opticStationCount(0){
        agskMoon = new double[3];
        agskSun = new double[3];
    }
    scenarioStruct( const QString &nameValue, const int &iterationCountValue,
                    const double &jdsStartValue, const double &jdsFinishValue,
                    const double &modelingStepValue, const int &idValue,
                    double *agskMoonValue, double *agskSunValue) :
    name ( nameValue ), iterationCount ( iterationCountValue ), id ( idValue ),
    jdsStart ( jdsStartValue ), jdsFinish ( jdsFinishValue ), modelingStep ( modelingStepValue ),
    agskMoon ( agskMoonValue ), agskSun ( agskSunValue ), spaceCraftCount (0),
    radiolocStationCount (0), opticStationCount(0){

        if ( jdsFinishValue > jdsStartValue ) deltaTime = ( jdsFinishValue - jdsStartValue ) * 86400.0F;
        else deltaTime = 0.0F;

        if ( !agskMoon ) agskMoon = new double[3];
        if ( !agskSun ) agskSun = new double[3];

        return;
    }

    QString name;
    int     iterationCount,
            id;
    double  jdsStart,
            jdsFinish,
            modelingStep,
            deltaTime,
            *agskMoon,
            *agskSun;
    int     spaceCraftCount,
            radiolocStationCount,
            opticStationCount;
};

#endif // DATABASESTRUCTS_H

