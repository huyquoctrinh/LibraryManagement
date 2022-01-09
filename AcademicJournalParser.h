#pragma once
#include "ContentParser.h"

class AcademicJournalParser : ContentParser
{
public:
	bool createContent(Content);
    vector<Content*> readContent();
	bool updateContent(Content);
	bool deleteContent(Content);
};
