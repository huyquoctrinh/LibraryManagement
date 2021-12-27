#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_btnSignup_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void LoginDialog::on_btnCreate_clicked()
{
    if (true) // successfully create an account
    {
        ui->stackedWidget->setCurrentIndex(0);
    }
}


void LoginDialog::on_btnBackToLogin_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void LoginDialog::on_btnLogin_clicked()
{
    QString username = ui->txtUsername->text();
    QString password = ui->txtPass->text();

    if (true)  // Successfully login
    {
        emit doLogin(username, password);
        this->close();
    }
}

