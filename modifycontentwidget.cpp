#include "modifycontentwidget.h"
#include "ui_modifycontentwidget.h"

#define ISBN "ISBN"
#define ISSN "ISSN"

#define SUCCESSFUL_ADD "Succesfully adding new content"
#define FAILED_ADD "Failed to add new content"

ModifyContentWidget::ModifyContentWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModifyContentWidget)
{
    ui->setupUi(this);
    ui->lblStt->setVisible(false);
}

ModifyContentWidget::~ModifyContentWidget()
{
    delete ui;
}

void ModifyContentWidget::on_btnSearch_clicked()
{
    /*
     * ContentData contentDB = DBAccess::getInstance()->getContentDB();
     */
    LibMS* libms = LibMS::getInstance();
    if (ui->cbbFilter->currentText() == ISBN) {
        string isbn = ui->txtISBN->text().toStdString();
        /*
         * Book* book = contentDB.searchByISBN(isbn);
         * libms->setViewingReading(book);
         * ui->txtPublisher->setText(QString::fromStdString(book->getPublisher()));
         * ui->cbbGenre->setCurrentText(QString::fromStdString(book->getGenre()));
        */
    } else {
        string issn = ui->txtISSN->text().toStdString();
        /*
         * AcademicJournal* journal = contentDB.searchByISSN(issn);
         * libms->setViewingReading(journal);
         * ui->txtVolume->setText(QString::number(journal->getVolume()));
         * ui->txtSubject->setText(QString::fromStdString(journal->getSubject()));
        */
    }


}


void ModifyContentWidget::on_btnAdd_clicked()
{
    User* user = LibMS::getInstance()->getCurrentUser();
    Staff* staff = dynamic_cast<Staff*>(user);
    string title = ui->txtTitle->text().toStdString();
    string authors = ui->txtAuthor->text().toStdString();
    int pubYear = ui->txtPubYear->text().toInt();
    Status status = sttAvailable;
    if (ui->cbbStatus->currentText() == "Unavailable")
        status = sttUnavailable;
    int avaiCount = ui->txtAvaiCount->text().toInt();
    int totalCount = ui->txtTotalCount->text().toInt();
    Content* newContent;
    if (ui->rdbBook->isChecked()) {
        string publisher = ui->txtPublisher->text().toStdString();
        string isbn = ui->txtISBN->text().toStdString();
        string genre = ui->cbbGenre->currentText().toStdString();
        Book* newBook = new Book(status, avaiCount, totalCount, title, authors, pubYear, publisher, isbn, genre);
        newContent = newBook;
    }
    else {
        int volume = ui->txtVolume->text().toInt();
        string issn = ui->txtISSN->text().toStdString();
        string subject = ui->txtSubject->text().toStdString();
        AcademicJournal* newJournal = new AcademicJournal(status, avaiCount, totalCount, title, authors, pubYear, volume, issn, subject);
        newContent = newJournal;
    }
    bool addResult = staff->addContent(newContent);
    if (addResult) {
        ui->lblStt->setText(SUCCESSFUL_ADD);
        ui->lblStt->setVisible(true);
        ui->lblStt->setStyleSheet("QLabel { color : green; }");
    } else {
        ui->lblStt->setText(FAILED_ADD);
        ui->lblStt->setVisible(true);
        ui->lblStt->setStyleSheet("QLabel { color : red; }");
    }
}

