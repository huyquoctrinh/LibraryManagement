#ifndef BOOKWIDGETITEM_H
#define BOOKWIDGETITEM_H

#include <QWidget>

namespace Ui {
class BookWidgetItem;
}

class BookWidgetItem : public QWidget
{
    Q_OBJECT

public:
    explicit BookWidgetItem(QWidget *parent = nullptr);
    ~BookWidgetItem();

private:
    Ui::BookWidgetItem *ui;

public:
    void setContent(QString title, QString category, QString authors);
};

#endif // BOOKWIDGETITEM_H
