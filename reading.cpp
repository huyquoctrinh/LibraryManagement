#include "reading.h"

const QString &Reading::title() const
{
    return _title;
}

void Reading::setTitle(const QString &newTitle)
{
    _title = newTitle;
}

const QString &Reading::authors() const
{
    return _authors;
}

void Reading::setAuthors(const QString &newAuthors)
{
    _authors = newAuthors;
}

Reading::Reading()
{

}

Reading::Reading(const QString &id, const QString &category, const QString &status, int availableCount,
                 int totalCount, const QString &title, const QString &authors)
    : Content(id, category, status, availableCount, totalCount)
{
    this->_title = title;
    this->_authors = authors;
}
