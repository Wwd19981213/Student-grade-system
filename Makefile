CC=gcc
STD=-std=gnu99
BIN=system.bin
FLAG=-Wall -Werror -DDEBUG
OBJ=main.o tch.o tools.o stu.o tools2.o master.o tools3.o

all:$(OBJ)
	$(CC) -o $(BIN) $(OBJ)
	
main.o:main.c tch.h stu.h master.h
	$(CC) $(STD) $(FLAG) -c main.c
tch.o:tch.c tch.h tools.h main.h
	$(CC) $(STD) $(FLAG) -c tch.c
tools.o:tools.c tools.h main.h
	$(CC) $(STD) $(FLAG) -c tools.c
stu.o:stu.c stu.h main.h tools2.h
	$(CC) $(STD) $(FLAG) -c stu.c
tools2.o:tools2.c tools2.h main.h
	$(CC) $(STD) $(FLAG) -c tools2.c
master.o:master.c master.h main.h tools3.h
	$(CC) $(STD) $(FLAG) -c master.c
tools3.o:tools3.c tools3.h main.h
	$(CC) $(STD) $(FLAG) -c tools3.c
clean:
	rm -rf $(BIN) $(OBJ)
