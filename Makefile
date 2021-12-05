CC = g++

all:  main.o Database.o Password.o  
	$(CC)  Database.o Password.o  main.o -l sqlite3 -lcrypto  -o main

main.o: main.cpp ./src/Database/Database.h ./src/Password/Password.h
	$(CC) -g -c main.cpp

Database.o:  ./src/Database/Database.cpp ./src/Database/Database.h
	$(CC) -g -c ./src/Database/Database.cpp

Password.o:  ./src/Password/Password.cpp ./src/Password/Password.h
	$(CC) -g -c ./src/Password/Password.cpp

clean:
	rm -f *.o
	rm main