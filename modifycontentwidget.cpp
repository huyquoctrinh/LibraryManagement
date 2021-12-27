#include "modifycontentwidget.h"
#include "ui_modifycontentwidget.h"

ModifyContentWidget::ModifyContentWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModifyContentWidget)
{
    ui->setupUi(this);
}

ModifyContentWidget::~ModifyContentWidget()
{
    delete ui;
}
