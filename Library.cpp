#include "Library.h"

Content * Library::loadContents()
{
	return nullptr;
}

Library::Library()
{
	_contents = NULL;
	_contentCount = 0;
}

Library::Library(Content * contents, int contentCount)
{
	_contentCount = contentCount;
	_contents = new Content[_contentCount];
	

	for (int i = 0; i < _contentCount; ++i)
		_contents[i] = contents[i];
}

Library::Library(const Library& other)
{
	_contentCount = other._contentCount;
	_contents = new Content[_contentCount];
	
	for (int i = 0; i < _contentCount; ++i)
		_contents[i] = other._contents[i];
}

Library::~Library()
{
	if (_contents)
		delete _contents;
}

Library& Library::operator=(const Library& other)
{
	if (&other != this)
	{
		if (_contents)
			delete _contents;
		_contentCount = other._contentCount;
		_contents = new Content[_contentCount];
		

		for (int i = 0; i < _contentCount; ++i)
			_contents[i] = other._contents[i];
	}
	return *this;
}

Content * Library::getContents()
{
	return _contents;
}

int Library::getContentCount()
{
	return _contentCount;
}

void Library::setContents(Content *)
{
}

void Library::setContentCount(int)
{
}
