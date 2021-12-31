#include "searchingwidget.h"
#include "ui_searchingwidget.h"

SearchingWidget::SearchingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchingWidget)
{
    ui->setupUi(this);
    displayContentResults(_results);
}

SearchingWidget::~SearchingWidget()
{
    delete ui;
}

void addReadingItem(Reading* reading, Ui::SearchingWidget* ui)
{
    QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->listWidget);
    ui->listWidget->addItem (listWidgetItem);
    BookWidgetItem *theWidgetItem = new BookWidgetItem;
    QString title = QString::fromStdString(reading->getTitle());
    QString category = QString::fromStdString(ToValue(reading->getCategory()));
    QString authors = QString::fromStdString(reading->getAuthors());
    theWidgetItem->setContent(title, category, authors);
    listWidgetItem->setSizeHint (theWidgetItem->sizeHint ());
    ui->listWidget->setItemWidget (listWidgetItem, theWidgetItem);
}

void SearchingWidget::displayContentResults(QVector<Reading*> results)
{
    ui->listWidget->clear();
    for (int i = 0; i < results.size(); i++) {
        addReadingItem(results[i], ui);
    }
}

void SearchingWidget::setCurrentUser(User * user)
{
    _currentUser = user;
}


void SearchingWidget::on_listWidget_currentRowChanged(int currentRow)
{
    contentDetailsDialog = new ContentDetailsDialog;
    contentDetailsDialog->setModal(true);
    contentDetailsDialog->setInfo(_results[currentRow], _currentUser);
    contentDetailsDialog->show();
}

void SearchingWidget::on_btnSearch_clicked()
{
    vector<string> filter(9, ""); // Filter [Book, AcademicJournal, Art, Biography, Economics, Math, Philosophy, Textbook, Science]
    if (ui->chbBook->isChecked()) filter[0] = "Book";
    if (ui->chbJournal->isChecked()) filter[1] = "AcademicJournal";
    if (ui->chbBook->isChecked() || !(ui->chbBook->isChecked() ^ ui->chbJournal->isChecked())) {
        if (ui->chbArt->isChecked()) filter[2] = "Art";
        if (ui->chbBiography->isChecked()) filter[3] = "Biography";
        if (ui->chbEconomics->isChecked()) filter[4] = "Economics";
        if (ui->chbMath->isChecked()) filter[5] = "Math";
        if (ui->chbPhilo->isChecked()) filter[6] = "Philosophy";
        if (ui->chbTextbook->isChecked()) filter[7] = "Textbook";
        if (ui->chbScience->isChecked()) filter[8] = "Science";
    }

    vector<Reading*> resVec;
    if (ui->cbbSearchBy->currentText() == "Title") {
        resVec = Library::searchReadingByTitle(ui->txtSearchBar->text().toStdString(), filter);
    }
    else {
        resVec = Library::searchReadingByAuthors(ui->txtSearchBar->text().toStdString(), filter);
    }
    _results = QVector<Reading*>(resVec.begin(), resVec.end());
    displayContentResults(_results);
}


void SearchingWidget::on_chbJournal_stateChanged(int arg1)
{
    if (ui->chbJournal->isChecked() && !ui->chbBook->isChecked()) {
        ui->grbGenre->setEnabled(false);
    }
    if (!ui->chbJournal->isChecked() && !ui->chbBook->isChecked()) {
        ui->grbGenre->setEnabled(true);
    }
}


void SearchingWidget::on_chbBook_stateChanged(int arg1)
{
    if (ui->chbBook->isChecked()) {
        ui->grbGenre->setEnabled(true);
    }
    else if (ui->chbJournal->isChecked() && !ui->chbBook->isChecked()) {
        ui->grbGenre->setEnabled(false);
    }
    if (!ui->chbJournal->isChecked() && !ui->chbBook->isChecked()) {
        ui->grbGenre->setEnabled(true);
    }

}

