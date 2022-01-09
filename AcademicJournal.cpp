#include "AcademicJournal.h"

int AcademicJournal::getVolume()
{
	return _volume;
}

string AcademicJournal::getISSN()
{
	return _ISSN;
}

string AcademicJournal::getSubject()
{
	return _subject;
}

void AcademicJournal::setVolume(int volume)
{
	_volume = volume;
}

void AcademicJournal::setISSN(string ISSN)
{
	_ISSN = ISSN;
}

void AcademicJournal::setSubject(string subject)
{
	_subject = subject;
}

AcademicJournal::AcademicJournal() :_volume(0)
{
}

AcademicJournal::AcademicJournal(string id, Status status, int availCount, int totalCount, string title, string authors, int publicYear, int volume, string ISSN, string subject)
    : Reading(id, catAcademicJournal, status, availCount, totalCount, title, authors, publicYear)
{
	_volume = volume;
	_ISSN = ISSN;
    _subject = subject;
}

AcademicJournal::AcademicJournal(Status status, int availCount, int totalCount, string title, string authors, int publicYear, int volume, string ISSN, string subject)
    : Reading("0", catAcademicJournal, status, availCount, totalCount, title, authors, publicYear)
{
    _volume = volume;
    _ISSN = ISSN;
    _subject = subject;
}


AcademicJournal::~AcademicJournal()
{
}

vector<string> AcademicJournal::getAllData()
{
    vector<string> res;
    res.push_back(this->getId());
    res.push_back(this->_ISSN);
    res.push_back("Journal");
    res.push_back(this->_subject);
    res.push_back(this->getTitle());
    res.push_back(this->getAuthors());
    res.push_back(to_string(this->getPublicationYear()));
    res.push_back(to_string(this->_volume));
    res.push_back(to_string(this->getAvailableCount()));
    res.push_back(to_string(this->getTotalCount()));
    return res;
}
