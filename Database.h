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
        Database(string database){
            this->databaseName = database;
        };
        static vector<string> Parse(string line, string seperator){
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

        vector<vector<string>>getRecord(){
            ifstream in(this->databaseName);
            vector<vector<string>> res;
            string content;
            while(getline(in, content)){
                vector<string> tmp = Parse(content, ", ");
                res.push_back(tmp);
            }
            return res;
        }
        void createRecord(vector<vector<string>> record){
            ofstream out(this->databaseName);
            for (auto row:record){
                for (auto content:row){
                    out<<content<<", ";
                }
                out<<endl;
            }
        }

        void updateRecord(vector<string> data){
            vector<vector<string>> tmp = this->getRecord();
            string idx = data[0];
            int id = stoi(idx);
            tmp[id-1] = data;
            this->createRecord(tmp);
        }

        void addRecord(vector<string> data){
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

        void deleteRecord(vector<string> input_vector){
            vector<vector<string>> data = this->getRecord();
            vector<vector<string>> res;
            for (auto row:data){
                if (compare(row, input_vector)){
                    continue;
                }
                else{
                    res.push_back(row);
                }
            }
            this->createRecord(res);
        }

};

#pragma once