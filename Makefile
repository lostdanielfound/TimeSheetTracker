CC=gcc 
EXE=TimeLogger 
FLAGS=-g -Wall

all: output

# The symbol: $^ denotes the replacement of the dependency list of the rule. 

cursorSelection.o: cursorSelection.c cursorSelection.h
	$(CC) $(FLAGS) -c $^

Time_Functions.o: Time_Functions.c Time_Functions.h
	$(CC) $(FLAGS) -c $^

Clock.o: Clock.c Clock.h
	$(CC) $(FLAGS) -c $^

output: main.c Time_Functions.o Clock.o cursorSelection.o
	$(CC) $(FLAGS) -lncurses -o $(EXE) $^ 

clean:
	rm *.o *.gch 

submit:
	zip $(EXE) *.c *.h