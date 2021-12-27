#ifndef CONTENTDETAILSDIALOG_H
#define CONTENTDETAILSDIALOG_H

#include <QDialog>

namespace Ui {
class ContentDetailsDialog;
}

class ContentDetailsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ContentDetailsDialog(QWidget *parent = nullptr);
    ~ContentDetailsDialog();

public:
    void setInfo(QString title, QString usertype);
    void setUsertype(QString usertype);

private slots:
    void on_btnCancel_clicked();

    void on_btnReserve_clicked();

    void on_btnBorrow_clicked();

private:
    Ui::ContentDetailsDialog *ui;
};

#endif // CONTENTDETAILSDIALOG_H
