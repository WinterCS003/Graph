CC = g++
FLAGS = -g -Wall

main: main.o ArrayGraph.o
	$(CC) $(FLAGS) $^ -o $@

main.o: main.cpp
	$(CC) $(FLAGS) -c $<

ArrayGraph.o: ArrayGraph.cpp
	$(CC) $(FLAGS) -c $<

clean: 
	rm *.o main
