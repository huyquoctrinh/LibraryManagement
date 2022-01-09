#pragma once
#include <string>
#include <vector>

using namespace std;

enum Category {
    catBook,
    catAcademicJournal
};

enum Status {
    sttAvailable,
    sttUnavailable
};

Category Tocat(string cat);
string ToValue(Category category);
bool ToValue(Status stt);
Status ToKey(bool stt);


class Content
{
private:
	string _id;
    Category _category;
    Status _status;
	int _availableCount;
	int _totalCount;
public:
	//Cac phuong thuc khoi tao, huy
	Content();
    Content(string id, Category cat, Status status, int availCount, int totalCount);

    ~Content();
public:
	//Cac getter
	string getId();
    Category getCategory();
    Status getStatus();
	int getAvailableCount();
	int getTotalCount();
    virtual vector<string> getAllData() = 0;

public:
	//Cac setter
	void setId(string);
    void setCategory(Category);
    void setStatus(Status);
	void setAvailableCount(int);
	void setTotalCount(int);

public:
	bool isAvailable();
};
