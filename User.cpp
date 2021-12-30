#include "User.h"

bool User::getGender() const
{
    return _gender;
}

void User::setGender(bool newGender)
{
    _gender = newGender;
}

User::User()
{
}

User::User(string name, DateTime dateOfBirth, bool gender, Account account) : _name(name), _dateOfBirth(dateOfBirth), _gender(gender), _account(account)
{
}

User::~User() {

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

string User::getId() const
{
	return string();
}

string User::getName() const
{
	return string();
}

DateTime User::getDateOfBirth() const
{
	return DateTime();
}

Account User::getAccount() const
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
