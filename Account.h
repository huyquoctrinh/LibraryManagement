#pragma once
#include <string>

using namespace std;

class Account
{
private:
	string _username;
	string _password;
public:
	//Phuong thuc khoi tao, huy
	Account();
	Account(string username, string pass);
public:
    bool changePassword(string currentPassword, string newPassword);
public:
	//Cac getter
	string getUsername();
	string getPassword();
public:
	//Cac setter
	void setUsername(string username);
	void setPassword(string password);
};
