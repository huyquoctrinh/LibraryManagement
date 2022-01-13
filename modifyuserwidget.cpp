#include "modifyuserwidget.h"
#include "ui_modifyuserwidget.h"

#define SUCCESSFUL_ADD "Succesfully adding new user"
#define FAILED_ADD "Failed to add new user"

#define SUCCESSFUL_REMOVE "Succesfully remove user"
#define FAILED_REMOVE "Failed to remove content"

#define SUCCESSFUL_UPDATE "Succesfully update user"
#define FAILED_UPDATE "Failed to update user"

#define FAILED_SEARCH "User not found"

#define INCOMPLETE_FORM "Please fill in required fields"

ModifyUserWidget::ModifyUserWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModifyUserWidget)
{
    ui->setupUi(this);
    ui->rdbBasic->setChecked(true);
    ui->lblStt->setVisible(false);
}

ModifyUserWidget::~ModifyUserWidget()
{
    delete ui;
}

void ModifyUserWidget::on_rdbBasic_toggled(bool checked)
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


void ModifyUserWidget::on_btnSearch_clicked()
{

    string sid = ui->txtSID->text().toStdString();
    Student* student = NULL;

    UserData userDB = DBAccess::getInstance()->getUserDB();
    student = userDB.searchBySID(sid);

    this->_currentStudent = student;
    if (student) {
        ui->txtSID->setEnabled(false);
        QString name = QString::fromStdString(student->getName());
        QString sid = QString::fromStdString(student->getStudentId());

        DateTime dob = student->getDateOfBirth();
        DateTime rnd = student->getRenewalDate();
        QString uni = QString::fromStdString(toValue(student->getUniversity()));
        ui->txtName->setText(name);
        ui->txtSID->setText(sid);
        ui->edtDateOfBirth->setDate(QDate(dob.getYear(), dob.getMonth(), dob.getDay()));
        ui->edtRenewalDate->setDate(QDate(rnd.getYear(), rnd.getMonth(), rnd.getDay()));
        ui->cbbUni->setCurrentText(uni);
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
        ui->lblStt->setVisible(false);


    }
    else
    {
        ui->txtSID->setEnabled(true);
        ui->lblStt->setText(FAILED_SEARCH);
        ui->lblStt->setStyleSheet("QLabel { color : red; }");
        ui->lblStt->setVisible(true);
    }
}


void ModifyUserWidget::on_btnAdd_clicked()
{
    // Student's info
    string name = ui->txtName->text().toStdString();
    bool gender = ui->rdbMale->isChecked() ? false : true;
    QDate dob = ui->edtDateOfBirth->date();
    DateTime dateOfBirth(dob.day(), dob.month(), dob.year());
    QDate rnd = ui->edtRenewalDate->date();
    DateTime renewalDate(rnd.day(), rnd.month(), rnd.year());
    University uni = toKey(ui->cbbUni->currentText().toStdString());
    string sid = ui->txtSID->text().toStdString();

    MemberShip* membership;
    if (ui->rdbBasic->isChecked())
        membership = new Basic();
    else
        membership = new Premium();
    string username = ui->txtUsername->text().trimmed().toStdString();
    string password = ui->txtPassword->text().trimmed().toStdString();

    if (username == "" || password == "" || name == "" || sid == "") {
        ui->lblStt->setText(INCOMPLETE_FORM);
        ui->lblStt->setVisible(true);
        ui->lblStt->setStyleSheet("QLabel { color : red; }");
    }
    else {
        Account account(ui->txtUsername->text().toStdString(), ui->txtPassword->text().toStdString());
        Student newStudent(name, dateOfBirth, gender, account, sid, uni, renewalDate, membership);
        LibMS* libms = LibMS::getInstance();
        bool signUpResult = libms->signUp(&newStudent);
        if (signUpResult) {
            ui->lblStt->setText(SUCCESSFUL_ADD);
            ui->lblStt->setVisible(true);
            ui->lblStt->setStyleSheet("QLabel { color : green; }");
        } else {
            ui->lblStt->setText(FAILED_ADD);
            ui->lblStt->setVisible(true);
            ui->lblStt->setStyleSheet("QLabel { color : red; }");
        }
    }
}


void ModifyUserWidget::on_btnUpdate_clicked()
{
    if (_currentStudent == NULL) {
        ui->lblStt->setText(FAILED_UPDATE);
        ui->lblStt->setVisible(true);
        ui->lblStt->setStyleSheet("QLabel { color : red; }");
        return;
    }
    // Student's info
    string name = ui->txtName->text().toStdString();
    bool gender = ui->rdbMale->isChecked() ? false : true;
    QDate dob = ui->edtDateOfBirth->date();
    DateTime dateOfBirth(dob.day(), dob.month(), dob.year());
    QDate rnd = ui->edtRenewalDate->date();
    DateTime renewalDate(rnd.day(), rnd.month(), rnd.year());
    University uni = toKey(ui->cbbUni->currentText().toStdString());
    string sid = ui->txtSID->text().toStdString();

    MemberShip* membership;
    if (ui->rdbBasic->isChecked())
        membership = new Basic();
    else
        membership = new Premium();
    Account account = this->_currentStudent->getAccount();
    Student newStudent(name, dateOfBirth, gender, account, sid, uni, renewalDate, membership);
    newStudent.setId(this->_currentStudent->getId());
    qInfo() << "Id" << QString::fromStdString(newStudent.getId());

    LibMS* libms = LibMS::getInstance();

    User* user = libms->getCurrentUser();
    Staff* staff = dynamic_cast<Staff*>(user);

    bool updateResult = staff->updateStudent(&newStudent);
    if (updateResult) {
        ui->lblStt->setText(SUCCESSFUL_UPDATE);
        ui->lblStt->setVisible(true);
        ui->lblStt->setStyleSheet("QLabel { color : green; }");
    } else {
        ui->lblStt->setText(FAILED_UPDATE);
        ui->lblStt->setVisible(true);
        ui->lblStt->setStyleSheet("QLabel { color : red; }");
    }

}


void ModifyUserWidget::on_btnDeactivate_clicked()
{

    LibMS* libms = LibMS::getInstance();

    User* user = libms->getCurrentUser();
    Staff* staff = dynamic_cast<Staff*>(user);

    bool updateResult = staff->blockStudent(this->_currentStudent);
    if (updateResult) {
        ui->lblStt->setText(SUCCESSFUL_REMOVE);
        ui->lblStt->setVisible(true);
        ui->lblStt->setStyleSheet("QLabel { color : green; }");
    } else {
        ui->lblStt->setText(FAILED_REMOVE);
        ui->lblStt->setVisible(true);
        ui->lblStt->setStyleSheet("QLabel { color : red; }");
    }
}


void ModifyUserWidget::on_btnNew_clicked()
{
    ui->txtSID->setEnabled(true);
    ui->txtName->setText("");
    ui->txtSID->setText("");
    ui->txtUsername->setText("");
    ui->txtPassword->setText("");
}

