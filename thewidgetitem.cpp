#include "thewidgetitem.h"
#include "ui_thewidgetitem.h"

TheWidgetItem::TheWidgetItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TheWidgetItem)
{
    ui->setupUi(this);
}

TheWidgetItem::~TheWidgetItem()
{
    delete ui;
}

void TheWidgetItem::setContent(QString text, QString icon)
{
    ui->lblName->setText(text);
    QPixmap pic(icon);
    ui->icon->setPixmap(pic);
}

void TheWidgetItem::on_pressThisBtn_clicked()
{

}

