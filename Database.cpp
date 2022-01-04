#include "Database.h"

Database::Database(string database){
    this->databaseName = database;
}

vector<string> Database::Parse(string line, string seperator){
    vector<string> tokens;
    int startPos = 0;
    size_t foundPos = line.find(seperator, startPos);
    while (foundPos != string::npos){
        int count =  foundPos - startPos;
        string token = line.substr(startPos, count);
        tokens.push_back(token);
        startPos = foundPos + seperator.length();
        foundPos = line.find(seperator, startPos);
    }
    int count  =  line.length() - startPos;
    string token = line.substr(startPos, count);
    tokens.push_back(token);
    return tokens;
}

vector<vector<string>> Database::getRecord(){
    ifstream in(this->databaseName);
    vector<vector<string>> res;
    string content;
    while(getline(in, content)){
        vector<string> tmp = Parse(content, ", ");
        res.push_back(tmp);
    }
    return res;
}
void Database::createRecord(vector<vector<string>> record){
    ofstream out(this->databaseName);
    for (auto row:record){
        for (auto content:row){
            out<<content<<", ";
        }
        out<<endl;
    }
}
void Database::updateRecord(vector<string> data){
    vector<vector<string>> tmp = this->getRecord();
    tmp.push_back(data);
    ofstream out(this->databaseName);
    for (auto row:tmp){
        for (auto content:row){
            out<<content<<", ";
        }
        out<<endl;
    }
}
void Database::deleteRecord(){
    vector<vector<string>> data = this->getRecord();
}
