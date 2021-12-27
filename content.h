#ifndef CONTENT_H
#define CONTENT_H

#include <QWidget>

class Content
{
private:
    QString _id;
    QString _category;
    QString _status;
    int _availableCount;
    int _totalCount;

public:
    Content();
    Content(const QString &id, const QString &category, const QString &status, int availableCount, int totalCount);

    const QString &id() const;
    void setId(const QString &newId);
    const QString &category() const;
    void setCategory(const QString &newCategory);
    const QString &status() const;
    void setStatus(const QString &newStatus);
    int availableCount() const;
    void setAvailableCount(int newAvailableCount);
    int totalCount() const;
};

#endif // CONTENT_H
