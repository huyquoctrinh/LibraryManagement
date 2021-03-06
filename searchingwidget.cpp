#include "searchingwidget.h"
#include "ui_searchingwidget.h"

SearchingWidget::SearchingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchingWidget)
{
    ui->setupUi(this);
    displayContentResults(_results);

    on_btnSearch_clicked();
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

    if (ui->chbBook->isChecked()) {
        if (ui->chbArt->isChecked()) bookGenres.push_back("Art");
        if (ui->chbBiography->isChecked()) bookGenres.push_back("Biography");
        if (ui->chbEconomics->isChecked()) bookGenres.push_back("Economics");
        if (ui->chbMath->isChecked()) bookGenres.push_back("Math");
        if (ui->chbPhilo->isChecked()) bookGenres.push_back("Philosophy");
        if (ui->chbTextbook->isChecked()) bookGenres.push_back("Textbook");
        if (ui->chbScience->isChecked()) bookGenres.push_back("Science");
    }

    SearchingFilter filter(categories, bookGenres);
    DBAccess* dbaccess = DBAccess::getInstance();
    ContentData contentDB = dbaccess->getContentDB();
    vector<Reading*> resVec;
    if (ui->txtSearchBar->text().trimmed() == "") {

        resVec = contentDB.searchAllReading(filter);
    }
    else if (ui->cbbSearchBy->currentText() == "Title") {
        resVec = contentDB.searchReadingByTitle(ui->txtSearchBar->text().toStdString(), filter);
    }
    else {
        qInfo() << "Search by authors";
        resVec = contentDB.searchReadingByAuthors(ui->txtSearchBar->text().toStdString(), filter);
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

void SearchingWidget::on_btnAllCategory_clicked()
{
    ui->chbBook->setChecked(true);
    ui->chbJournal->setChecked(true);
}

void SearchingWidget::on_btnAllGenre_clicked()
{
    ui->chbArt->setChecked(true);
    ui->chbBiography->setChecked(true);
    ui->chbEconomics->setChecked(true);
    ui->chbMath->setChecked(true);
    ui->chbPhilo->setChecked(true);
    ui->chbScience->setChecked(true);
    ui->chbTextbook->setChecked(true);
}
