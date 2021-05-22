#ifndef LIGHT3D_H
#define LIGHT3D_H

#include <QVector3D>
#include <QVector4D>
#include <QMatrix4x4>

class Light3D
{
public:
    enum Type{
        Directional = 0,
        Point =1 ,
        Spot =2
    };
    Light3D(const Type &type = Directional);

    void setAmbienceColor(const QVector3D &ambience_color);
    const QVector3D &getAmbienceColor() const;
    void setDiffuseColor(const QVector3D &diffuse_color);
    const QVector3D &getDiffuseColor() const;
    void setSpecularColor(const QVector3D &specular_color);
    const QVector3D &getSpecularColor() const;
    void setPosition(const QVector4D &position);
    const QVector4D &getPosition() const;
    void setDirection(const QVector4D &direction);
    const QVector4D &getDirection() const;
    void setCatoff(const float &catoff);
    const float &getCatoff() const;
    const QMatrix4x4 &getLightMatrix() const;

private:
    QVector3D m_ambience_color;  //отраженный свет
    QVector3D m_diffuse_color;   //свет падающих лучей
    QVector3D m_specular_color;  //свет блика
    QVector4D m_position;
    QVector4D m_direction;
    float m_catoff;
    QMatrix4x4 m_light_matrix;
    int m_type;
};

#endif // LIGHT3D_H
