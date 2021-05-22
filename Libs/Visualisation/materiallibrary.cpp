#include "materiallibrary.h"

MaterialLibrary::MaterialLibrary()
{

}

void MaterialLibrary::addMaterial(Materials *materialValue){

    if ( !materialValue ) return;

    for (int i = 0; i < materialList.size(); ++i){
        if (materialValue == materialList[i]) return;
    }
    materialList.append(materialValue);

    return;
}

Materials *MaterialLibrary::getMaterial(const quint32 &indexValue){

    if (indexValue >= materialList.size()) return 0;

    return materialList[indexValue];
}

Materials *MaterialLibrary::getMaterial(const QString &materialNameValue){

    for (int i = 0; i < materialList.size(); ++i){
        if (materialNameValue == materialList[i]->getName()) return materialList[i];
    }

    return 0;
}

quint32 MaterialLibrary::getCountMaterials(){

    return materialList.size();
}

void MaterialLibrary::loadMaterialsFromFile(const QString &pathToFileValue){

    QFile materialFile(pathToFileValue);

    if(!materialFile.open(QIODevice::ReadOnly)){
        qDebug() << "error read file";
        return;
    }

    clearMaterials();

    Materials *newMtl = 0;
    QFileInfo fileInfo(pathToFileValue);

    QTextStream inputStream(&materialFile);

    while (!inputStream.atEnd()){
        QString str = inputStream.readLine();
        QStringList list = str.split(" ");
        if (list[0] == "#"){
            continue;
        }
        else if (list[0] == "newmtl"){
            addMaterial(newMtl);
            newMtl = new Materials;
            newMtl->setName(list[1]);
            continue;
        }
        else if (list[0] == "Ns"){
            newMtl->setShines(list[1].toFloat());
            continue;
        }
        else if (list[0] == "Ka"){
            newMtl->setAmbientColor(QVector3D(list[1].toFloat(), list[2].toFloat(), list[3].toFloat()));
            continue;
        }
        else if (list[0] == "Kd"){
            newMtl->setDiffuseColor(QVector3D(list[1].toFloat(), list[2].toFloat(), list[3].toFloat()));
            continue;
        }
        else if (list[0] == "Ks"){
            newMtl->setSpecularColor(QVector3D(list[1].toFloat(), list[2].toFloat(), list[3].toFloat()));
            continue;
        }
        else if (list[0] == "map_Kd"){
            newMtl->setDiffuseMap(QString("%1/%2").arg(fileInfo.absolutePath()).arg(list[1]));
            continue;
        }
    }

    addMaterial(newMtl);

    materialFile.close();
}

void MaterialLibrary::clearMaterials(){

    if (materialList.isEmpty()) return;

    for (int i = 0; i < materialList.size(); ++i){
        delete materialList[i];
    }
    materialList.clear();
    materialList.squeeze();

    return;
}
