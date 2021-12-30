#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QListWidget>
#include <QListWidgetItem>
#include <QDebug>

#include "thewidgetitem.h"
#include "userinfowidget.h"
#include "searchingwidget.h"
#include "bookwidgetitem.h"
#include "borrowedwidget.h"
#include "signupwindow.h"
#include "regulationwidget.h"
#include "modifycontentwidget.h"
#include "modifyuserwidget.h"

#include "logindialog.h"
#include "User.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_listWidget_itemSelectionChanged();

    void receiveLogin(User* currentUser);

    void on_btnLogInOut_clicked();

private:
    Ui::MainWindow *ui;
    UserInfoWidget* userInfoWidget;
    BorrowedWidget* borrowedWidget;
    SearchingWidget* searchingWidget;
    RegulationWidget* regulationWidget;
    ModifyContentWidget* modifyContentWidget;
    ModifyUserWidget* modifyUserWidget;

    LoginDialog* loginDialog = NULL;

public:
    User* _currentUser;

private:
    void addMenuItem(QVector<QString>, QVector<QString>);
    void initStudentMenu();
    void initGuestMenu();
    void initStaffMenu();

};
#endif // MAINWINDOW_H
