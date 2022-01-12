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

vector<string> SearchingFilter::getGenre(){
    return this->_bookGenres;
}

vector<string> SearchingFilter::getCat(){
    vector<string> res;
    for (auto i:this->_categories){
        res.push_back(ToValue(i));
    }
    return res;
}