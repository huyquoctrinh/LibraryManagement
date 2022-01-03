#include"Database.h"
#include<iostream>
using namespace std;
int main(){
    Database a = Database("Account.csv");
    vector<vector<string>> out = a.getRecord();
    string k = "3, Thao, 6";
    vector<string> tmp = Database::Parse(k,", ");
    a.updateRecord(tmp);
}