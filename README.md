## Installation

'''bash
sudo apt install sqlite3 libsqlite3-dev
'''

After installing the compulsory packages, run the code below
## Usage

'''c++
string filename = "./database/databaseName.db";
Database f = Database(filename);
string sql = "INSERT or IGNORE INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
            "VALUES (1, 'Huy', 18, 'HCM', 500000 ); ";
f.Query(sql);
