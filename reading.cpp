#include "Reading.h"

string Reading::getTitle()
{
	return _title;
}

string Reading::getAuthors()
{
	return _authors;
}

int Reading::getPublicationYear()
{
	return _publicationYear;
}

void Reading::setTitle(string title)
{
	_title = title;
}

void Reading::setAuthors(string authors)
{
	_authors = authors;
}

void Reading::setPublicationYear(int publicYear)
{
	_publicationYear = publicYear;
}

Reading::Reading() : Content()
{
	_publicationYear = 2000;
}

Reading::Reading(string id, Category cat, Status status, int availCount, int totalCount, string title, string authors, int publicYear): Content(id, cat, status, availCount, totalCount)
{
	_title = title;
	_authors = authors;
	_publicationYear = publicYear;
}

Reading::~Reading()
{
}
