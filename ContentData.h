#ifndef CONTENTDATA_H
#define CONTENTDATA_H

#include "Book.h"
#include "AcademicJournal.h"

class ContentData
{
public:
    ContentData();
public:
    Book* searchByISBN(string isbn);
    AcademicJournal* searchByISSN(string issn);
    bool addContent(Content* content);
    bool updateContent(Content* content);
    bool deleteContent(Content* content);
};

#endif // CONTENTDATA_H
