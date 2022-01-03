#include"Database.h"
using namespace std;

class Content{
    private:
        string id;
        string category;
        string status;
        int AvailableCount;
        int totalCount;
    public:
        Content(string id, string category, string status, int AvailableCount, int totalCount);
        string getCatergory(){
            return this->category;
        }
        bool isAvailable(){
            return this->AvailableCount==0 ? 0 : 1;
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

