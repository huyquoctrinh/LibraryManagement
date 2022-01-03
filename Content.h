#include"Database.h"
using namespace std;

class Content{
    private:
        string id;
        string ISSN;
        string _type;
        string category;
        string contentName;
        string Author;
        string publisher;
        string status;
        int AvailableCount;
        int totalCount;
        vector<string> borrowers;
    public:
        Content(string id, string category, string status, int AvailableCount, int totalCount);
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
            res.push_back(contentName);
            res.push_back(Author);
            res.push_back(publisher);
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

class ContentData: public Database{
    private:
        vector<vector<string>> contentDatabase;
    public:
        ContentData(string databasename):Database(databasename){
            this->contentDatabase = getRecord();
        }
        bool addContent(Content data){
            vector<string> content = data.getAllData();
            updateRecord(content);
        }
        bool updateReservation(Content* data){
            for (auto contentRow: contentDatabase){
                if (contentRow[0] == data->getId()){
                    
                }
            }
        }

};

class Reading: public Content{
    private:
        string title;
        string author;
        int publicationYear;
    public:
        Reading(string title, string author, int publicationYear, string id, string category, 
        string status, int AvailableCount, int totalCount):Content(id, category, status, AvailableCount, totalCount){
            this->title = title;
            this->author = author;
            this->publicationYear = publicationYear;
        };
};

class Book:public Reading{
    private:
        string publisher;
        string ISBN;
        string genre;
    // public:
    //     Book(string publisher, string ISBN, string genre):public {

    //     };
};

