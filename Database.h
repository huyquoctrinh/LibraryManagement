#ifndef DATABASE_H
#define DATABASE_H

#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class Database{
    private:
        string databaseName;
    public:
        Database() {};
        Database(string database);
        static vector<string> Parse(string line, string seperator);

        vector<vector<string>>getRecord();
        void createRecord(vector<vector<string>> record);
        void updateRecord(vector<string> data);
        void deleteRecord();

};

#endif // DATABASE_H
