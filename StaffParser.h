#pragma once
#include "UserParser.h"

class StaffParser :public UserParser
{
private:
public:
    bool createUser(User*);
	User* readUser();
    bool updateUser(User*);
	bool deleteUser();
};
