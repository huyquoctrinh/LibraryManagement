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
	DateTime dateOfBirth;
	Account _account;
	UserType _userType;
public:
	//Cac phuong thuc khoi tao, huy
	User();
	User(string id, string name, DateTime dateOfBirth, Account account);
public:
	Content* browseContent();
	Content viewContent();
	bool deactivate();
	virtual string getPermission();
    virtual UserType getUserType();
	//Cac getter
public:
	string getId();
	string getName();
	DateTime getDateOfBirth();
	Account getAccount();
	//Cac setter
public:
	void setId(string);
	void setName(string);
	void setDateOfBirth(DateTime);
	void setAccount(Account);
};
