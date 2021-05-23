#ifndef TACTICLEVEL_H
#define TACTICLEVEL_H

#include <QWidget>

namespace Ui {
class TacticLevel;
}

class TacticLevel : public QWidget
{

    Q_OBJECT

public:

    explicit TacticLevel( QWidget *parent = 0, int regionNumValue = 0 );
    ~TacticLevel();

private:

    Ui::TacticLevel *ui;

    int regionNum;

};

#endif // TACTICLEVEL_H
