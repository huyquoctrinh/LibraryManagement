#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QDebug>
#include <string>
#include "Student.h"
#include "Staff.h"
#include "UniversityEnum.h"
#include "Basic.h"
#include "Premium.h"
#include "LibMS.h"

#define SUCCESSFUL_SIGN_UP "Successful. Please back to login!"
#define FAILED_SIGN_UP "Failed to create a new account!"
#define INCOMPLETE_FORM "Please fill in required fields"
namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private slots:
    void on_btnSignup_clicked();

    void on_btnCreate_clicked();

    void on_btnBackToLogin_clicked();

    void on_btnLogin_clicked();

    void on_rdbBasic_toggled(bool checked);

signals:
    void doLogin(User* loginUser);

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
