#include "modifycontentwidget.h"
#include "ui_modifycontentwidget.h"

#define ISBN "ISBN"
#define ISSN "ISSN"

#define SUCCESSFUL_ADD "Succesfully adding new content"
#define FAILED_ADD "Failed to add new content"

#define SUCCESSFUL_REMOVE "Succesfully remove content"
#define FAILED_REMOVE "Failed to remove content"

#define SUCCESSFUL_UPDATE "Succesfully update content"
#define FAILED_UPDATE "Failed to update content"

#define FAILED_SEARCH "Content not found"

ModifyContentWidget::ModifyContentWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModifyContentWidget)
{
    ui->setupUi(this);
    ui->lblStt->setVisible(false);
    ui->rdbJournal->setChecked(true);
}

ModifyContentWidget::~ModifyContentWidget()
{
    delete ui;
}

void ModifyContentWidget::on_btnSearch_clicked()
{
    ContentData contentDB = DBAccess::getInstance()->getContentDB();
    Reading* reading;
    LibMS* libms = LibMS::getInstance();
    if (ui->cbbFilter->currentText() == ISBN) {
        string isbn = ui->txtISBN->text().toStdString();

        Book* book = contentDB.searchByISBN(isbn);
        reading = book;
        if (book != NULL) {
            libms->setViewingReading(book);
            ui->txtPublisher->setText(QString::fromStdString(book->getPublisher()));
            ui->cbbGenre->setCurrentText(QString::fromStdString(book->getGenre()));
            ui->rdbBook->setChecked(true);
            ui->txtISBN->setEnabled(false);
        }

    } else {
        string issn = ui->txtISSN->text().toStdString();

        AcademicJournal* journal = contentDB.searchByISSN(issn);
        reading = journal;

        if (journal != NULL) {
            ui->txtVolume->setText(QString::number(journal->getVolume()));
            ui->txtSubject->setText(QString::fromStdString(journal->getSubject()));
            ui->rdbJournal->setChecked(true);
            ui->txtISSN->setEnabled(false);
        }
    }
    libms->setViewingReading(reading);
    if (libms->getViewingReading() == NULL) {
        ui->lblStt->setText(FAILED_SEARCH);
        ui->lblStt->setStyleSheet("QLabel { color : red; }");
        ui->lblStt->setVisible(true);
    }
    else {
        ui->lblStt->setVisible(false);
        ui->txtTitle->setText(QString::fromStdString(reading->getTitle()));
        ui->txtAuthor->setText(QString::fromStdString(reading->getAuthors()));
        ui->txtPubYear->setText(QString::number(reading->getPublicationYear()));
        ui->txtAvaiCount->setText(QString::number(reading->getAvailableCount()));
        ui->txtTotalCount->setText(QString::number(reading->getTotalCount()));
        if (reading->getStatus()) {
            ui->cbbStatus->setCurrentIndex(0);
        }
        else {
            ui->cbbStatus->setCurrentIndex(1);
        }

    }
}


void ModifyContentWidget::on_btnAdd_clicked()
{
    User* user = LibMS::getInstance()->getCurrentUser();
    Staff* staff = dynamic_cast<Staff*>(user);
    string title = ui->txtTitle->text().trimmed().toStdString();
    string authors = ui->txtAuthor->text().trimmed().toStdString();
    int pubYear = ui->txtPubYear->text().trimmed().toInt();
    Status status = sttAvailable;
    if (ui->cbbStatus->currentText() == "Unavailable")
        status = sttUnavailable;
    int avaiCount = ui->txtAvaiCount->text().trimmed().toInt();
    int totalCount = ui->txtTotalCount->text().trimmed().toInt();
    Content* newContent = NULL;

    string publisher = ui->txtPublisher->text().trimmed().toStdString();
    string isbn = ui->txtISBN->text().trimmed().toStdString();
    string genre = ui->cbbGenre->currentText().toStdString();

    int volume = ui->txtVolume->text().trimmed().toInt();
    string issn = ui->txtISSN->text().trimmed().toStdString();
    string subject = ui->txtSubject->text().trimmed().toStdString();

    if (title == "") {
        ui->lblStt->setText("Please fill in required fields");
        ui->lblStt->setVisible(true);
        ui->lblStt->setStyleSheet("QLabel { color : red; }");
    }
    else {
        if (ui->rdbBook->isChecked() && isbn != "") {
            Book* newBook = new Book(status, avaiCount, totalCount, title, authors, pubYear, publisher, isbn, genre);
            newContent = newBook;
        }
        else if (ui->rdbJournal->isChecked() && issn != "") {
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
}


void ModifyContentWidget::on_btnRemove_clicked()
{
    LibMS* libms = LibMS::getInstance();
    User* user = libms->getCurrentUser();
    Staff* staff = dynamic_cast<Staff*>(user);
    bool removeResult = staff->removeContent(libms->getViewingReading());
    if (removeResult) {
        ui->lblStt->setText(SUCCESSFUL_REMOVE);
        ui->lblStt->setVisible(true);
        ui->lblStt->setStyleSheet("QLabel { color : green; }");
    } else {
        ui->lblStt->setText(FAILED_REMOVE);
        ui->lblStt->setVisible(true);
        ui->lblStt->setStyleSheet("QLabel { color : red; }");
    }
}


void ModifyContentWidget::on_btnUpdate_clicked()
{
    LibMS* libms = LibMS::getInstance();

    User* user = libms->getCurrentUser();
    Staff* staff = dynamic_cast<Staff*>(user);
    string title = ui->txtTitle->text().toStdString();
    string authors = ui->txtAuthor->text().toStdString();
    int pubYear = ui->txtPubYear->text().toInt();
    Status status = sttAvailable;
    if (ui->cbbStatus->currentText() == "Unavailable")
        status = sttUnavailable;
    int avaiCount = ui->txtAvaiCount->text().toInt();
    int totalCount = ui->txtTotalCount->text().toInt();
    Reading* newContent;
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
    newContent->setId(libms->getViewingReading()->getId());
    libms->setViewingReading(newContent);

    qInfo() << "Before calling database";
    bool updateResult = staff->updateContent(libms->getViewingReading());
    if (updateResult) {
        ui->lblStt->setText(SUCCESSFUL_UPDATE);
        ui->lblStt->setVisible(true);
        ui->lblStt->setStyleSheet("QLabel { color : green; }");
    } else {
        ui->lblStt->setText(FAILED_UPDATE);
        ui->lblStt->setVisible(true);
        ui->lblStt->setStyleSheet("QLabel { color : red; }");
    }
}


void ModifyContentWidget::on_rdbJournal_toggled(bool checked)
{
    if (checked) {
        ui->txtVolume->setEnabled(true);
        ui->txtSubject->setEnabled(true);
        ui->txtISSN->setEnabled(true);

        ui->txtISBN->setEnabled(false);
        ui->txtPublisher->setEnabled(false);
        ui->cbbGenre->setEnabled(false);

        ui->cbbFilter->setCurrentText("ISSN");
    }
    else {
        ui->txtVolume->setEnabled(false);
        ui->txtSubject->setEnabled(false);
        ui->txtISSN->setEnabled(false);

        ui->txtISBN->setEnabled(true);
        ui->txtPublisher->setEnabled(true);
        ui->cbbGenre->setEnabled(true);

        ui->cbbFilter->setCurrentText("ISBN");
    }
}


void ModifyContentWidget::on_btnNew_clicked()
{
    LibMS::getInstance()->setViewingReading(NULL);
    ui->txtISSN->setEnabled(true);
    ui->txtISBN->setEnabled(true);
    ui->txtAuthor->setText("");
    ui->txtTitle->setText("");
    ui->txtISBN->setText("");
    ui->txtISSN->setText("");
    ui->txtPubYear->setText("");
    ui->txtPublisher->setText("");
    ui->txtSubject->setText("");
    ui->txtVolume->setText("");
    ui->txtAvaiCount->setText("0");
    ui->txtTotalCount->setText("0");

    on_rdbJournal_toggled(ui->rdbJournal->isChecked());
}

