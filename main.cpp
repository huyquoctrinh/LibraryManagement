#include "sqlite3.h"
#include <iostream>
#include<string>
// #include "./src/Database/Database.h"
#include"./src/Password/Password.h"  
using namespace std;

int main()
{
    string filename = "./database/account.db";
    Password a(2,"showmaker","edgvenuoc");
    a.pushToDatabase();
}