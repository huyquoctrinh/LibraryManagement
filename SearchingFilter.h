#ifndef SEARCHINGFILTER_H
#define SEARCHINGFILTER_H

#include "Content.h"
#include "Reading.h"
#include <vector>
#include <string>

using namespace std;

class SearchingFilter
{
private:
    vector<Category> _categories;
    vector<string> _bookGenres;
public:
    SearchingFilter();
    SearchingFilter(vector<Category>, vector<string>);
};

#endif // SEARCHINGFILTER_H
