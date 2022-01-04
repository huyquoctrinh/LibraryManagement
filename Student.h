#include<vector>
#include<string>

class User;
class Student;
class UserData;
class Content;
class Reservation;
class ReservationFilter;

class Student:public User{
    private:
        string studentID;
        DateTime renewalDate;
        string memberType;
    public:
        Student(string id, string uname, string password, string fullName, string DateOfBirth,string userType, int gender, string studentId, 
        string renewalDate, string memberType):User(id, uname,password, fullName, DateOfBirth, userType, gender){  
            this->studentID = studentID;
            this->renewalDate = DateTime(DateOfBirth);
            this->memberType = memberType;
        }
        vector<string> getfullInfo();
        bool Reserve(Reservation p);
        vector<Reservation> getReservation(ReservationFilter);
        bool renewMembership();
};