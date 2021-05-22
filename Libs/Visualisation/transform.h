#ifndef TRANSFORM_H
#define TRANSFORM_H

class QQuaternion;
class QVector3D;
class QMatrix4x4;
class QOpenGLShaderProgram;
class QOpenGLFunctions;

class Transform{

public:

    virtual ~Transform() {}
    virtual void rotate(const QQuaternion &rotateValue) = 0;
    virtual void translate(const QVector3D &translateValue) = 0;
    virtual void scale(const float &scaleValue) = 0;
    virtual void setGlobalTransform(const QMatrix4x4 &globalMatrix) = 0;
    virtual void draw(QOpenGLShaderProgram *program, QOpenGLFunctions *functions) = 0;

};


#endif // TRANSFORM_H
