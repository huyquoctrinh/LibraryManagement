#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

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

signals:
    void doLogin(QString username, QString userType);

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
