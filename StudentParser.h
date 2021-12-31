#pragma once
#include "UserParser.h"

class StudentParser :public UserParser
{
private:
public:
    bool createUser(User*);
	User* readUser();
    bool updateUser(User*);
	bool deleteUser();
};
