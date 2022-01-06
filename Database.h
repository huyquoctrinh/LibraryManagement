#ifndef DATABASE_H
#define DATABASE_H

#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Utils.h"
using namespace std;

class Database{
    private:
        string databaseName;
    public:
        Database() {};
        Database(string database);
        static vector<string> Parse(string line, string seperator);
        static bool compare(vector<string> a1, vector<string> a2){
            if (a1.size() != a2.size()){
                return 0;
            }
            for (int i=0;i<a1.size();i++){
                if (a1[i] != a2[i]){
                    return 0;
                }
            }
            return 1;
        }

        vector<vector<string>>getRecord();
        void createRecord(vector<vector<string>> record);
        void updateRecord(vector<string> data);
        void addRecord(vector<string> data);
        void deleteRecord(vector<string> input_vector);
};

#endif // DATABASE_H
