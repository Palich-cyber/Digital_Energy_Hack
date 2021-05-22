#ifndef SCENE_H
#define SCENE_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLContext>
#include <GL/gl.h>
#include <qmath.h>

// users
#include "QKeyEvent"
#include "camera3d.h"
#include "transform.h"
#include "light3d.h"
#include "spaceobject3d.h"
#include "sceneconstants.h"

class Scene : public QOpenGLWidget, protected QOpenGLFunctions
{

    Q_OBJECT

public:

    explicit Scene( QWidget *parent = 0 );
    ~Scene();

    void deleteOldScene();
    void initializeGL();
    void paintGL();
    void RotateMyObject(float x, float y, float z);
    void setModel ( const QString &pathToModelValue ) noexcept;

private:

    void resizeGL( int w, int h );
    void initShaders();
    void initglSettins();

    SpaceObject3D *mSpaceObject = nullptr;
    QOpenGLShaderProgram mProgram;
    Camera3D *mCamera = nullptr;
    Light3D *mLight = nullptr;

    GLfloat nSca;
    QMatrix4x4 projection_matrix;
    QQuaternion rotation;

    int m_vertexAttr;
    int m_projection_matrix;
    int m_constColor;

    QString pathToModel;

    QVector2D ptrMousePosition;

protected:
    void mousePressEvent(QMouseEvent *pe);
    void mouseMoveEvent(QMouseEvent *pe);
    void wheelEvent(QWheelEvent *pe);
    void keyPressEvent(QKeyEvent *pe);
};

#endif // SCENE_H
