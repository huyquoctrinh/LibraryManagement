# Library Management System

## Database Format
### Book.csv

[Id], [ISBN/ISSN], [Category], [Genre/Subject], [Title], [Author], [Publisher], [Publication Year], [Volume (for Journal only)], [Available count], [Total count]

### Account.csv

[Id], [Username], [Password], [Name], [Date of Birth], [Gender], [User Type], [University], [SID], [Renewal Date], [Membership]

### Reservation.csv

[Id], [Start Date], [Expired Date], [Content Id], [Borrower Id], [Is returned]

## To-dos
 - [x] **DBAccess()** constructor in *DBAccess.cpp* 
 - [x] **signIn()** method in *LibMS.cpp*
 - [x] **signUp()** method in *LibMS.cpp*
 - [x] Copy/Paste **Database.h, Database.cpp**
 - [ ] Fix **addStudent()** method in *UserData.cpp*. Add *setId()*.
 - [ ] Fix **readAllReservation()**, **readUserReservation()** method in *ReservationData.cpp*
 - [ ] Fix **createReservation()** method in *ReservationData.cpp*, should update database.
 - [ ] Fix **updateContent()**, **addContent()** methods in *ContentData.cpp*
 - [ ] Fix **deleteContent()** method in *ContentData.cpp*, just need to compare ID only!
 - [x] Copy/Paste **addStudent()** method in *UserData.cpp*
 - [x] Copy/Paste **updateStudent()** method in *UserData.cpp*
 - [x] Copy/Paste **deleteStudent()** method in *UserData.cpp*
 - [x] Copy/Paste **searchReadingByTitle()**, **searchReadingByAuthors()** in *ContentData.cpp*

### Notes:
1. Content, Reading are abstract classes. If a method returns a Content/Reading pointer, that pointer should point to an instance of Book or Academic Journal.
2. **Use filter to refine the results!**

## Design

In general, we would like to design our system as real life activity. Followings are important classes/abstract classes and their role.

### LibMS
**Description**: This class contains all needed information for the entire program to work, including *current user*, *viewing reading*, *database*. Thus, it is designed with Singleton pattern. There is only one instance of this class and it is constructed when the main program starts launching.

### User
**Description**: This is an abstract class which contains information of a real life user. Each user would have an account which is store in a different class, **Account**. **Student** and **Staff** are two derived classes of this class.

### Content
**Description**: This is an abstract class which contains information of a real life content which can be a book, a record, a media player. In this project, we just work with reading items which are books and academic journals.

### Reservation
**Description**: This is an abstract class which contains information of a reservation, including *content* that is borrowed, *borrower*, *start date* and *expired date*. 

### Database
**Description**: This is a regular class that defines all CRUD operation on back-end database. This class's methods often require queries (String) which will be passed from derived classes (**UserData**, **ContentData**, **ReservationData**). Its child classes will do their particular tasks: 
* **UserData**: Add, modify, delete users' account. This class will associate with derived **UserParser** classes to complete the task.
* **ReservationData**: Add, modify, delete reservations. It also uses **ReservationFilter** instance to refine the results of searching.
* **ContentData**: Add, modify, delete content. This class will associate with derived **ContentParser** classes to complete the task. It also uses **SearchingFilter** instance to refine the results of searching.

### ContentParser & UserParser
**Description**: These two class are abstract class. Its derived classes should implement to return specific queries to operate with database. For example, there are two derived classes (*Book* and *Academic Journal*) and their attribute are different from each other, so we need to add them into database with distinguished queries. When we call a method of **ContentData** class to add a book to the database, we should pass a *BookParser* instance to it. Then, *BookParser* should return a specific query.
