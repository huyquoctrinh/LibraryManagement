#pragma once
#include <string>
#include "Content.h"
#include "Account.h"
#include "DateTime.h"
#include "UserTypeEnum.h"

using namespace std;

class User
{
private:
	string _id;
	string _name;
    DateTime _dateOfBirth;
    bool _gender;
	Account _account;
	UserType _userType;
public:
	//Cac phuong thuc khoi tao, huy
	User();
    User(string name, DateTime dateOfBirth, bool gender, Account account);
    virtual ~User();
public:
	Content* browseContent();
	Content viewContent();
	bool deactivate();
	virtual string getPermission();
    virtual UserType getUserType();
	//Cac getter
public:
    string getId() const;
    string getName() const;
    DateTime getDateOfBirth() const;
    Account getAccount() const;
    bool getGender() const;
	//Cac setter
public:
	void setId(string);
	void setName(string);
	void setDateOfBirth(DateTime);
    void setAccount(Account);
    void setGender(bool newGender);
};
