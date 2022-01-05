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

void UserInfoWidget::setContent()
{
    // Display content
    User* currentUser = LibMS::getInstance()->getCurrentUser();

    Student* student = dynamic_cast<Student*>(currentUser);

    QString name = QString::fromStdString(student->getName());
    QString sid = QString::fromStdString(student->getStudentId());

    QString dob = QString::fromStdString(student->getDateOfBirth().toString());
    QString uni = QString::fromStdString(toValue(student->getUniversity()));

    ui->txtName->setText(name);
    ui->txtSID->setText(sid);
    ui->txtDateOfBirth->setText(dob);
    ui->txtUni->setText(uni);
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
