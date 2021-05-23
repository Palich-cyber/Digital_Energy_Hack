#include "simpleelement.h"

SimpleElement::SimpleElement() :
    vertexBuffer(QOpenGLBuffer::VertexBuffer) ,indexBuffer(QOpenGLBuffer::IndexBuffer), texture(0),
    material(0)
{

}

SimpleElement::~SimpleElement(){

    if(vertexBuffer.isCreated()) vertexBuffer.destroy();
    if(indexBuffer.isCreated()) indexBuffer.destroy();

    delete material;
    material = nullptr;

    delete texture;
    texture = nullptr;

    return;
}

void SimpleElement::init(const QVector<vertex_data_Obj> &vert_data, const QVector<GLuint> &indexes, Materials *materialValue){

    if(vertexBuffer.isCreated()) vertexBuffer.destroy();
    if(indexBuffer.isCreated()) indexBuffer.destroy();
    if(texture!=0){
        if(texture->isCreated()){
           delete texture;
           texture = 0;
        }
    }

    if(!vertexBuffer.create()) return;
    vertexBuffer.bind();
    vertexBuffer.allocate(vert_data.constData(), vert_data.size()*sizeof(vertex_data_Obj));
    vertexBuffer.release();

    if(!indexBuffer.create()) return;
    indexBuffer.bind();
    indexBuffer.allocate(indexes.constData(), indexes.size()*sizeof(GLuint));
    indexBuffer.release();

    material = materialValue;
    if (!material) return;
    if ( !material->getDiffuseMap().isNull() )
    texture = new QOpenGLTexture(material->getDiffuseMap().mirrored());
    qDebug () << "ambience: " << material->getAmbientColor();
    qDebug () << "specular: " << material->getSpecularColor();
    qDebug () << "diffuse: " << material->getDiffuseColor();
    if ( !texture ) return;
    if ( !texture->isCreated() ) return;

    return;
}

void SimpleElement::clearBuffer(){

    if(vertexBuffer.isCreated()) vertexBuffer.destroy();
    if(indexBuffer.isCreated()) indexBuffer.destroy();

    return;
}

void SimpleElement::setMaterialObj( materialDataObj materialValue ){

    if (material){

        delete material;
        material = nullptr;
    }

    material = new Materials;
    material->setAmbientColor( materialValue.ambient );
    material->setSpecularColor( materialValue.specular );
    material->setDiffuseColor( materialValue.diffuse );

    return;
}

void SimpleElement::draw(QOpenGLShaderProgram *program, QOpenGLFunctions *functions){

    if(!vertexBuffer.isCreated() || !indexBuffer.isCreated()) return;

    QMatrix4x4 normalMatrix;
    normalMatrix = modelMatrix.inverted();

    glEnable(GL_DEPTH_TEST);

//    if (texture){
//        texture->bind();
//        program->setUniformValue("u_texture", 0);
//        program->setUniformValue(program->uniformLocation("u_material_property.ambient"), material->getAmbientColor());
//        program->setUniformValue(program->uniformLocation("u_material_property.diffuse"), material->getDiffuseColor());
//        program->setUniformValue(program->uniformLocation("u_material_property.specular"), material->getSpecularColor());
//        program->setUniformValue("texture_mode", true);
//        program->setUniformValue("model_matrix", modelMatrix);
//        program->setUniformValue(program->uniformLocation("u_normal_matrix"), normalMatrix);

//        vertexBuffer.bind();

//        int offset = 0;

//        int vert_loc = program->attributeLocation("vertexAttr");
//        program->enableAttributeArray(vert_loc);
//        program->setAttributeBuffer(vert_loc, GL_FLOAT, offset, 3, sizeof(vertex_data_Obj));

//        offset += sizeof(QVector3D);

//        int text_loc = program->attributeLocation("textureAttr");
//        program->enableAttributeArray(text_loc);
//        program->setAttributeBuffer(text_loc, GL_FLOAT, offset, 2, sizeof(vertex_data_Obj));

//        offset += sizeof(QVector2D);

//        int norm_loc = program->attributeLocation("normalAttr");
//        program->enableAttributeArray(norm_loc);
//        program->setAttributeBuffer(norm_loc, GL_FLOAT, offset, 3, sizeof(vertex_data_Obj));

//        indexBuffer.bind();
//        functions->glDrawElements(GL_TRIANGLES, indexBuffer.size(), GL_UNSIGNED_INT, 0);

//        program->disableAttributeArray(vert_loc);
//        program->disableAttributeArray(text_loc);
//        program->disableAttributeArray(norm_loc);

//        texture->release();
//        vertexBuffer.release();
//        indexBuffer.release();
//    }

//    else{
        program->setUniformValue("texture_mode", true); // false
        program->setUniformValue("model_matrix", modelMatrix);
       // program->setUniformValue("isConstColor", true); // none
        program->setUniformValue("constColor", QColor(Qt::gray));
        program->setUniformValue(program->uniformLocation("u_material_property.ambient"), material->getAmbientColor());
        qDebug () << "ambience color is "<< material->getAmbientColor();
        program->setUniformValue(program->uniformLocation("u_material_property.diffuse"), material->getDiffuseColor());
        program->setUniformValue(program->uniformLocation("u_material_property.specular"), material->getSpecularColor());
        program->setUniformValue(program->uniformLocation("u_normal_matrix"), normalMatrix);

        vertexBuffer.bind();

        int offset = 0;

        int vertLoc = program->attributeLocation("vertexAttr");
        program->enableAttributeArray(vertLoc);
        program->setAttributeBuffer(vertLoc, GL_FLOAT, offset, 3, sizeof(vertex_data_Obj));

        offset += sizeof(QVector3D);

        int text_loc = program->attributeLocation("textureAttr");
        program->enableAttributeArray(text_loc);
        program->setAttributeBuffer(text_loc, GL_FLOAT, offset, 2, sizeof(vertex_data_Obj));

        offset += sizeof(QVector2D);

        int normLoc = program->attributeLocation("normalAttr");
        program->enableAttributeArray(normLoc);
        program->setAttributeBuffer(normLoc, GL_FLOAT, offset, 3, sizeof(vertex_data_Obj));

        indexBuffer.bind();
        glLineWidth(10.0);
        functions->glDrawElements(GL_TRIANGLES, indexBuffer.size(), GL_UNSIGNED_INT, 0);

        program->disableAttributeArray(vertLoc);
        program->disableAttributeArray(normLoc);

        vertexBuffer.release();
        indexBuffer.release();
//    }

    glDisable(GL_DEPTH_TEST);

    return;
}

void SimpleElement::rotate(const QQuaternion &rotate_value){

    mRotate *= rotate_value;
    modelMatrix.setToIdentity();
    modelMatrix.rotate(QQuaternion::fromAxisAndAngle(0.0F, 0.0F, 1.0F, -23.26F));
    modelMatrix.rotate(QQuaternion::fromAxisAndAngle(1.0F, 0.0F, 0.0F, -90.0F));
    modelMatrix.rotate(QQuaternion::fromAxisAndAngle(0.0F, 0.0F, 1.0F, 180.0F));
    modelMatrix.translate(mTranslate);
    modelMatrix.rotate(mRotate);

    return;
}

void SimpleElement::translate(const QVector3D &translate_value){

    mTranslate = translate_value;

    modelMatrix.setToIdentity();
//    modelMatrix.rotate(QQuaternion::fromAxisAndAngle(0.0F, 0.0F, 1.0F, -23.26F));
//    modelMatrix.rotate(QQuaternion::fromAxisAndAngle(1.0F, 0.0F, 0.0F, -90.0F));
//    modelMatrix.rotate(QQuaternion::fromAxisAndAngle(0.0F, 0.0F, 1.0F, 180.0F));
    modelMatrix.translate(mTranslate);
    modelMatrix.rotate(mRotate);

    return;
}

void SimpleElement::scale(const float &scale_value)
{

}

void SimpleElement::setGlobalTransform(const QMatrix4x4 &global_matrix)
{

}
