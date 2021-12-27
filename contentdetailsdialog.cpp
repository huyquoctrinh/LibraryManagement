#include "contentdetailsdialog.h"
#include "ui_contentdetailsdialog.h"

ContentDetailsDialog::ContentDetailsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContentDetailsDialog)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

ContentDetailsDialog::~ContentDetailsDialog()
{
    delete ui;
}

void ContentDetailsDialog::setInfo(QString title, QString usertype)
{
    ui->lblTitle->setText(title);
    ui->btnBorrow->setEnabled(usertype == "Student");
}



void ContentDetailsDialog::on_btnCancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void ContentDetailsDialog::on_btnReserve_clicked()
{
    if (true) // Successfully reserve
    {
        ui->stackedWidget->setCurrentIndex(0);
    }
}


void ContentDetailsDialog::on_btnBorrow_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

