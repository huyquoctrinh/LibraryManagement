#include "Database.h"
#include <QDebug>

Database::Database(string database){
    database = Utils::getDir(database);
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
    in.close();
    return res;
}

void Database::createRecord(vector<vector<string>> record){
    ofstream out(this->databaseName);
    for (auto row:record){
        for (int i = 0; i < row.size(); i++) {
            out << row[i];
            if (i < row.size() - 1)
                out << ", ";
        }
        /*for (auto content:row){
            out << content << ", ";
        }*/
        out<<endl;
    }
    out.close();
}
void Database::updateRecord(vector<string> data){
    vector<vector<string>> tmp = this->getRecord();
    string idx = data[0];
    for (int i = 0; i < tmp.size(); i++) {
        if (tmp[i][0] == idx)
            tmp[i] = data;
    }
    this->createRecord(tmp);
}

void Database::addRecord(vector<string> data){
    vector<vector<string>> tmp = this->getRecord();
    tmp.push_back(data);
    ofstream out(this->databaseName);
    for (auto row:tmp){
        for (int i = 0; i < row.size(); i++) {
            out << row[i];
            if (i < row.size() - 1)
                out << ", ";
        }
        /*for (auto content:row){
            out << content << ", ";
        }*/
        out<<endl;
    }
    out.close();
}

void Database::deleteRecord(vector<string> input_vector){
    vector<vector<string>> data = this->getRecord();
    vector<vector<string>> res;
    for (auto row:data){
        if (this->compare(row, input_vector)){
            continue;
        }
        else{
            res.push_back(row);
        }
    }
    this->createRecord(res);

}
