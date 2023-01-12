CC=gcc 
EXE=TimeLogger 
FLAGS=-g -Wall

all: output

# The symbol: $^ denotes the replacement of the dependency list of the rule. 

cursorSelection.o: cursorSelection.c cursorSelection.h
	$(CC) $(FLAGS) -c $^

Timefun.o: Timefun.c Timefun.h
	$(CC) $(FLAGS) -c $^

Clock.o: Clock.c Clock.h
	$(CC) $(FLAGS) -c $^

output: main.c Timefun.o Clock.o cursorSelection.o
	$(CC) $(FLAGS) -lncurses -o $(EXE) $^ 

clean:
	rm *.o *.gch 

submit:
	zip $(EXE) *.c *.h