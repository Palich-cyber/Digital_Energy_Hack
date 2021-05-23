#ifndef SIMPLEELEMENT_H
#define SIMPLEELEMENT_H

#include <QVector>
#include <QVector3D>
#include <QVector2D>
#include <QMatrix4x4>
#include <QOpenGLTexture>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions>
#include <QFile>
#include <QFileInfo>

#include "transform.h"
#include "materials.h"

struct vertex_data_Obj{
    vertex_data_Obj(){}
    vertex_data_Obj(QVector3D p, QVector2D t, QVector3D n):
        position(p), tex_coord(t), normal(n){}
    QVector3D position;
    QVector2D tex_coord;
    QVector3D normal;
};

struct materialDataObj{
    materialDataObj(){}
    materialDataObj(QVector3D p, QVector3D t, QVector3D n):
        ambient(p), diffuse(t), specular(n){}
    QVector3D ambient;
    QVector3D diffuse;
    QVector3D specular;
};

class SimpleElement final : public Transform
{
public:
    SimpleElement();
    ~SimpleElement();

    void init(const QVector<vertex_data_Obj> &vert_data, const QVector<GLuint> &indexes, Materials *materialValue);
    void clearBuffer();
    void setMaterialObj( materialDataObj materialValue );

    //From class Transform
    void draw(QOpenGLShaderProgram *program, QOpenGLFunctions *functions);
    void rotate(const QQuaternion &rotate_value);
    void translate(const QVector3D &translate_value);
    void scale(const float &scale_value);
    void setGlobalTransform(const QMatrix4x4 &global_matrix);

private:

    QOpenGLTexture *texture;
    QOpenGLBuffer vertexBuffer;
    QOpenGLBuffer indexBuffer;

    QMatrix4x4 modelMatrix;
    QVector3D mTranslate;
    QQuaternion mRotate;
    QMatrix4x4 m_globalTransform;

    Materials *material;
};

#endif // SIMPLEELEMENT_H
