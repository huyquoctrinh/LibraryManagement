#include "modifyuserwidget.h"
#include "ui_modifyuserwidget.h"

ModifyUserWidget::ModifyUserWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModifyUserWidget)
{
    ui->setupUi(this);
}

ModifyUserWidget::~ModifyUserWidget()
{
    delete ui;
}
