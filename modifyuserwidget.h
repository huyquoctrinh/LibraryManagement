#ifndef MODIFYUSERWIDGET_H
#define MODIFYUSERWIDGET_H

#include <QWidget>
#include "Student.h"
#include "LibMS.h"
#include "Basic.h"
#include "Premium.h"

namespace Ui {
class ModifyUserWidget;
}

class ModifyUserWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ModifyUserWidget(QWidget *parent = nullptr);
    ~ModifyUserWidget();

private slots:
    void on_rdbBasic_toggled(bool checked);

    void on_btnSearch_clicked();

    void on_btnAdd_clicked();

    void on_btnUpdate_clicked();

    void on_btnDeactivate_clicked();

private:
    Ui::ModifyUserWidget *ui;
    Student* _currentStudent;
};

#endif // MODIFYUSERWIDGET_H
