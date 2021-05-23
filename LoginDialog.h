#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QWidget>

#include "Libs/DataBase/DataBaseStructs.h"

class EnergyOracle;

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QWidget
{
    Q_OBJECT

public:

    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

private:

    void createStartData () noexcept;

private:

    Ui::LoginDialog *ui;

    connectionStruct *currentConnection;

    EnergyOracle *strategyWindow;

private slots:

    void on_pushButton_clicked () noexcept;

    void closeMainDataMenu () noexcept;
};

#endif // LOGINDIALOG_H
