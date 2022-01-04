#include"Staff.h"
#include"UserData.h"
#include"Content.h"
#include"Reservation.h"
#include"ReservationFilter.h"

bool Staff::AddStudent(Student p){
    UserData* tmp = new UserData("Account.csv");
    vector<string> record = p.getfullInfo();
    tmp->addRecord(record);
    return 1;
}

bool Staff::updateContent(Content p){
    vector<string> content = p.getAllData();
    ContentData* tmp = new ContentData("Book.csv");
    tmp->updateRecord(content);
    return 1;
}

bool Staff::removeContent(Content p){
    vector<string> content = p.getAllData();
    ContentData* tmp = new ContentData("Book.csv");
    tmp->deleteRecord(content);
    return 1;
}

bool Staff::addContent(Content p){
    vector<string> content = p.getAllData();
    ContentData* tmp = new ContentData("Book.csv");
    tmp->addRecord(content);
    return 1;
}

bool Staff::blockStudent(Student p){
    vector<string> record = p.getfullInfo();
    UserData* tmp = new UserData("Account.csv");
    tmp->deleteRecord(record);
    return 1;
}

vector<Student> Staff::getStudent(){
    UserData* tmp = new UserData("Account.csv");
    vector<vector<string>> accountList = tmp->getfullDatabase();
    vector<Student> res;
    for (auto row:accountList){
        if (row[6] == "0"){
            string id = row[0];
            string uname = row[1];
            string password = row[2];
            string fullName = row[3];
            string dob = row[4];
            int gender = (stoi(row[5]));
            string userType = row[6];
            string studentID = row[8];
            string renewalDate = row[9];
            string memberType = row[10];
            Student student = Student(id, uname, password, fullName, dob, userType, gender,studentID, renewalDate, memberType);
            res.push_back(student);
        }
    }
    return res;
}

vector<Reservation> getAllReservation(ReservationFilter p){
    ReservationData* tmp = new ReservationData("Reservation.csv");
    return tmp->readAllReservation();
}