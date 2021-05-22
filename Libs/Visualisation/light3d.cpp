#include "light3d.h"
#include <math.h>

Light3D::Light3D(const Type &type) :
    m_ambience_color(1.0F, 1.0F, 1.0F),
    m_diffuse_color(1.0F, 1.0F, 1.0F),
    m_specular_color(1.0F, 1.0F, 1.0F),
    m_position(0.0F, 0.0F, 0.0F, 1.0F),
    m_direction(0.0F, 0.0F, -1.0F, 0.0F),
    m_catoff(M_PI/2),
    m_type(type)
{
    m_light_matrix.setToIdentity();
    m_light_matrix.lookAt(m_position.toVector3D(),
                         (m_position+m_direction).toVector3D(),
                          QVector3D(m_direction.x(), m_direction.z(), -m_direction.y()));
}

void Light3D::setAmbienceColor(const QVector3D &ambience_color)
{
    m_ambience_color = ambience_color;
}

const QVector3D &Light3D::getAmbienceColor() const
{
    return m_ambience_color;
}

void Light3D::setDiffuseColor(const QVector3D &diffuse_color)
{
    m_diffuse_color = diffuse_color;
}

const QVector3D &Light3D::getDiffuseColor() const
{
    return m_diffuse_color;
}

void Light3D::setSpecularColor(const QVector3D &specular_color)
{
    m_specular_color = specular_color;
}

const QVector3D &Light3D::getSpecularColor() const
{
    return m_specular_color;
}

void Light3D::setPosition(const QVector4D &position)
{
    m_position = position;
    m_light_matrix.setToIdentity();
    m_light_matrix.lookAt(m_position.toVector3D(),
                         (m_position+m_direction).toVector3D(),
                          QVector3D(m_direction.x(), m_direction.z(), -m_direction.y()));
}

const QVector4D &Light3D::getPosition() const
{
    return m_position;
}

void Light3D::setDirection(const QVector4D &direction)
{
    m_direction = direction.normalized();
    m_light_matrix.setToIdentity();
    m_light_matrix.lookAt(m_position.toVector3D(),
                         (m_position+m_direction).toVector3D(),
                          QVector3D(m_direction.x(), m_direction.z(), -m_direction.y()));
}

const QVector4D &Light3D::getDirection() const
{
    return m_direction;
}

void Light3D::setCatoff(const float &catoff)
{
    m_catoff = catoff;
}

const float &Light3D::getCatoff() const
{
    return m_catoff;
}

const QMatrix4x4 &Light3D::getLightMatrix() const
{
    return m_light_matrix;
}
