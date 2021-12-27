#ifndef READING_H
#define READING_H

#include <QWidget>
#include "content.h"

class Reading : public Content
{
private:
    QString _title;
    QString _authors;

public:
    Reading();
    Reading(const QString &id, const QString &category, const QString &status, int availableCount, int totalCount, const QString &title, const QString &authors);
    const QString &title() const;
    void setTitle(const QString &newTitle);
    const QString &authors() const;
    void setAuthors(const QString &newAuthors);
};

#endif // READING_H
