#include<iostream>
#include<string>
#include "sqlite3.h"
using namespace std;

class Database{
    private:
        string filename;
    public:
        static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
            int i;
            for(i = 0; i<argc; i++) {
                printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
            }
            printf("\n");
            return 0;
        }
        Database(string filename){
            this->filename = filename;
        };
        Database(){};
        bool Query(string sql){
            sqlite3* db;
            char* zErrMsg = 0;
            int res = sqlite3_open(this->filename.c_str(),&db);
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
};
#pragma once