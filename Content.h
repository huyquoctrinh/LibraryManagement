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
	vector<string> getAllData(){
		vector<string> res;
		res.push_back(this->_id);
		res.push_back(ToValue(this->getCategory()));
		res.push_back(to_string(ToValue(this->getStatus())));
		res.push_back(to_string(this->_availableCount));
		res.push_back(to_string(this->_totalCount));
        return res;
	}

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
