#ifndef USERINFOWIDGET_H
#define USERINFOWIDGET_H

#include <QWidget>
#include <QDebug>
#include "LibMS.h"

namespace Ui {
class UserInfoWidget;
}

class UserInfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UserInfoWidget(QWidget *parent = nullptr);
    ~UserInfoWidget();

private:
    Ui::UserInfoWidget *ui;

public:
    void setContent();
private slots:
    void on_btnChangePassword_clicked();
};

#endif // USERINFOWIDGET_H
