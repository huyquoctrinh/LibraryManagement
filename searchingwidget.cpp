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

void SearchingWidget::on_listWidget_currentRowChanged(int currentRow)
{
    LibMS::getInstance()->setViewingReading(_results[currentRow]);
    contentDetailsDialog = new ContentDetailsDialog;
    contentDetailsDialog->setModal(true);
    contentDetailsDialog->show();
}

void SearchingWidget::on_btnSearch_clicked()
{
    vector<Category> categories;
    vector<string> bookGenres;
    if (ui->chbBook->isChecked()) categories.push_back(catBook);
    if (ui->chbJournal->isChecked()) categories.push_back(catAcademicJournal);
    else if (!ui->chbJournal->isChecked() && !ui->chbBook->isChecked())
        categories = { catBook, catAcademicJournal };
    if (ui->chbBook->isChecked() || !(ui->chbBook->isChecked() ^ ui->chbJournal->isChecked())) {
        int countGenres = 0;
        if (ui->chbArt->isChecked()) bookGenres.push_back("Art");
        else countGenres++;
        if (ui->chbBiography->isChecked()) bookGenres.push_back("Biography");
        else countGenres++;
        if (ui->chbEconomics->isChecked()) bookGenres.push_back("Economics");
        else countGenres++;
        if (ui->chbMath->isChecked()) bookGenres.push_back("Math");
        else countGenres++;
        if (ui->chbPhilo->isChecked()) bookGenres.push_back("Philosophy");
        else countGenres++;
        if (ui->chbTextbook->isChecked()) bookGenres.push_back("Textbook");
        else countGenres++;
        if (ui->chbScience->isChecked()) bookGenres.push_back("Science");
        else countGenres++;
        if (countGenres == 7)
            bookGenres = { "Book", "AcademicJournal", "Art", "Biography", "Economics", "Math", "Philosophy", "Textbook", "Science"};
    }
    SearchingFilter filter(categories, bookGenres);
    DBAccess* dbaccess = DBAccess::getInstance();
    vector<Reading*> resVec;
    if (ui->cbbSearchBy->currentText() == "Title") {
        //resVec = dbaccess->getContentDB->searchReadingByTitle(ui->txtSearchBar->text().toStdString(), filter);
        resVec ={   new Book("12", sttAvailable, 12, 15, "The Lord of Rings", "J.K.Rowling", 2012, "Springer", "HHF263", "Fiction"),
                    new Book("12", sttAvailable, 12, 15, "The Lord of Rings", "J.K.Rowling", 2012, "Springer", "HHF263", "Fiction"),
                    new Book("12", sttAvailable, 12, 15, "The Lord of Rings", "J.K.Rowling", 2012, "Springer", "HHF263", "Fiction"),
                    new AcademicJournal("11", sttUnavailable, 0, 12, "Journal 1", "Author Tri", 2020, 1, "2525", "Science")};
    }
    else {
        //resVec = dbaccess->getContentDB.searchReadingByAuthors(ui->txtSearchBar->text().toStdString(), filter);
        resVec ={   new Book("12", sttAvailable, 12, 15, "The Alchelmist", "J.K.Rowling", 2012, "Springer", "HHF263", "Fiction"),
                    new Book("12", sttAvailable, 12, 15, "The Alchelmist", "J.K.Rowling", 2012, "Springer", "HHF263", "Fiction"),
                    new Book("12", sttAvailable, 12, 15, "The Alchelmist", "J.K.Rowling", 2012, "Springer", "HHF263", "Fiction"),
                    new AcademicJournal("11", sttUnavailable, 0, 12, "Journal 1", "Author Tri", 2020, 1, "2525", "Science")};
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

