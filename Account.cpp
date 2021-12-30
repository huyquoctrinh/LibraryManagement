#include "Account.h"

Account::Account()
{
}

Account::Account(string username, string pass) : _username(username), _password(pass)
{
}

bool Account::changePassword(string newPassword)
{
    //
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
