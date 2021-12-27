#include "userinfowidget.h"
#include "ui_userinfowidget.h"

UserInfoWidget::UserInfoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserInfoWidget)
{
    ui->setupUi(this);
}

UserInfoWidget::~UserInfoWidget()
{
    delete ui;
}
