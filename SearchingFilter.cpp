#include "SearchingFilter.h"

SearchingFilter::SearchingFilter()
{
    _categories = { catBook, catAcademicJournal };
    _bookGenres = { "Book", "AcademicJournal", "Art", "Biography", "Economics", "Math", "Philosophy", "Textbook", "Science"};
}

SearchingFilter::SearchingFilter(vector<Category> categories, vector<string> bookGenres)
{
    _categories = categories;
    _bookGenres = bookGenres;
}
