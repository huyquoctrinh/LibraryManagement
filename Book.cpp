#include "Book.h"

string Book::getPublisher()
{
	return _publisher;
}

string Book::getISBN()
{
	return _ISBN;
}

string Book::getGenre()
{
	return _genre;
}

void Book::setPublisher(string publisher)
{
	_publisher = publisher;
}

void Book::setISBN(string ISBN)
{
	_ISBN = ISBN;
}

void Book::setGenre(string genre)
{
	_genre = genre;
}

Book::Book() :Reading()
{
}

Book::Book(string id, Category cat, Status status, int availCount, int totalCount, string title, string authors, int publicYear, string publisher, string ISBN, string genre)
    : Reading(id, cat, status, availCount, totalCount, title, authors, publicYear)
{
	_publisher = publisher;
	_ISBN = ISBN;
	_genre = genre;
}

Book::~Book()
{

}
