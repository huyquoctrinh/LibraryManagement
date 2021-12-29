#ifndef BORROWEDITEMWIDGET_H
#define BORROWEDITEMWIDGET_H

#include <QWidget>
#include <QDebug>
#include "Reading.h"

namespace Ui {
class BorrowedItemWidget;
}

class BorrowedItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BorrowedItemWidget(QWidget *parent = nullptr);
    ~BorrowedItemWidget();

private:
    Ui::BorrowedItemWidget *ui;

public:
    void setContent(QString title, QString category, QString authors, bool isReturned);
private slots:
    void on_label_4_linkActivated(const QString &link);
};

#endif // BORROWEDITEMWIDGET_H
