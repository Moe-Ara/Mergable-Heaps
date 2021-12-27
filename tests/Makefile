output: testunit.o BinomialHeap.o Node.o FibonacciHeap.o
	g++ -std=c++17 testunit.o BinomialHeap.o Node.o FibonacciHeap.o -o output

testunit.o: ../src/* ../include/*.hpp
	g++ -c -std=c++17 ./Test1.cpp

BinomialHeap.o: ../src/BinomialHeap.cpp ../include/BinomialHeap.hpp
	g++ -c -std=c++17 ../src/BinomialHeap.cpp

Node.o: ../src/Node.cpp ../include/Node.hpp
	g++ -c -std=c++17 ../src/Node.cpp

FibonacciHeap.o: ../src/FibonacciHeap.cpp ../include/FibonacciHeap.hpp
	g++ -c -std=c++17 ../src/FibonacciHeap.cpp

clean:
	del *.o
	del test.exe

target: dependencies
	action