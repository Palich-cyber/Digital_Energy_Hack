#include "materials.h"

Materials::Materials()
{

}

void Materials::setName(const QString &materialNameValue){

    materialName = materialNameValue;

    return;
}

const QString Materials::getName() const{

    return materialName;
}

void Materials::setDiffuseColor(const QVector3D &diffuseColorValue){

    diffuseColor = diffuseColorValue;

    return;
}

const QVector3D Materials::getDiffuseColor() const{

    return diffuseColor;
}

void Materials::setAmbientColor(const QVector3D &ambientColorValue){

    ambientColor = ambientColorValue;

    return;
}

const QVector3D Materials::getAmbientColor() const{

    return ambientColor;
}

void Materials::setSpecularColor(const QVector3D &specularColorValue){

    specularColor = specularColorValue;

    return;
}

const QVector3D Materials::getSpecularColor() const{

    return specularColor;
}

void Materials::setShines(const qreal &shinesValue){

    shines = shinesValue;

    return;
}

const qreal Materials::getShines() const{

    return shines;
}

void Materials::setDiffuseMap(const QString &diffuseMapValue){

    diffuseMap = QImage(diffuseMapValue);
    qDebug () << "path image is " << diffuseMapValue;
    return;
}

const QImage Materials::getDiffuseMap() const{

    return diffuseMap;
}

bool Materials::isExistedDiffuseMap(){

    if (diffuseMap.isNull()) return false;
    return true;
}
