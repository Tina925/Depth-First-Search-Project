CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
TESTS = -DTEST_DIVIDE -DTEST_INTERLEAVE -DTEST_SHUFFLE
GCC = gcc $(CFLAGS) $(TESTS)
EXEC = hw9
OBJS =  hw9.o solver.o mazehelper.o path.o maze.o
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose

$(EXEC): $(OBJS) maze.h solver.h mazehelper.h
	$(GCC) $(OBJS) -o $(EXEC)

all: $(EXEC)

test: $(EXEC)
	./$(EXEC) inputs/maze1 path1
	./$(EXEC) inputs/maze2 path2
	./$(EXEC) inputs/maze3 path3
	./$(EXEC) inputs/maze4 path4
	./$(EXEC) inputs/maze5 path5
memory: $(EXEC)
	$(VALGRIND) --log-file=log1 ./$(EXEC) inputs/maze1 path1
	$(VALGRIND) --log-file=log2 ./$(EXEC) inputs/maze2 path2
	$(VALGRIND) --log-file=log3 ./$(EXEC) inputs/maze3 path3
	$(VALGRIND) --log-file=log4 ./$(EXEC) inputs/maze4 path4
	$(VALGRIND) --log-file=log5 ./$(EXEC) inputs/maze5 path5
%.o : %.c
	$(GCC) -c $<

clean:
	/bin/rm -f *.o
	/bin/rm -f $(EXEC)
	/bin/rm -f path? log?
