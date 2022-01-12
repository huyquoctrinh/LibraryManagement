#include "userinfowidget.h"
#include "ui_userinfowidget.h"

#include <QMessageBox>

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

void UserInfoWidget::setContent()
{
    // Display content
    User* currentUser = LibMS::getInstance()->getCurrentUser();

    Student* student = dynamic_cast<Student*>(currentUser);

    QString name = QString::fromStdString(student->getName());
    QString sid = QString::fromStdString(student->getStudentId());

    QString dob = QString::fromStdString(student->getDateOfBirth().toString());
    QString uni = QString::fromStdString(toValue(student->getUniversity()));

    QString username = QString::fromStdString(student->getAccount().getUsername());
    ui->txtName->setText(name);
    ui->txtSID->setText(sid);
    ui->txtDateOfBirth->setText(dob);
    ui->txtUni->setText(uni);
    ui->txtUsername->setText(username);
    if (student->getGender())
        ui->rdbFemale->setChecked(true);
    else
        ui->rdbMale->setChecked(true);

    if (student->getMemberShip()->getTypename() == "Basic")
        ui->rdbBasic->setChecked(true);
    else
        ui->rdbPremium->setChecked(true);

    QString fee = QString::number(student->getMemberShip()->getFee());
    ui->lblFee->setText(fee + "$");
}

void UserInfoWidget::on_btnChangePassword_clicked()
{
    User* currentUser = LibMS::getInstance()->getCurrentUser();
    string currentPass = ui->txtCurrentPass->text().toStdString();
    string newPass = ui->txtNewPass->text().toStdString();
    bool changeResult = currentUser->getAccount().changePassword(currentPass, newPass);
    QMessageBox msgBox;
    if (changeResult) {
        msgBox.setText("Successfully change password!");
    }
    else {
        msgBox.setText("Failed to change password!");
    }
    msgBox.exec();
}

