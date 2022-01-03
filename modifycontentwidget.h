#ifndef MODIFYCONTENTWIDGET_H
#define MODIFYCONTENTWIDGET_H

#include <QWidget>
#include "LibMS.h"
#include "DBAccess.h"

namespace Ui {
class ModifyContentWidget;
}

class ModifyContentWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ModifyContentWidget(QWidget *parent = nullptr);
    ~ModifyContentWidget();

private slots:
    void on_btnSearch_clicked();

    void on_btnAdd_clicked();

private:
    Ui::ModifyContentWidget *ui;
};

#endif // MODIFYCONTENTWIDGET_H
