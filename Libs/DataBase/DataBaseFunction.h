#ifndef DATABASEFUNCTION_H
#define DATABASEFUNCTION_H

// users
#include "Libs/DataBase/DataBaseConstants.h"
#include "DataBaseStructs.h"

class QSqlDatabase;
class QString;

    // ------------------------- COMMON -------------------------
    void removeConnection( QSqlDatabase &&dataBaseValue ) noexcept;
    bool creatConnection( QSqlDatabase &&dataBaseValue, connectionStruct *connectionPointer ) noexcept;
    bool isAutonomMode ( QSqlDatabase &&dataBaseValue ) noexcept;
    void clearTable ( const QString &tableNameValue ) noexcept;
    // ----------------------- END COMMON -----------------------

#endif // DATABASEFUNCTION_H
