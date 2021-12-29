#include "User.h"

User::User()
{
}

User::User(string id, string name, DateTime dateOfBirth, Account account) :_id(id), _name(name), dateOfBirth(dateOfBirth), _account(account)
{
}

Content * User::browseContent()
{
	return nullptr;
}

Content User::viewContent()
{
	return Content();
}

bool User::deactivate()
{
	return false;
}

string User::getPermission()
{
	return string();
}

UserType User::getUserType()
{
    return uNone;
}

string User::getId()
{
	return string();
}

string User::getName()
{
	return string();
}

DateTime User::getDateOfBirth()
{
	return DateTime();
}

Account User::getAccount()
{
	return Account();
}

void User::setId(string)
{
}

void User::setName(string)
{
}

void User::setDateOfBirth(DateTime)
{
}

void User::setAccount(Account)
{
}
