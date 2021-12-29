#pragma once
#include "Content.h"

class ContentParser
{
public:
	virtual bool createContent(Content) = 0;
	virtual Content* readContent() = 0;
	virtual bool updateContent(Content) = 0;
	virtual bool deleteContent(Content) = 0;
};