#ifndef USERDATA_H
#define USERDATA_H

#include <string>

using namespace std;

class Student;

class UserData
{
public:
    UserData();
public:
    Student* searchBySID(string sid);
    bool addStudent(Student* student);
    bool updateStudent(Student* student);
    bool deleteStudent(Student* student);
};

#endif // USERDATA_H
