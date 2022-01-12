#include "ContentData.h"
#include <QCoreApplication>
#include <QDebug>
#include <string>

bool find(vector<string> a, string key){
    for (int i = 0;i < a.size();i++){
        if (a[i]== key){
            return 1;
        }
    }
    return 0;
}

bool ContentData::addContent(Content* data){
    if (data==NULL){
        return 0;
    }
    vector<string> content = data->getAllData();
    this->contentDatabase = getRecord();
    int id = stoi(this->contentDatabase[this->contentDatabase.size() - 1][0]) + 1;
    content[0] = to_string(id);
    contentDatabase.push_back(content);
    createRecord(contentDatabase);
    this->contentDatabase = this->getRecord();
    return 1;
}

bool ContentData::deleteContent(Content* content){
    if (content == NULL){
        return 0;
    }
    this->contentDatabase = getRecord();
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
    Database* temp = new Database("Book.csv");
    temp->createRecord(res);
    return 1;
}

bool ContentData::updateContent(Content* data){
    qInfo() << "in UpdateContent()";
    if (data == NULL){
        return 0;
    }
    this->contentDatabase = getRecord();
    Database* tmp = new Database("Book.csv");
    for (auto contentRow: contentDatabase){
        qInfo() << QString::fromStdString(contentRow[0]);
        if (contentRow[0] == data->getId()){
            vector<string> res = data->getAllData();
            qInfo() << QString::number(res.size());
            for (string str : res)
                qInfo() << "res: " << QString::fromStdString(str);
            tmp->updateRecord(res);
            this->contentDatabase = this->getRecord();
            return 1;
        }
    }
    return 0;
}

Book* ContentData::searchByISBN(string isbn){
    this->contentDatabase = getRecord();
    for (auto row:this->contentDatabase){
        if (row[1] == isbn ){
            // vector<string> borrowers = Database::Parse(row[10],", ");
            int avaiCount = stoi(row[8]);
            int totalCount = stoi(row[9]);
            Book* content = new Book(row[0], ToKey(avaiCount > 0),avaiCount,totalCount,row[4],row[5],stoi(row[7]),row[6],isbn,row[3]);
            return content;
        }
    }
    return NULL;
}

vector<Reading *> ContentData::searchAllReading(SearchingFilter filter)
{
    this->contentDatabase = getRecord();
    vector<string> genreFilter = filter.getGenre();
    vector<string> catFilter = filter.getCat();
    vector<Reading*> res;
    for (auto row:this->contentDatabase){
        if (find(catFilter,row[2]) && row[2] == "Book"){
            int avaiCount = stoi(row[8]);
            int totalCount = stoi(row[9]);
            Book* book = new Book(row[0],ToKey(avaiCount > 0),avaiCount,totalCount,row[4],row[5],stoi(row[7]),row[6],row[1],row[3]);
            if (find(genreFilter,row[3])){
                res.push_back(book);
            }
        }
        if(find(catFilter,row[2]) && row[2] == "Journal"){
            int avaiCount = stoi(row[8]);
            int totalCount = stoi(row[9]);
            AcademicJournal* academic =  new AcademicJournal(row[0], ToKey(avaiCount > 0),avaiCount,totalCount,row[4],row[5],stoi(row[6]),stoi(row[7]),row[1],row[3]);
            res.push_back(academic);
        }
    }

    return res;
}

AcademicJournal* ContentData::searchByISSN(string issn){
    this->contentDatabase = getRecord();
    for (auto row:this->contentDatabase){
        if (row[1] == issn ){
            int avaiCount = stoi(row[8]);
            int totalCount = stoi(row[9]);
            AcademicJournal* content = new AcademicJournal(row[0], ToKey(avaiCount > 0), avaiCount, totalCount,row[4],row[5],stoi(row[6]),stoi(row[7]),issn,row[3]);
            return content;
        }
    }
    return NULL;
}

vector<Reading*> ContentData::searchReadingByTitle(string keyword, SearchingFilter filter)
{
    this->contentDatabase = getRecord();
    vector<string> genreFilter = filter.getGenre();
    vector<string> catFilter = filter.getCat();
    vector<Reading*> res;
    for (auto row:this->contentDatabase){
        if (row[4].find(keyword) != string::npos){
            if (find(catFilter,row[2]) && row[2] == "Book"){
                int avaiCount = stoi(row[8]);
                int totalCount = stoi(row[9]);
                Book* book = new Book(row[0],ToKey(avaiCount > 0),avaiCount,totalCount,row[4],row[5],stoi(row[7]),row[6],row[1],row[3]);
                if (find(genreFilter,row[3])){
                    res.push_back(book);
                }
            }
            if(find(catFilter,row[2]) && row[2] == "Journal"){
                int avaiCount = stoi(row[8]);
                int totalCount = stoi(row[9]);
                AcademicJournal* academic =  new AcademicJournal(row[0], ToKey(avaiCount > 0),avaiCount,totalCount,row[4],row[5],stoi(row[6]),stoi(row[7]),row[1],row[3]);
                res.push_back(academic);
            }
        }
    }
    return res;
}

vector<Reading *> ContentData::searchReadingByAuthors(string keyword, SearchingFilter filter)
{
    // Return all contents whose authors includes keyword, refine the result with filter


    // filter include two attributes: they are all vectors.
    // Get all possible results that have category in categories vector, and have genre (if book) in genres vector.
    this->contentDatabase = getRecord();
    vector<string> genreFilter = filter.getGenre();
    vector<string> catFilter = filter.getCat();
    vector<Reading*> res;
    for (auto row:this->contentDatabase){
        if (row[5].find(keyword) != string::npos){
            if (find(catFilter,row[2]) && row[2] == "Book"){
                int avaiCount = stoi(row[8]);
                int totalCount = stoi(row[9]);
                Book* book = new Book(row[0],ToKey(avaiCount > 0),avaiCount,totalCount,row[4],row[5],stoi(row[7]),row[6],row[1],row[3]);
                if (find(genreFilter,row[3])){
                    res.push_back(book);
                }
            }
            if(find(catFilter,row[2]) && row[2] == "Journal"){
                int avaiCount = stoi(row[8]);
                int totalCount = stoi(row[9]);
                AcademicJournal* academic =  new AcademicJournal(row[0], ToKey(avaiCount > 0),avaiCount,totalCount,row[4],row[5],stoi(row[6]),stoi(row[7]),row[1],row[3]);
                res.push_back(academic);
            }
        }
    }
    return res;
}

Content* ContentData::getContentbyID(string id){
    this->contentDatabase = getRecord();
    for (auto row:this->contentDatabase) {
        qInfo() << QString::fromStdString(id) << " : " << QString::fromStdString(row[0]);
        if (id == row[0]){
            if (row[2] == "Book"){
                int avaiCount = stoi(row[8]);
                int totalCount = stoi(row[9]);
                Book* book = new Book(row[0],ToKey(avaiCount > 0),avaiCount,totalCount,row[4],row[5],stoi(row[7]),row[6],row[1],row[3]);
                qInfo() << QString::fromStdString(book->getTitle());
                return book;
            }
            if (row[2] == "Journal"){
                int avaiCount = stoi(row[8]);
                int totalCount = stoi(row[9]);
                return new AcademicJournal(row[0], ToKey(avaiCount > 0),avaiCount,totalCount,row[4],row[5],stoi(row[6]),stoi(row[7]),row[1],row[3]);
            }
        }
    }
    return NULL;
}
