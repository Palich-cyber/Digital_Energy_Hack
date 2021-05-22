#include <QMatrix4x4>
#include "Scene.h"
#include "QDebug"

Scene::Scene( QWidget *parent ) :
    QOpenGLWidget( parent ), mSpaceObject( new SpaceObject3D ),
    mCamera ( new Camera3D ), mLight ( new Light3D(Light3D::Directional) )
{

    this->setFocusPolicy(Qt::StrongFocus);

    mCamera->translate(QVector3D(0.0F, 0.0F, -10.0F));

    mLight->setPosition(QVector4D(1.0F, 1.0F, 1.0F, 1.0F));
    mLight->setDirection(QVector4D(-1.0F, -1.0F, -1.0F, 0.0F));
    mLight->setCatoff(20.0F/180.0F*M_PI);
}

Scene::~Scene()
{

    delete mCamera;
    delete mSpaceObject;
    delete mLight;
}

void Scene::initializeGL(){

    initializeOpenGLFunctions();
    initglSettins();
    initShaders();

    if ( mSpaceObject->isNull() ) mSpaceObject->loadObj( pathToModel );

    return;
}

void Scene::paintGL(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if ( !mProgram.bind() ) return;

    mProgram.setUniformValue( mProgram.uniformLocation( "projection_matrix" ), projection_matrix );
    mProgram.setUniformValue( mProgram.uniformLocation( "u_light_position" ), QVector4D( 0.0, 0.0, 0.0, 1.0 ) );
    mProgram.setUniformValue( mProgram.uniformLocation( "u_light_power" ), 2.0F );

    mCamera->draw( &mProgram );

    mSpaceObject->drawObj( &mProgram, context()->functions() );

    mProgram.release();

    return;
}

void Scene::resizeGL( int w, int h ){

    float aspect = float(w) / float(h);
    projection_matrix.setToIdentity();
    projection_matrix.perspective( 45, aspect, 0.01F, 50000.0F );

    return;
}

void Scene::initShaders(){

    if ( !mProgram.addShaderFromSourceFile( QOpenGLShader::Vertex, ":/Resources/Shaders/vShader.glsl" ) ) return;
    if ( !mProgram.addShaderFromSourceFile( QOpenGLShader::Fragment, ":/Resources/Shaders/fShader.glsl" ) ) return;
    if ( !mProgram.link() ){

        qWarning( "Error: unable to link a shader program." );
        return;
    }

    return;
}

void Scene::initglSettins(){

    glEnable( GL_DOUBLEBUFFER );
    glEnable( GL_RGBA );
    glEnable( GL_DEPTH_TEST );
    glEnable( GL_CULL_FACE );
    glClearColor( 179.0F / 255.0F, 218.0F / 255.0F, 254.0F / 255.0F, 218.0F / 255.0F );

    return;
}

void Scene::mousePressEvent(QMouseEvent *pe){

    if( pe->buttons() == Qt::LeftButton ) ptrMousePosition = QVector2D( pe->localPos() );
    pe->accept();

    return;
}

void Scene::mouseMoveEvent(QMouseEvent *pe){

    if( pe->buttons() != Qt::LeftButton ) return;

    QVector2D diff = QVector2D( pe->localPos() ) - ptrMousePosition;
    ptrMousePosition = QVector2D( pe->localPos() );

    float angle = diff.length() / 2;
    QVector3D axis = QVector3D( diff.y(), diff.x(), 0.0F );
    mCamera->rotate(QQuaternion::fromAxisAndAngle(axis, angle));



    update();
}

void Scene::wheelEvent(QWheelEvent *pe){

    if ( pe->delta() > 0 ) mCamera->translate( QVector3D( 0.0F, 0.0F, 1.0F ) );
    else if ( pe->delta() < 0 ) mCamera->translate( QVector3D( 0.0F, 0.0F, -1.0F ) );

    update();

    return;
}

void Scene::keyPressEvent(QKeyEvent *pe){

    switch ( pe->key() )
    {
     case Qt::Key_Up:
        mCamera->translate( QVector3D( 0.0F, 10.0F, 0.0F ) );
     break;

     case Qt::Key_Down:
        mCamera->translate( QVector3D( 0.0F, -10.0F, 0.0F ) );
     break;

     case  Qt::Key_Left:
        mCamera->translate( QVector3D( 10.0F, 0.0F, 0.0F ) );
     break;

     case Qt::Key_Right:
        mCamera->translate( QVector3D( -10.0F, 0.0F, 0.0F ) );
     break;
    }

    update();

    return;
}

void  Scene::RotateMyObject(float x, float y, float z)
{
    mSpaceObject->rotateObj(QQuaternion::fromEulerAngles(x,y,z));
}

void Scene::setModel( const QString &pathToModelValue ) noexcept{

    pathToModel = pathToModelValue;

    return;
}

