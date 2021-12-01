#include "sqlite3.h"
#include <iostream>
#include<string>
#include "./src/Database/Database.h"
using namespace std;



int main()
{
    string filename = "./database/databaseName.db";
    Database f = Database(filename);
    string sql = "INSERT or IGNORE INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
                "VALUES (1, 'Huy', 18, 'HCM', 500000 ); ";
    f.Query(sql);

}