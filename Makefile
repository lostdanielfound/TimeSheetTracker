CC=gcc 
EXE=TimeLogger 
FLAGS=-c

all: output cleanup

output: main.o Timefun.o Clock.o 
	$(CC) main.o Timefun.o Clock.o -o $(EXE)

main.o: 
	$(CC) $(FLAGS) main.c

Timefun.o:
	$(CC) $(FLAGS) Timefun.c

Clock.o:
	$(CC) $(FLAGS) Clock.c 

cleanup:
	rm *.o 