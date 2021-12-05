#include "Password.h"
#include<string>
using namespace std;

Password::Password(unsigned long long uid, string username, string Pass){
    this->pass = Pass;
    this->uid = uid;
    this->username = username;
}

string Password::Hashing() {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, this->pass.c_str(), this->pass.size());
    SHA256_Final(hash, &sha256);
    stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}

bool Password::pushToDatabase(){
    string filename = "./database/account.db";
    Database f = Database(filename);
    stringstream ss;
    ss<<this->uid;
    string value = "VALUES ("+ ss.str()+", '"+this->username+"', '"+this->Hashing()+"' ); ";
    string sql = "INSERT or IGNORE INTO ACCOUNT (ID,USERNAME,PASSWORD) "+value;
    f.Query(sql);
    return 1;
}