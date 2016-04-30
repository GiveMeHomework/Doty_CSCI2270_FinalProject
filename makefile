all: Project clean

Project: finalproj.o Graph.o
	g++ -std=c++11 finalproj.o Graph.o -o Project_EXE

finalproj.o: finalproj.cpp
	g++ -c -std=c++11 finalproj.cpp
	
Graph.o: Graph.cpp
	g++ -c -std=c++11 Graph.cpp
	
clean:
	rm -f finalproj.o
	rm -f Graph.o
	

	
