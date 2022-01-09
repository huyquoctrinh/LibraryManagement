#ifndef REGULATIONWIDGET_H
#define REGULATIONWIDGET_H

#include <QWidget>

namespace Ui {
class RegulationWidget;
}

class RegulationWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RegulationWidget(QWidget *parent = nullptr);
    ~RegulationWidget();

private:
    Ui::RegulationWidget *ui;
};

#endif // REGULATIONWIDGET_H
