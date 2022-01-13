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
    string name = ui->txtName->text().trimmed().toStdString();
    bool gender = ui->rdbMale->isChecked() ? false : true;
    QDate dob = ui->edtDateOfBirth->date();
    DateTime dateOfBirth(dob.day(), dob.month(), dob.year());
    QDate rnd = ui->edtRenewalDate->date();
    DateTime renewalDate(rnd.day(), rnd.month(), rnd.year());
    University uni = toKey(ui->cbbUni->currentText().trimmed().toStdString());
    string sid = ui->txtSID->text().trimmed().toStdString();

    MemberShip* membership;
    if (ui->rdbBasic->isChecked())
        membership = new Basic();
    else
        membership = new Premium();

    string username = ui->txtNewUsername->text().trimmed().toStdString();
    string password = ui->txtNewPassword->text().trimmed().toStdString();
    string password2 = ui->txtNewPassword_2->text().trimmed().toStdString();
    if (password != password2) {
        ui->lblSignUpStt->setText("Not match password!");
        ui->lblSignUpStt->setVisible(true);
        ui->lblSignUpStt->setStyleSheet("QLabel { color : red; }");
    }
    else if (username == "" || password == "" || name == "" || sid == "") {
        ui->lblSignUpStt->setText(INCOMPLETE_FORM);
        ui->lblSignUpStt->setVisible(true);
        ui->lblSignUpStt->setStyleSheet("QLabel { color : red; }");
    }
    else {
        Account account(username, password);
        Student newStudent(name, dateOfBirth, gender, account, sid, uni, renewalDate, membership);
        // Sign up
        bool signUpResult = LibMS::getInstance()->signUp(&newStudent);

        if (signUpResult) // successfully create an account
        {
            ui->lblSignUpStt->setText(SUCCESSFUL_SIGN_UP);
            ui->lblSignUpStt->setVisible(true);
            ui->lblSignUpStt->setStyleSheet("QLabel { color : green; }");
            ui->txtName->setText("");
            ui->txtSID->setText("");
            ui->txtNewUsername->setText("");
            ui->txtNewPassword->setText("");
        }
        else
        {
            ui->lblSignUpStt->setText(FAILED_SIGN_UP);
            ui->lblSignUpStt->setVisible(true);
            ui->lblSignUpStt->setStyleSheet("QLabel { color : red; }");
        }
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

