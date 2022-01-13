CC=gcc 
EXE=TimeLogger 
FLAGS=-c

all: output clean

output: main.o Timefun.o Clock.o 
	$(CC) main.o Timefun.o Clock.o -o $(EXE)

main.o: main.c
	$(CC) $(FLAGS) main.c

Timefun.o: Timefun.c
	$(CC) $(FLAGS) Timefun.c

Clock.o: Clock.c
	$(CC) $(FLAGS) Clock.c 

clean:
	rm *.o 