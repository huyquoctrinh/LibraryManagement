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
        if (tmp[0]==i[0]){
            continue;
        }
        else{
            res.push_back(i);
        }
    }
    return 1;
}

bool ContentData::updateContent(Content* data){
    qInfo() << "in UpdateContent()";
    if (data == NULL){
        return 0;
    }
    for (auto contentRow: contentDatabase){
        if (contentRow[0] == data->getId()){
            vector<string> res = data->getAllData();
            for (auto str : res)
                qInfo() << "res: " << QString::fromStdString(str);
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
            int avaiCount = stoi(row[9]);
            int totalCount = stoi(row[8]);
            Book* content = new Book(row[0], ToKey(totalCount - avaiCount > 0),avaiCount,totalCount,row[4],row[5],stoi(row[7]),row[6],isbn,row[3]);
            return content;
        }
    }
    return NULL;
}

AcademicJournal* ContentData::searchByISSN(string issn){
    for (auto row:this->contentDatabase){
        if (row[1] == issn ){
            int avaiCount = stoi(row[9]);
            int totalCount = stoi(row[8]);
            AcademicJournal* content = new AcademicJournal(row[0], ToKey(totalCount - avaiCount > 0), avaiCount, totalCount,row[4],row[5],stoi(row[6]),stoi(row[7]),issn,row[3]);
            return content;
        }
    }
    return NULL;
}

Reading* ContentData::searchReadingByTitle(string keyword, SearchingFilter filter)
{
    for (auto row:this->contentDatabase){
        if (row[4] == keyword){
            if (row[2] == "Book"){
                int stt = stoi(row[10]);
                bool status = !!stt;
                return new Book(row[0],ToKey(status),stoi(row[7]),stoi(row[8]),row[4],row[5],stoi(row[7]),row[6],row[1],row[3]);
            }
            if (row[2] == "Journal"){
                int stt = stoi(row[11]);
                bool status = !!stt;
                return new AcademicJournal(row[0], ToKey(status),stoi(row[9]),stoi(row[8]),row[4],row[5],stoi(row[6]),stoi(row[7]),row[1],row[3]);
            }
        }
    }
    return NULL
}

vector<Reading *> ContentData::searchReadingByAuthors(string keyword, SearchingFilter filter)
{
    // Return all contents whose authors includes keyword, refine the result with filter
    vector<Reading*> res;
    for (auto row:this->contentDatabase){
        if (row[5]== keyword){
            if (row[2] == "Book"){
                int avaiCount = stoi(row[9]);
                int totalCount = stoi(row[8]);
                Book* book = new Book(row[0],ToKey(totalCount - avaiCount > 0),stoi(row[7]),stoi(row[8]),row[4],row[5],stoi(row[7]),row[6],row[1],row[3]);
                res.push_back(book);
            }
            if(row[2] == "Journal"){
                int avaiCount = stoi(row[9]);
                int totalCount = stoi(row[8]);
                AcademicJournal* academic =  new AcademicJournal(row[0], ToKey(totalCount - avaiCount > 0),stoi(row[9]),stoi(row[8]),row[4],row[5],stoi(row[6]),stoi(row[7]),row[1],row[3]);
                res.push_back(academic);
            }
        }
    }
    return res;
}

Content* ContentData::getContentbyID(string id){
    if (id == row[0]){
        if (row[2]=="Book"){
            int avaiCount = stoi(row[9]);
            int totalCount = stoi(row[8]);
            Book* book = new Book(row[0],ToKey(totalCount - avaiCount > 0),stoi(row[7]),stoi(row[8]),row[4],row[5],stoi(row[7]),row[6],row[1],row[3]);
            return Book;
        }
        if (row[2] == "Journal"){
            int avaiCount = stoi(row[9]);
            int totalCount = stoi(row[8]);
            return new AcademicJournal(row[0], ToKey(totalCount - avaiCount > 0),stoi(row[9]),stoi(row[8]),row[4],row[5],stoi(row[6]),stoi(row[7]),row[1],row[3]);
        }
    }
}