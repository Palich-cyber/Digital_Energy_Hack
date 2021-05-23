#ifndef SPACEOBJECT3D_H
#define SPACEOBJECT3D_H

// system
#include <QMatrix4x4>
#include <QVector3D>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QOpenGLFunctions>
#include <QGLWidget>
#include <QQuaternion>
#include <QFile>
#include <QStringList>
#include <QApplication>

// users
#include "sceneconstants.h"
#include "simpleelement.h"
#include "materiallibrary.h"

class SpaceObject3D
{
public:

    SpaceObject3D();
    ~SpaceObject3D();

    struct vertex_data{
        vertex_data(){}
        vertex_data(QVector3D p, QVector3D n):
            position(p), normal(n){}
        QVector3D position;
        QVector3D normal;
    };

    void clearBuffer();
    void loadObj(const QString &pathToObj);
    void drawObj(QOpenGLShaderProgram *program, QOpenGLFunctions *functions);
    void setMaterialObj(QOpenGLShaderProgram *program, materialDataObj material);
    void addSimpleElementFromObjModel(SimpleElement *elementFromObjModel);
    void translateObj(const QVector3D &translateValue);
    void translateElement( const int &elementNum, const QVector3D &translateValue );
    void setElementColor ( const int &elementNum, const QVector3D &colorValue );
    void rotateObj(const QQuaternion &rotateValue);
    bool isNull();
    SimpleElement *getSimpleElementFromObjModel(const int &indexValue);

private:

    QOpenGLBuffer vertexBuffer;
    QOpenGLBuffer indexBuffer;
    QMatrix4x4 modelMatrix;
    QQuaternion mRotate;

    QVector <SimpleElement *> elementsFromObjModel;
    MaterialLibrary materialsFromObjModel;

};

#endif // SPACEOBJECT3D_H
