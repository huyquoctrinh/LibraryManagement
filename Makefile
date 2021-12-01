CC = g++

all:  main.o Database.o   
	$(CC)  Database.o  main.o -l sqlite3 -o main

main.o: main.cpp ./src/Database/Database.h
	$(CC) -g -c main.cpp

Database.o:  ./src/Database/Database.cpp ./src/Database/Database.h
	$(CC) -g -c ./src/Database/Database.cpp
clean:
	rm -f *.o
	rm main