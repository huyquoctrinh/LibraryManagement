#ifndef CONTENTDATA_H
#define CONTENTDATA_H

#include "Book.h"
#include "AcademicJournal.h"
#include "Database.h"
#include "SearchingFilter.h"
#include <QDebug>

class ContentData:public Database
{
private:
    vector<vector<string>> contentDatabase;
public:
    ContentData(string databasename):Database(databasename){
        this->contentDatabase = getRecord();
    };
public:
    Book* searchByISBN(string isbn);
    AcademicJournal* searchByISSN(string issn);
    Reading* searchReadingByTitle(string keyword, SearchingFilter filter);
    vector<Reading*> searchReadingByAuthors(string keyword, SearchingFilter filter);
    bool addContent(Content* content);
    bool updateContent(Content* content);
    bool deleteContent(Content* content);
    Content* getContentbyID(string id);
};

#endif // CONTENTDATA_H
