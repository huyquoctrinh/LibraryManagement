#pragma once
#include "User.h"

class UserParser
{
public:
	virtual bool createUser(User) = 0;
	virtual User* readUser() = 0;
	virtual bool updateUser(User) = 0;
	virtual bool deleteUser() = 0;
};