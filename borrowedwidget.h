#ifndef BORROWEDWIDGET_H
#define BORROWEDWIDGET_H

#include <QWidget>
#include "reading.h"
#include "borroweditemwidget.h"

namespace Ui {
class BorrowedWidget;
}

class BorrowedWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BorrowedWidget(QWidget *parent = nullptr);
    ~BorrowedWidget();

private:
    Ui::BorrowedWidget *ui;

public:
    void displayContentResults(QVector<Reading> results);

};

#endif // BORROWEDWIDGET_H
