#include"Database.h"
using namespace std;

class Content{
    private:
        string id;
        // string ISSN;
        string _type;
        string category;
        string title;
        string Author;
        string publisher;
        string status;
        int AvailableCount;
        int totalCount;
        int publicationYear;
        vector<string> borrowers;
    public:
        Content(string id, string _type, string category, string title, string author, string publisher, string status, 
        int AvailableCount, int totalCount, int publicationYear, vector<string> borrowers){
            this->id = id;
            this->_type = _type;
            this-> category = category;
            this-> title = title;
            this->Author = author;
            this-> Author = author;
            this->publisher = publisher;
            this->status = status;
            this->AvailableCount = AvailableCount;
            this->totalCount = totalCount;
            this->publicationYear = publicationYear;
            this->borrowers = borrowers;
        };
        string getCatergory(){
            return this->category;
        }
        bool isAvailable(){
            return this->AvailableCount==0 ? 0 : 1;
        }
        vector<string> getAllData(){
            vector<string> res;
            res.push_back(id);
            res.push_back(_type);
            res.push_back(category);
            res.push_back(title);
            res.push_back(Author);
            res.push_back(publisher);
            res.push_back(to_string(publicationYear));
            res.push_back(to_string(AvailableCount));   
            res.push_back(to_string(totalCount));
            string borrowers_add ="";
            for (auto borrower:borrowers){
                borrowers_add+= borrower+", ";
            }
            res.push_back(borrowers_add);
            return res;
        }
        string getId(){
            return this->id;
        }
};

class SearchingFilter{
    private:
        string category;
        string genre;
    public:
        SearchingFilter(){};
        string getFilter(){
        if (category =="" && genre==""){
            return "";
        }
        else if ( genre!=""){
            return genre;
        }

        }
};

class ContentData: public Database{
    private:
        vector<vector<string>> contentDatabase;
    public:
        ContentData(string databasename):Database(databasename){
            this->contentDatabase = getRecord();
        }

        bool addContent(Content* data){
            if (data==NULL){
                return 0;
            }
            vector<string> content = data->getAllData();
            int id = contentDatabase.size();
            vector<string> tmp;
            tmp.push_back(to_string(id));
            for (auto i:content){
                tmp.push_back(i);
            }
            updateRecord(content);
            this->contentDatabase = this->getRecord();
            return 1;
        }

        bool updateContent(Content* data){
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

        bool deleteContent(Content* data){
            if (data == NULL){
                return 0;
            }
            vector<string> tmp = data->getAllData();
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
        Content* searchReadingByTitle(string title, SearchingFilter p){
            for (auto row:this->contentDatabase){
                if (row[4] == title ){
                    vector<string> borrowers = Database::Parse(row[10],", ") ;
                    Content* content = new Content(row[0],row[1],row[2],row[3],row[4],row[5],row[6],stoi(row[7]),stoi(row[8]),stoi(row[9]),borrowers);
                    if (p.getFilter()==""){
                        return content;
                    }
                    else{
                        if (row[3] == p.getFilter()){
                            return content;
                        }
                        else{
                            return NULL;
                        }
                    }
                }
            }
        }
        
        Content* searchReadingByAuthor(string author, SearchingFilter p){
            for (auto row:this->contentDatabase){
                if (row[5] == author ){
                    vector<string> borrowers = Database::Parse(row[10],", ") ;
                    Content* content = new Content(row[0],row[1],row[2],row[3],row[4],row[5],row[6],stoi(row[7]),stoi(row[8]),stoi(row[9]),borrowers);
                    if (p.getFilter()==""){
                        return content;
                    }
                    else{
                        if (row[3] == p.getFilter()){
                            return content;
                        }
                        else{
                            return NULL;
                        }
                    }
                }
            }
            
        }
};


// class Reading: public Content{
//     private:
//         string title;
//         string author;
//         int publicationYear;
//     public:
//         Reading(string title, string author, int publicationYear, string id, string category, 
//         string status, int AvailableCount, int totalCount):Content(id, category, status, AvailableCount, totalCount){
//             this->title = title;
//             this->author = author;
//             this->publicationYear = publicationYear;
//         };
// };

class Book:public Content{
    private:
        string _ISBN;
        string _genre;
    public:
        Book(string id, string _type ,string category, string title, string author, string publisher, string status, 
        int AvailableCount, int totalCount, int publicationYear, vector<string> borrowers, string ISBN, string genre):Content(id, _type, category, title, author, publisher, status, AvailableCount,
        totalCount, publicationYear, borrowers){
            this->_ISBN = ISBN;
            this->_genre = genre;
        };
};

class AcademicJournal:public Content{
    private:
        string _volume;
        string _ISSN;
    public:
        AcademicJournal(string id, string _type ,string category, string title, string author, string publisher, string status, 
        int AvailableCount, int totalCount, int publicationYear, vector<string> borrowers, string ISSN, string _volume):Content(id, _type, category, title, author, publisher, status, AvailableCount,
        totalCount, publicationYear, borrowers){
            this->_ISSN = ISSN;
            this->_volume = _volume;
        }
};