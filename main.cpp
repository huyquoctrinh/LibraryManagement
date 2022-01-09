#include "mainwindow.h"
#include "signupwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //LoginWindow w;
    MainWindow w;
    w.show();
    return a.exec();
}
