#include "camera3d.h"

Camera3D::Camera3D():
    mScale(1.0F), mTranslate(QVector3D(0.0F, 0.0F, 0.0F))
{
    mGlobalTransform.setToIdentity();
}

void Camera3D::rotate(const QQuaternion &rotateValue) noexcept{

    mRotate *= rotateValue;

    update();

    return;
}

void Camera3D::translate(const QVector3D &translateValue) noexcept{

    mTranslate += translateValue;

    update();

    return;
}

void Camera3D::scale(const float &scaleValue) noexcept{

    mScale *= scaleValue;

    update();

    return;
}

void Camera3D::setGlobalTransform(const QMatrix4x4 &globalMatrix) noexcept{

    mGlobalTransform = globalMatrix;

    update();

    return;
}

void Camera3D::draw(QOpenGLShaderProgram *program, QOpenGLFunctions *functions) noexcept{

    if (!functions) program->setUniformValue(program->uniformLocation("view_matrix"), mViewMatrix);

    return;
}

void Camera3D::update() noexcept{

    mViewMatrix.setToIdentity();
    mViewMatrix.translate(mTranslate);
    mViewMatrix.rotate(mRotate);

    mViewMatrix.scale(mScale);
    mViewMatrix = mViewMatrix*mGlobalTransform.inverted();

    return;
}
