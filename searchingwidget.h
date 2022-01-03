#ifndef SEARCHINGWIDGET_H
#define SEARCHINGWIDGET_H

#include <QWidget>
#include "bookwidgetitem.h"
#include "Reading.h"
#include "LibMS.h"
#include "DBAccess.h"
#include "SearchingFilter.h"
#include "UserTypeEnum.h"
#include "contentdetailsdialog.h"
#include <vector>
#include <QVector>
#include <QDebug>

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
    QVector<Reading*> _results;

public:
    void displayContentResults(QVector<Reading*> results);

private slots:
    void on_listWidget_currentRowChanged(int currentRow);
    void on_btnSearch_clicked();
    void on_chbJournal_stateChanged(int arg1);
    void on_chbBook_stateChanged(int arg1);

};



#endif // SEARCHINGWIDGET_H
