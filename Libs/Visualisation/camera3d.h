#ifndef CAMERA3D_H
#define CAMERA3D_H

#include <QQuaternion>
#include <QVector3D>
#include <QMatrix4x4>
#include <QOpenGLShaderProgram>

#include"transform.h"


class Camera3D final : public Transform
{

public:

    Camera3D();
    void rotate(const QQuaternion &rotateValue) noexcept override;
    void translate(const QVector3D &translateValue) noexcept override;
    void scale(const float &scaleValue) noexcept override;
    void setGlobalTransform(const QMatrix4x4 &globalMatrix) noexcept override;
    void draw(QOpenGLShaderProgram *program, QOpenGLFunctions *functions = 0) noexcept override;

    void update() noexcept;

private:

    float       mScale;
    QQuaternion mRotate;
    QVector3D   mTranslate;
    QMatrix4x4  mGlobalTransform;
    QMatrix4x4  mViewMatrix;
};

#endif // CAMERA3D_H
