#ifndef STRTEGYINFORMER_H
#define STRTEGYINFORMER_H

#include <QWidget>

namespace Ui {
class StrtegyInformer;
}

class StrtegyInformer : public QWidget
{
    Q_OBJECT

public:
    explicit StrtegyInformer(QWidget *parent = 0);
    ~StrtegyInformer();

private:
    Ui::StrtegyInformer *ui;
};

#endif // STRTEGYINFORMER_H
