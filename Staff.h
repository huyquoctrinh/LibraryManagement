// #include"UserData.h"
#include<vector>
#include<string>

class User;
class Student;
class UserData;
class Content;
class Reservation;
class ReservationFilter;

class Staff:public User{
    public:
        Staff(string id, string uname, string password, string fullName, string DateOfBirth,string userType, int gender):User(id,
        uname, password, fullName, DateOfBirth, userType, gender ){};
    public:
        bool AddStudent(Student p);
        bool updateContent(Content p);
        bool removeContent(Content p);
        bool addContent(Content p);
        bool blockStudent(Student p);
        vector<Student> getStudent();
        vector<Reservation> getAllReservation(ReservationFilter p);

};

#pragma once