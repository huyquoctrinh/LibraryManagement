#include "Account.h"
#include "Database.h"
Account::Account()
{
}

Account::Account(string username, string pass) : _username(username), _password(pass)
{
}

bool Account::changePassword(string currentPassword, string newPassword)
{
	if (newPassword.length()<6){
        return 0;
    }
	Database* tmp = new Database("Account.csv");
	vector<vector<string>> recordData = tmp->getRecord();
	for (auto row:recordData){
        if (row[1] == this->_username && row[2] == currentPassword){
			row[2] = newPassword;
			this->_password = newPassword;
			tmp->updateRecord(row);
			return 1; 
		}
	}
	return false;
}

string Account::getUsername()
{
	return _username;
}

string Account::getPassword()
{
	return _password;
}

void Account::setUsername(string username)
{
	_username = username;
}

void Account::setPassword(string password)
{
	_password = password;
}
