#ifndef SEARCHINGWIDGET_H
#define SEARCHINGWIDGET_H

#include <QWidget>
#include "bookwidgetitem.h"
#include "reading.h"
#include "contentdetailsdialog.h"

namespace Ui {
class SearchingWidget;
}

class SearchingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SearchingWidget(QWidget *parent = nullptr);
    ~SearchingWidget();

private:
    Ui::SearchingWidget *ui;
    ContentDetailsDialog *contentDetailsDialog;

public:
    QVector<Reading> results;

public:
    void displayContentResults(QVector<Reading> results);

private slots:
    void on_listWidget_currentRowChanged(int currentRow);
};

#endif // SEARCHINGWIDGET_H
