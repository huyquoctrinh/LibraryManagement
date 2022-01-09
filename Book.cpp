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

Book::Book(string id, Status status, int availCount, int totalCount, string title, string authors, int publicYear, string publisher, string ISBN, string genre)
    : Reading(id, catBook, status, availCount, totalCount, title, authors, publicYear)
{
	_publisher = publisher;
	_ISBN = ISBN;
    _genre = genre;
}

Book::Book(Status status, int availCount, int totalCount, string title, string authors, int publicYear, string publisher, string ISBN, string genre)
    : Reading("0", catBook, status, availCount, totalCount, title, authors, publicYear)
{
    _publisher = publisher;
    _ISBN = ISBN;
    _genre = genre;
}

Book::~Book()
{

}

vector<string> Book::getupdateContentData(){
	vector<string> tmp = this->getAllData();
	vector<string> res;
	res.push_back(tmp[0]);
	res.push_back(this->_ISBN);
	res.push_back(tmp[2]);
	res.push_back(this->_genre);
	res.push_back(this->getTitle());
	res.push_back(this->getAuthors());
	res.push_back(this->_publisher);
	res.push_back(to_string(this->getPublicationYear()));
	res.push_back(to_string(this->getAvailableCount()));
	res.push_back(to_string(this->getTotalCount()));
	return res;
}

