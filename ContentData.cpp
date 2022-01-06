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

vector<Reading *> ContentData::searchReadingByTitle(string keyword, SearchingFilter filter)
{
    // Return all contents whose title includes keyword, refine the result with filter
    return {    new Book("12", sttAvailable, 12, 15, "The Lord of Rings", "J.K.Rowling", 2012, "Springer", "HHF263", "Fiction"),
                new AcademicJournal("11", sttUnavailable, 0, 12, "Journal 1", "Author Tri", 2020, 1, "2525", "Science"),
                new Book("12", sttAvailable, 12, 15, "The Lord of Rings", "J.K.Rowling", 2012, "Springer", "HHF263", "Fiction"),
                new AcademicJournal("11", sttUnavailable, 0, 12, "Journal 1", "Author Tri", 2020, 1, "2525", "Science"),
                new Book("12", sttAvailable, 12, 15, "The Lord of Rings", "J.K.Rowling", 2012, "Springer", "HHF263", "Fiction"),
                new AcademicJournal("11", sttUnavailable, 0, 12, "Journal 1", "Author Tri", 2020, 1, "2525", "Science"),
                new AcademicJournal("11", sttUnavailable, 0, 12, "Journal 1", "Author Tri", 2020, 1, "2525", "Science")};

}

vector<Reading *> ContentData::searchReadingByAuthors(string keyword, SearchingFilter filter)
{
    // Return all contents whose authors includes keyword, refine the result with filter
    return {    new Book("12", sttAvailable, 12, 15, "The Lord of Rings", "J.K.Rowling", 2012, "Springer", "HHF263", "Fiction"),
                new AcademicJournal("11", sttUnavailable, 0, 12, "Journal 1", "Author Tri", 2020, 1, "2525", "Science"),
                new Book("12", sttAvailable, 12, 15, "The Lord of Rings", "J.K.Rowling", 2012, "Springer", "HHF263", "Fiction"),
                new AcademicJournal("11", sttUnavailable, 0, 12, "Journal 1", "Author Tri", 2020, 1, "2525", "Science"),
                new Book("12", sttAvailable, 12, 15, "The Lord of Rings", "J.K.Rowling", 2012, "Springer", "HHF263", "Fiction"),
                new AcademicJournal("11", sttUnavailable, 0, 12, "Journal 1", "Author Tri", 2020, 1, "2525", "Science"),
                new AcademicJournal("11", sttUnavailable, 0, 12, "Journal 1", "Author Tri", 2020, 1, "2525", "Science")};

}
