#include "StrtegyInformer.h"
#include "ui_StrtegyInformer.h"

StrtegyInformer::StrtegyInformer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StrtegyInformer)
{
    ui->setupUi(this);
}

StrtegyInformer::~StrtegyInformer()
{
    delete ui;
}
