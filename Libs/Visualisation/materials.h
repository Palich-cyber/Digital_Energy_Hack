#ifndef MATERIALS_H
#define MATERIALS_H

#include <QString>
#include <QVector3D>
#include <QImage>
#include <QDebug>

class Materials
{
public:
    Materials();
    void setName(const QString &materialNameValue);
    const QString getName() const;
    void setDiffuseColor(const QVector3D &diffuseColorValue);
    const QVector3D getDiffuseColor() const;
    void setAmbientColor(const QVector3D &ambientColorValue);
    const QVector3D getAmbientColor() const;
    void setSpecularColor(const QVector3D &specularColorValue);
    const QVector3D getSpecularColor() const;
    void setShines(const qreal &shinesValue);
    const qreal getShines() const;
    void setDiffuseMap(const QString &diffuseMapValue);
    const QImage getDiffuseMap() const;
    bool isExistedDiffuseMap();

private:
    QString materialName;
    QVector3D diffuseColor,
              ambientColor,
              specularColor;
    qreal shines;
    QImage diffuseMap;
};

#endif // MATERIALS_H
