#include "sqlite3.h"
#include <iostream>
#include<string>
using namespace std;

/* 
    int res = sqlite3_open(filename,&db); to open and then connect to db
    callback(): raise error

    rule to run: connect to db then query to db and return result if success
*/

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

//2 parameter to parse: 
// filename: file of db
// sql: Query command
bool Query(const char* filename, string sql){
    sqlite3* db;
    char* zErrMsg = 0;
    int res = sqlite3_open(filename,&db);
    if (res){
        return 0;
    }

    const char* c = sql.c_str();
    res = sqlite3_exec(db, c, callback, 0, &zErrMsg);
    if( res != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        sqlite3_close(db);
        return 0;
    } else {
        fprintf(stdout, "Records created successfully\n");
        sqlite3_close(db);
        return 1;
    }
}

int main()
{
    const char* filename = "databaseName.db";
    string sql = "INSERT or IGNORE INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
                "VALUES (1, 'Huy', 18, 'HCM', 500000 ); ";
    cout<<Query(filename,sql)<<endl;

}