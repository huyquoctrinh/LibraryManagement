#ifndef MODIFYCONTENTWIDGET_H
#define MODIFYCONTENTWIDGET_H

#include <QWidget>

namespace Ui {
class ModifyContentWidget;
}

class ModifyContentWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ModifyContentWidget(QWidget *parent = nullptr);
    ~ModifyContentWidget();

private:
    Ui::ModifyContentWidget *ui;
};

#endif // MODIFYCONTENTWIDGET_H
