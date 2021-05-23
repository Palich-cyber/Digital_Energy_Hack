#include <QDebug>

#include "TacticLevel.h"
#include "ui_TacticLevel.h"

TacticLevel::TacticLevel( QWidget *parent, int regionNumValue ) :
    QWidget(parent),
    ui(new Ui::TacticLevel), regionNum ( regionNumValue )
{
    ui->setupUi(this);

    QPixmap pm( qApp->applicationDirPath() + "/Resources/img/Penza all.jpg");

    ui->l_tacticMap->setPixmap(pm);
    ui->l_tacticMap->setScaledContents(true);
}

TacticLevel::~TacticLevel()
{
    delete ui;
}
