#include "ContentData.h"

bool ContentData::addContent(Content* data){
    if (data==NULL){
        return 0;
    }
    vector<string> content = data->getAllData();
    int id = this->contentDatabase.size();
    vector<string> tmp;
    tmp.push_back(to_string(id));
    for (auto i:content){
        tmp.push_back(i);
    }
    updateRecord(content);
    this->contentDatabase = this->getRecord();
    return 1;
}

bool ContentData::deleteContent(Content* content){
    if (content == NULL){
        return 0;
    }
    vector<string> tmp = content->getAllData();
    vector<vector<string>> res;
    for (auto i:this->contentDatabase){
        if (Database::compare(tmp, i)){
            continue;
        }
        else{
            res.push_back(i);
        }
    }
}

bool ContentData::updateContent(Content* data){
    if (data == NULL){
        return 0;
    }
    for (auto contentRow: contentDatabase){
        if (contentRow[0] == data->getId()){
            vector<string> res = data->getAllData();
            updateRecord(res);
            return 1;
        }
    }
    return 0;
}

Book* ContentData::searchByISBN(string isbn){
    for (auto row:this->contentDatabase){
        if (row[1] == isbn ){
            // vector<string> borrowers = Database::Parse(row[10],", ");
            Book* content = new Book(row[0],sttAvailable,stoi(row[7]),stoi(row[8]),row[4],row[5],stoi(row[7]),row[6],isbn,row[3]);
            return content;
        }
    }
    return NULL;
}

AcademicJournal* ContentData::searchByISSN(string issn){
    for (auto row:this->contentDatabase){
        if (row[1] == issn ){
            AcademicJournal* content = new AcademicJournal(row[0], sttAvailable,stoi(row[9]),stoi(row[8]),row[4],row[5],stoi(row[6]),stoi(row[7]),issn,row[3]);
            return content;
        }
    }
    return NULL;
}