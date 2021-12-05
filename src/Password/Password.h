#include<string>
#include<iostream>
#include<sstream>
#include <iomanip>
#include "../Database/Database.h"
using namespace std;
#include <openssl/sha.h>

class Password{
    private:
        string pass;
        unsigned long long uid;
        string username;

    public:
        Password(unsigned long long uid, string username, string Pass);
        bool checkPass(string s){
            if (s.size()!= this->pass.size()){
                return 0;
            }
            for (int i =0;i <s.size();i++){
                if (this->pass[i]!=s[i]);
                    return 0;
            }
            return 1;
        };
        string Hashing();
        bool pushToDatabase();

};

#pragma once