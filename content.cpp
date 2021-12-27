#include "content.h"

const QString &Content::id() const
{
    return _id;
}

void Content::setId(const QString &newId)
{
    _id = newId;
}

const QString &Content::category() const
{
    return _category;
}

void Content::setCategory(const QString &newCategory)
{
    _category = newCategory;
}

const QString &Content::status() const
{
    return _status;
}

void Content::setStatus(const QString &newStatus)
{
    _status = newStatus;
}

int Content::availableCount() const
{
    return _availableCount;
}

void Content::setAvailableCount(int newAvailableCount)
{
    _availableCount = newAvailableCount;
}

int Content::totalCount() const
{
    return _totalCount;
}

Content::Content()
{

}

Content::Content(const QString &id, const QString &category, const QString &status, int availableCount, int totalCount) : _id(id),
    _category(category),
    _status(status),
    _availableCount(availableCount),
    _totalCount(totalCount)
{}
