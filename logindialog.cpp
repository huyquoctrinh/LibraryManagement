#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->lblFailedLogin->setVisible(false);
    ui->lblSignUpStt->setVisible(false);

}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_btnSignup_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QDate today = QDate::currentDate();
    ui->edtRenewalDate->setDate(today.addDays(30));
    ui->edtRenewalDate->setEnabled(false);
    ui->rdbBasic->setChecked(true);
}


void LoginDialog::on_btnCreate_clicked()
{
    // Student's info
    string name = ui->txtName->text().toStdString();
    bool gender = ui->rdbMale->isChecked() ? false : true;
    QDate dob = ui->edtDateOfBirth->date();
    DateTime dateOfBirth(dob.day(), dob.month(), dob.year());
    QDate rnd = ui->edtRenewalDate->date();
    DateTime renewalDate(rnd.day(), rnd.month(), rnd.year());
    University uni = toKey(ui->txtUni->text().toStdString());
    string sid = ui->txtSID->text().toStdString();

    MemberShip* membership;
    if (ui->rdbBasic->isChecked())
        membership = new Basic();
    else
        membership = new Premium();
    Account account(ui->txtNewUsername->text().toStdString(), ui->txtNewPassword->text().toStdString());
    Student newStudent(name, dateOfBirth, gender, account, sid, uni, renewalDate, membership);

    // Sign up
    bool signUpResult = LibMS::getInstance()->signUp(&newStudent);

    if (signUpResult) // successfully create an account
    {
        ui->lblSignUpStt->setText(SUCCESSFUL_SIGN_UP);
        ui->lblSignUpStt->setVisible(true);
    }
    else
    {
        ui->lblSignUpStt->setText(FAILED_SIGN_UP);
        ui->lblSignUpStt->setVisible(true);
    }
}


void LoginDialog::on_btnBackToLogin_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void LoginDialog::on_btnLogin_clicked()
{
    string username = ui->txtUsername->text().toStdString();
    string password = ui->txtPass->text().toStdString();

    Account loginAccount(username, password);
    User* loginUser = LibMS::getInstance()->signIn(loginAccount);
    if (loginUser == NULL)  // Failed to login
    {
        ui->lblFailedLogin->setVisible(true);
    }
    else // Successfully login
    {
        emit doLogin(loginUser);
        this->close();
    }
}

void LoginDialog::on_rdbBasic_toggled(bool checked)
{
    if (checked) {
        Basic tmp;
        ui->lblFee->setText(QString::number(tmp.getFee()) + "$");
    }
    else {
        Premium tmp;
        ui->lblFee->setText(QString::number(tmp.getFee()) + "$");
    }
}

