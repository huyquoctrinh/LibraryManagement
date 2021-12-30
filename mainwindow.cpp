#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //initStaffMenu();
    initGuestMenu();
    _currentUser = NULL;
    //initStudentMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void clearStackedWidget(QStackedWidget* stackedWidget)
{
    while(stackedWidget->count() > 0)
    {
        QWidget* widget = stackedWidget->widget(0);
        stackedWidget->removeWidget(widget);
        widget->deleteLater();
    }
}

void MainWindow::addMenuItem(QVector<QString> itemNames, QVector<QString> itemIcons)
{
    for (int i = 0; i < itemNames.size(); i++) {
        QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->listWidget);
        ui->listWidget->addItem (listWidgetItem);
        TheWidgetItem *theWidgetItem = new TheWidgetItem;
        theWidgetItem->setContent(itemNames[i], itemIcons[i]);
        //BookWidgetItem *theWidgetItem = new BookWidgetItem;
        listWidgetItem->setSizeHint (theWidgetItem->sizeHint ());
        ui->listWidget->setItemWidget (listWidgetItem, theWidgetItem);
    }
}

void MainWindow::initStudentMenu()
{
    ui->listWidget->clear();
    clearStackedWidget(ui->stackedWidget);
    QVector<QString> itemNames;
    itemNames << "Search" << "Borrowed items" << "Account" << "Regulation";
    QVector<QString> itemIcons;
    itemIcons << ":/img/img/icon/search.png" << ":/img/img/icon/book-cart.png" << ":/img/img/icon/account.png" << ":/img/img/icon/regulation.png";
    addMenuItem(itemNames, itemIcons);

    searchingWidget = new SearchingWidget;
    borrowedWidget = new BorrowedWidget;
    userInfoWidget = new UserInfoWidget;
    regulationWidget = new RegulationWidget;
    ui->stackedWidget->insertWidget(0, searchingWidget);
    ui->stackedWidget->insertWidget(1, borrowedWidget);
    ui->stackedWidget->insertWidget(2, userInfoWidget);
    ui->stackedWidget->insertWidget(3, regulationWidget);

    ui->listWidget->setCurrentRow(0);
}


void MainWindow::initGuestMenu()
{
    ui->listWidget->clear();
    clearStackedWidget(ui->stackedWidget);
    QVector<QString> itemNames;
    itemNames << "Search" << "Regulation";
    QVector<QString> itemIcons;
    itemIcons << ":/img/img/icon/search.png" << ":/img/img/icon/regulation.png";
    addMenuItem(itemNames, itemIcons);

    searchingWidget = new SearchingWidget;
    regulationWidget = new RegulationWidget;
    ui->stackedWidget->insertWidget(0, searchingWidget);
    ui->stackedWidget->insertWidget(1, regulationWidget);

    ui->listWidget->setCurrentRow(0);
}

void MainWindow::initStaffMenu()
{
    ui->listWidget->clear();
    clearStackedWidget(ui->stackedWidget);
    QVector<QString> itemNames;
    itemNames << "Search" << "Modify content" << "Modify Student" << "Reservations" << "Regulation";
    QVector<QString> itemIcons;
    itemIcons << ":/img/img/icon/search.png" << ":/img/img/icon/storage.png" << ":/img/img/icon/readers.png" << ":/img/img/icon/reservation.png" << ":/img/img/icon/regulation.png";
    addMenuItem(itemNames, itemIcons);

    searchingWidget = new SearchingWidget;
    modifyContentWidget = new ModifyContentWidget;
    modifyUserWidget = new ModifyUserWidget;
    borrowedWidget = new BorrowedWidget;
    regulationWidget = new RegulationWidget;
    ui->stackedWidget->insertWidget(0, searchingWidget);
    ui->stackedWidget->insertWidget(1, modifyContentWidget);
    ui->stackedWidget->insertWidget(2, modifyUserWidget);
    ui->stackedWidget->insertWidget(3, borrowedWidget);
    ui->stackedWidget->insertWidget(4, regulationWidget);

    ui->listWidget->setCurrentRow(0);
}

void MainWindow::on_listWidget_itemSelectionChanged()
{
    int index = ui->listWidget->currentRow();
    ui->stackedWidget->setCurrentIndex(index);
}

void MainWindow::receiveLogin(User *currentUser)
{
    _currentUser = currentUser;
    if (_currentUser->getUserType() == uStudent) { // Sign in as student
        initStudentMenu();
        //ui->label->setText("Hello Student, " + QString::fromStdString(_currentUser->getAccount().getUsername()));
    }
    else { // Sign in as staff
        initStaffMenu();
        //ui->label->setText("Hello Staff, " + QString::fromStdString(_currentUser->getAccount().getUsername()));
    }
    QIcon icon(":/img/img/icon/logout.png");
    ui->btnLogInOut->setIcon(icon);
    ui->btnLogInOut->setText("Log out");
}

void MainWindow::on_btnLogInOut_clicked()
{
    if (_currentUser == NULL) {
        loginDialog = new LoginDialog();
        loginDialog->setModal(true);
        loginDialog->setAttribute(Qt::WA_DeleteOnClose);
        loginDialog->show();
        connect(loginDialog, SIGNAL(doLogin(User*)), this, SLOT(receiveLogin(User*)));
    }
    else
    {
        QIcon icon(":/img/img/icon/login.png");
        ui->btnLogInOut->setIcon(icon);
        ui->btnLogInOut->setText("Log in/Sign up");
        delete _currentUser;
        _currentUser = NULL;
        initGuestMenu();
    }
}
