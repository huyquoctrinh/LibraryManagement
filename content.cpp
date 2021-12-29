#include "Content.h"

string ToValue(Category category) {
    switch(category) {
        case catBook: return "Book";
        case catAcademicJournal: return "Academic Journal";
    }
    return "";
}

bool ToValue(Status stt) {
   switch(stt) {
       case sttAvailable: return true;
       case sttUnvailable: return false;
   }
   return false;
}

Content::Content(): _availableCount(0), _totalCount(0)
{
}

Content::Content(string id, Category cat, Status status, int availCount, int totalCount)
{
	_id = id;
	_category = cat;
	_status = status;
	_availableCount = availCount;
	_totalCount = totalCount;
}

Content::~Content()
{
}

string Content::getId()
{
	return _id;
}

Category Content::getCategory()
{
	return _category;
}

Status Content::getStatus()
{
	return _status;
}

int Content::getAvailableCount()
{
	return _availableCount;
}

int Content::getTotalCount()
{
	return _totalCount;
}

void Content::setId(string id)
{
	_id = id;
}

void Content::setCategory(Category cat)
{
	_category = cat;
}

void Content::setStatus(Status status)
{
	_status = status;
}

void Content::setAvailableCount(int availCount)
{
	_availableCount = availCount;
}

void Content::setTotalCount(int totalCount)
{
	_totalCount = totalCount;
}

bool Content::isAvailable()
{
	return _availableCount > 0;
}
