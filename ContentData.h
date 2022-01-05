#ifndef CONTENTDATA_H
#define CONTENTDATA_H

#include "Book.h"
#include "AcademicJournal.h"
#include "Database.h"
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
    bool addContent(Content* content);
    bool updateContent(Content* content);
    bool deleteContent(Content* content);
};

#endif // CONTENTDATA_H
