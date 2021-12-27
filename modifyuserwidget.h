#ifndef MODIFYUSERWIDGET_H
#define MODIFYUSERWIDGET_H

#include <QWidget>

namespace Ui {
class ModifyUserWidget;
}

class ModifyUserWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ModifyUserWidget(QWidget *parent = nullptr);
    ~ModifyUserWidget();

private:
    Ui::ModifyUserWidget *ui;
};

#endif // MODIFYUSERWIDGET_H
