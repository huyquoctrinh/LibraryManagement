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

User::User(const User &other)
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

string User::getId() const
{
    return _id;
}

string User::getName() const
{
    return _name;
}

DateTime User::getDateOfBirth() const
{
    return _dateOfBirth;
}

Account User::getAccount() const
{
    return _account;
}

void User::setId(string id)
{
    _id = id;
}

void User::setName(string name)
{
    _name = name;
}

void User::setDateOfBirth(DateTime dateOfBirth)
{
    _dateOfBirth = dateOfBirth;
}

void User::setAccount(Account account)
{
    _account = account;
}

string toValue(UserType type)
{
    switch(type) {
    case uStudent: return "Student";
    case uStaff: return "Staff";
        return "None";
    }
}
