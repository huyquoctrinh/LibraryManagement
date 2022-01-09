#ifndef THEWIDGETITEM_H
#define THEWIDGETITEM_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QSlider>
#include <QProgressBar>
#include <QLabel>

namespace Ui {
class TheWidgetItem;
}

class TheWidgetItem : public QWidget
{
    Q_OBJECT

public:
    explicit TheWidgetItem(QWidget *parent = 0);
    ~TheWidgetItem();

private slots:
    void on_pressThisBtn_clicked();

private:
    Ui::TheWidgetItem *ui;

public:
    void setContent(QString, QString);
};

#endif // THEWIDGETITEM_H
