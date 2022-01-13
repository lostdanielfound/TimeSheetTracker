CC=gcc 
EXE=TimeLogger 
FLAGS=-g -Wall

all: output

# The symbol: $^ denotes the replacement of the dependency list of the rule. 

Timefun.o: Timefun.c Timefun.h
	$(CC) $(FLAGS) -c $^

Clock.o: Clock.c Clock.h
	$(CC) $(FLAGS) -c $^

output: main.c Timefun.o Clock.o 
	$(CC) $(FLAGS) -o $(EXE) $^ 

clean:
	rm *.o *.gch $(EXE)

submit:
	zip $(EXE) *.c *.h