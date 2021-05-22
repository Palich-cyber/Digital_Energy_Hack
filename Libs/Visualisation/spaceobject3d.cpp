#include <QStringList>
#include "spaceobject3d.h"

SpaceObject3D::SpaceObject3D() :
    vertexBuffer(QOpenGLBuffer::VertexBuffer) ,indexBuffer(QOpenGLBuffer::IndexBuffer)
{

}

SpaceObject3D::~SpaceObject3D()
{

}

void SpaceObject3D::clearBuffer(){

    if(vertexBuffer.isCreated()) vertexBuffer.destroy();
    if(indexBuffer.isCreated()) indexBuffer.destroy();

    for(int i = 0; i < elementsFromObjModel.size(); ++i){
        delete elementsFromObjModel[i];
        elementsFromObjModel[i] = nullptr;
    }
    elementsFromObjModel.clear();
    elementsFromObjModel.squeeze();

    return;
}

void SpaceObject3D::loadObj(const QString &pathToObj){

    QFile object(pathToObj);

    if(!object.open(QIODevice::ReadOnly)){
        qDebug() << "error read file";
        return;
    }

    QVector <QVector3D> coords,
                        normals;
    QVector <QVector2D> textureCoords;

    QVector <vertex_data_Obj> dataObj;
    QVector <GLuint> indexes;
    SimpleElement *simpleElement = 0;

    QTextStream input(&object);

    while (!input.atEnd()){
        QString str = input.readLine();
        QStringList list = str.split(" ");
        if (list[0] == "#"){
            continue;
        }
        else if (list[0] == "mtllib"){
            // file-material
            QFileInfo fileInfo(pathToObj);
            materialsFromObjModel.loadMaterialsFromFile(QString("%1/%2").arg(fileInfo.absolutePath()).arg(list[1]));
            qDebug() << "file with materials: " << QString("%1/%2").arg(fileInfo.absolutePath()).arg(list[1]);
            for (int i = 0; i < materialsFromObjModel.getCountMaterials(); ++i)
            qDebug() << "file with materials: " << materialsFromObjModel.getMaterial(i)->getName();
            continue;
        }
        else if (list[0] == "v"){
            coords.append(QVector3D(list[1].toFloat(), list[2].toFloat(), list[3].toFloat()));
            continue;
        }
        else if (list[0] == "vt"){
            textureCoords.append(QVector2D(list[1].toFloat(), list[2].toFloat()));
            continue;
        }
        else if (list[0] == "vn"){
            normals.append(QVector3D(list[1].toFloat(), list[2].toFloat(), list[3].toFloat()));
            continue;
        }
        else if (list[0] == "f"){
            for (int i = 1; i <= 3; ++i){
                QStringList vert = list[i].split("/");
                if (vert[1].size() == 0) vert[1] = "1";
                dataObj.append(vertex_data_Obj(coords[vert[0].toLong() - 1], textureCoords[vert[1].toLong() - 1], normals[vert[2].toLong() - 1]));
                indexes.append(indexes.size());
            }
            continue;
        }
        else if (list[0] == "usemtl"){
            qDebug () << "Material name: " << list[1];

            if ( materialsFromObjModel.getMaterial(list[1]) ){
                simpleElement = new SimpleElement;
                simpleElement->init(dataObj, indexes, materialsFromObjModel.getMaterial(list[1]));
                qDebug () << "ambience: " << materialsFromObjModel.getMaterial(list[1])->getAmbientColor();
            }

            if (simpleElement) addSimpleElementFromObjModel(simpleElement);
            //simpleElement = new SimpleElement;
            dataObj.clear();
            indexes.clear();
            continue;
        }
    }

    qDebug () << "Close";
    object.close();

    return;
}

void SpaceObject3D::drawObj(QOpenGLShaderProgram *program, QOpenGLFunctions *functions){

    for (int i = 0; i < elementsFromObjModel.size(); ++i){
        elementsFromObjModel[i]->draw(program, functions);
    }

    return;
}

void SpaceObject3D::setMaterialObj(QOpenGLShaderProgram *program, materialDataObj material){

    program->setUniformValue(program->uniformLocation("u_material_property.ambient"), material.ambient);
    program->setUniformValue(program->uniformLocation("u_material_property.diffuse"), material.diffuse);
    program->setUniformValue(program->uniformLocation("u_material_property.specular"), material.specular);

    return;
}

void SpaceObject3D::addSimpleElementFromObjModel(SimpleElement *elementFromObjModel){

    if (!elementFromObjModel) return;

    for (int i = 0; i < elementsFromObjModel.size(); ++i){
        if (elementFromObjModel == elementsFromObjModel[i]) return;
    }

    elementsFromObjModel.append(elementFromObjModel);

    return;
}

void SpaceObject3D::translateObj(const QVector3D &translateValue){

    for (int i = 0; i < elementsFromObjModel.size(); ++i){
        elementsFromObjModel[i]->translate(translateValue);
    }

    return;
}

void SpaceObject3D::rotateObj(const QQuaternion &rotateValue){

    for (int i = 0; i < elementsFromObjModel.size(); ++i){
        elementsFromObjModel[i]->rotate(rotateValue);

    }

    return;
}

bool SpaceObject3D::isNull(){

    if (materialsFromObjModel.getCountMaterials() == 0) return true;
    else return false;
}

SimpleElement *SpaceObject3D::getSimpleElementFromObjModel(const int &indexValue){

    if (indexValue < elementsFromObjModel.size()) return elementsFromObjModel[indexValue];
    else return 0;
}
