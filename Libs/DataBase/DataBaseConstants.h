#ifndef DATABASECONSTANTS_H
#define DATABASECONSTANTS_H

#include <QStringList>

/* space_obj            - spaceCraftTable
 * scenarioSpaceObject  - scenarioOrbitalGroupTable
 * scenario             - scenarioTable
 * scenarioStation      - scenarioStationTable
*/

const QString DEFAULT_DATABASE_NAME  = "Resources/dataBase/DB_Energy.db";
const QString SQLITE_DRIVER_NAME     = "QSQLITE";
const QString POSTRESQL_DRIVER_NAME  = "QPSQL";

const QStringList DEFAULT_CONNECTION = { "10.90.90.23",          // host     - 0
                                         "5432",                 // port     - 1
                                         "postgres",             // user     - 2
                                         "xTk9Rs56",             // password - 3
                                         "october_mission" };    // name`    - 4

const QStringList tableHeaders    = { "space_obj",
                                      "scenarioSpaceObject",
                                      "scenario",
                                      "scenarioStation",
                                      "ScenarioGroundControlComplex",
                                      "StationsInComplex",
                                      "SeparateCommandMeasurementComplexTable",
                                      "CommandMeasurementStationTable",
                                      "GroundControlComplexZoneVision",
                                      "TechnologicOperationInCycleTable",
                                      "TechnologicCycleTable",
                                      "TechnologicOperationTable",
                                      "CommandMeasurementStationModeTable",
                                      "RLSGroup",
                                      "OES"};

const QStringList spaceCraftTable = { "id_SO",
                                      "scenarioId",
                                      "object_name",
                                      "big_axis",
                                      "eccentricity",
                                      "ra_of_asc_node",
                                      "inclination",
                                      "arg_of_pericenter",
                                      "epoch_time",
                                      "start_MGM_AGECS_x",
                                      "start_MGM_AGECS_y",
                                      "start_MGM_AGECS_z",
                                      "start_MGM_AGECS_Vx",
                                      "start_MGM_AGECS_Vy",
                                      "start_MGM_AGECS_Vz",
                                      "timeAGECS",
                                      "rotational_Vx",
                                      "rotational_Vy",
                                      "rotational_Vz",
                                      "external_moment_X",
                                      "external_moment_Y",
                                      "external_moment_Z",
                                      "main_moment_inertia_X",
                                      "main_moment_inertia_Y",
                                      "main_moment_inertia_Z",
                                      "start_precession",
                                      "start_nutation",
                                      "start_rotation_speed",
                                      "model_rotation" },

        scenarioOrbitalGroupTable = { "scenarioId",
                                      "id" },

                    scenarioTable = { "name",
                                      "iterationCount",
                                      "jdsStart",
                                      "jdsFinish",
                                      "stepModeling",
                                      "id",
                                      "agskMoonX",
                                      "agskMoonY",
                                      "agskMoonZ",
                                      "agskSunX",
                                      "agskSunY",
                                      "agskSunZ" },

             scenarioStationTable = { "scenarioId",
                                      "type",
                                      "id" },

     ScenarioGroundControlComplex = { "scenarioId",
                                      "commandComplexId",
                                      "stationId" },

           StationsInComplexTable = { "complexId",
                                      "stationId",
                                      "stationCount" },

SeparateCommandMeasurementComplexTable = { "id",
                                           "name",
                                           "longitude",
                                           "latitude",
                                           "height" },

CommandMeasurementStationTable = { "id",
                                   "name",
                                   "type",
                                   "minRange",
                                   "maxRange",
                                   "minAntennaElevation" },

GroundControlComplexZoneVisionTable = { "complexId",
                                        "complexName",
                                        "stationId",
                                        "stationName",
                                        "stationType",
                                        "spaceCraftId",
                                        "loopNumber",
                                        "entranceTime",
                                        "exitTime" },

TechnologicOperationInCycleTable = { "cycleId",
                                     "operationId" },

TechnologicCycleTable = { "id",
                          "name",
                          "duration" },

TechnologicOperationTable = { "id",
                              "name",
                              "type",
                              "duration",
                              "frequency" },

CommandMeasurementStationModeTable = { "stationId",
                                       "modeId" },

RLSGroupTable = { "id_RLS",
                  "name_RLS",
                  "model_RLS",
                  "name_disloc",
                  "name_sys",
                  "latitude",
                  "longtitude" }, // NOT FULL

OESTable = { "id_OES",
             "OES_Name",
             "OES_Dislocation",
             "OES_TypeSystem" }, // NOT FULL


spasecraftradioandopticmodel = { "spacecraftid",
                                 "scenarioid",
                                 "radiomodelid",
                                 "opticmodelid",
                                 "radiodispersion",
                                 "radiomathexpetation",
                                 "opticdispersion",
                                 "opticmathexpetation",
                                 "paramreflex",
                                 "radius",
                                 "pdiffus",
                                 "psurface" };





/* ------------------------ Structs -------------------------------- */

// --------------------- GroundStation -----------------------------

struct CoordinateStruct{

    CoordinateStruct() : longitude ( 0.0F ), latitude ( 0.0F ), height ( 0.0F ),
                         agskX ( 0.0F ), agskY ( 0.0F ), agskZ ( 0.0F ){}
    CoordinateStruct( double&& longitudeValue, double&& latitudeValue,
                      double&& heightValue ) : longitude ( std::move(longitudeValue) ),
                      latitude ( std::move(latitudeValue) ), height ( std::move(heightValue) ),
                      agskX ( 0.0F ), agskY ( 0.0F ), agskZ ( 0.0F ){}

    double longitude,
           latitude,
           height,
           agskX,
           agskY,
           agskZ;
};

struct ZoneParametersStruct{

    ZoneParametersStruct() : minRange ( 0.0F ), maxRange ( 0.0F ), minAzimuth ( 0.0F ),
                             maxAzimuth ( 0.0F ), minElevation ( 0.0F ), maxElevation ( 0.0F ){}
    ZoneParametersStruct( double&& minRangeValue, double&& maxRangeValue, double&& minAzimuthValue,
                          double&& maxAzimuthValue, double&& minElevationValue, double&& maxElevationValue  ) :
                          minRange ( std::move(minRangeValue) ), maxRange ( std::move(maxRangeValue) ),
                          minAzimuth ( std::move(minAzimuthValue) ), maxAzimuth ( std::move(maxAzimuthValue) ),
                          minElevation ( std::move(minElevationValue) ), maxElevation ( std::move(maxElevationValue) ){}

    double minRange,
           maxRange,
           minAzimuth,
           maxAzimuth,
           minElevation,
           maxElevation;
};

struct ZoneEventStruct{

    ZoneEventStruct(){}
    ZoneEventStruct( const int &sectorNumValue, const int &shineNumValue, const double *spaceCraftAgskPointer,
                     const double *spaceCraftMskPointer, const double *spaceCraftRlsPointer, const double &jdTimeValue,
                     const double &jdFinishTimeValue = 0.0F ) :
    sectorNum ( std::move( sectorNumValue ) ), shineNum ( std::move( shineNumValue ) ), jdTime ( std::move( jdTimeValue ) ),
    jdFinishTime ( std::move( jdFinishTimeValue ) ){

        for ( int i = 0; i < 3; ++i ){

            spaceCraftAgsk[i]     = std::move( spaceCraftAgskPointer[i] );
            spaceCraftAgsk[i + 3] = std::move( spaceCraftAgskPointer[i + 3] );
            spaceCraftMsk[i]      = std::move( spaceCraftMskPointer[i] );
            spaceCraftMsk[i + 3]  = std::move( spaceCraftMskPointer[i + 3] );
            spaceCraftRls[i]      = std::move( spaceCraftRlsPointer[i] );
        }
    }

    int    sectorNum,
           shineNum;
    double spaceCraftAgsk[6],
           spaceCraftMsk[6],
           spaceCraftRls[3],
           jdTime,
           jdFinishTime;

};

struct ZoneStruct{

    ZoneStruct() : spaceCraftId (0), stationNumInSystem (0), spaceCraftLoop (0), entranceJDTime ( 0.0F ), exitJDTime ( 0.0F ),
                   entranceAgsk ( new double[6] ), entranceRls ( new double[3] ){}
    ZoneStruct( const ZoneStruct &zoneValue ) :
                spaceCraftId ( std::move( zoneValue.spaceCraftId ) ), stationNumInSystem (std::move( zoneValue.stationNumInSystem ) ),
                spaceCraftLoop ( std::move( zoneValue.spaceCraftLoop ) ),
                entranceJDTime ( std::move( zoneValue.entranceJDTime ) ),
                exitJDTime ( std::move( zoneValue.exitJDTime ) ), entranceAgsk ( new double[6] ), entranceRls ( new double[3] ){

        for ( int i = 0; i < 6; ++i )
            entranceAgsk[i] = std::move( zoneValue.entranceAgsk[i] );
        for ( int i = 0; i < 3; ++i )
            entranceRls[i] = std::move( zoneValue.entranceRls[i] );
    }

    int    spaceCraftId,
           stationNumInSystem,
           spaceCraftLoop;
    double entranceJDTime,
           exitJDTime,
           *entranceAgsk,
           *entranceRls;

    QVector <ZoneEventStruct> event;
};

struct ReportStruct{

    ReportStruct(){}
   // OpticStation
    QString zoneCheck;
    int     spaceCraftId,               // id of SO
            shineNum,            // num of shine
            sectorNum,           // num of sector
            trajectoryFlag,
            iterationId,
            stationNumInSysytem;
    double  JDTime,               // julian time
            antennaGain,         // antenna gain
            RLS[3],               // 0 - elevation, 1 - azimuth, 2 - range
            SKO[7],
            MSK[6],
            AGSK[6],
            Quaternion[4],
            racurs[2],
            dispersionArea;
    // OpticStation

    QString parametr_shine;  // Параметр отражения светимости
    bool   find_mgm_fact,            // Факт обнаружения
    fact_nalozh_zvezd_ko,             // Фвкт наложения
    oes_mgm_find_critery;    // Выполнение критерияя распознавания МГМ полезной нагрузки в зоне ответственности наземного ОЭС
    double     shine_ko_mgm,         // Значение cилы отраженного излучения от МГМ полезной нагрузки в коcмосе
    shine_ko_oes,        // приходящая на ОЭС
    shine_ko_mgm_zvezd,
    shine_ko_oes_zvezd,
    shine_ko_optic_system_oes, // приходящая с оптической системы
    shine_ko_optic_system_oes_zvezd,
    oes_angle_ugl_azimuth_out,    // Координаты обнаруженной МГМ полезной нагрузки в поле зрения специализированного оптического средства
    oes_angle_ugl_elevation_out,  // Координаты обнаруженной МГМ полезной нагрузки в поле зрения специализированного оптического средства
    oes_mgm_find_probability,  // Вероятность возможности распознавания МГМ полезной нагрузки в зоне ответственности наземного ОЭС
    oes_angle_ugl_azimuth_in, // Координаты обнаруженной МГМ полезной нагрузки в поле зрения специализированного оптического средства
    oes_angle_ugl_elevation_in, // Координаты обнаруженной МГМ полезной нагрузки в поле зрения специализированного оптического средства
    oes_naklon_range,// Дальность до МГМ полезной нагрузки относсительно специализированного оптического средства
    angle_faz_sun_ko_oes,    // Фазовый угол между Солнце, КА, наземной ОЭС
    angleSunEarthSO,  // Угол между Солнцем Землей КА, град.
    angleSunEathOS,  // Угол между Солнцем, Землей, наземной ОЭС, град.
    angleMoonOSSO,    // Угол между Луной, наземной ОЭС, КА град.
    angle_ko_racurs_x, //  Ракурс КА для эсперементальных данных, ракурс, град.
    angle_ko_racurs_y; //  Ракурс КА для эсперементальных данных, ракурс, град.
};

struct ResultStruct{

    ResultStruct(){}

    ZoneStruct zone;
    QVector <ReportStruct> report;
};

struct SpaceCraftInZoneStruct{

    SpaceCraftInZoneStruct(){}
    SpaceCraftInZoneStruct( const double &jdTimeValue, const double *agskValue, const double *quaternionValue, const double &racursAlpha,
                            const double &racursBetta ) :
    jdTime ( std::move( jdTimeValue ) ){

        for ( int i = 0; i < 6; ++i )
            AGSK[i] = agskValue[i];
        for ( int i = 0; i < 4; ++i )
            Quaternion[i] = quaternionValue[i];

        racurs[0] = racursAlpha;
        racurs[1] = racursBetta;
    }

    double jdTime,
           AGSK[6],
           Quaternion[4],
           racurs[2];
};

enum stationType{

    All      = 0,
    RadioLoc = 1,
    Optic    = 2,
    Control  = 3
};

const QStringList stationTypeList = { "radioloc",
                                      "optic",
                                      "control" };

// -------------------End GroundStation ----------------------------

enum controlStationType{

    Telemetry          = 0,
    Measurement        = 1,
    Command            = 2,
    MeasurementCommand = 3,
    Special            = 4,
    Universal          = 5
};

const QStringList commandMeasurementStationTypeList = { "telemetry",
                                                        "measurement",
                                                        "command",
                                                        "measurement-command",
                                                        "special",
                                                        "universal" };

struct ControlStationModeStruct{

    ControlStationModeStruct () : name ( "" ), id ( 0 ){}
    ControlStationModeStruct ( const QString &nameValue, const int &idValue ) : name ( std::move( nameValue ) ),
                                                                                id ( std::move( idValue ) ){}

    QString name;
    int     id;
};

/* ----------------------End Structs ------------------------------- */
#endif // DATABASECONSTANTS_H
