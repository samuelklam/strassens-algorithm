# Rules
strassen: main.o strassens-algorithm.o matrix-functions.o experimental-testing.o
	g++ main.o strassens-algorithm.o matrix-functions.o experimental-testing.o -o strassen

main.o: main.cpp
	g++ -c main.cpp

strassens-algorithm.o: strassens-algorithm.cpp strassens-algorithm.hpp
	g++ -c strassens-algorithm.cpp

matrix-functions.o: matrix-functions.cpp matrix-functions.hpp
	g++ -c matrix-functions.cpp

experimental-testing.o: experimental-testing.cpp experimental-testing.hpp
	g++ -c experimental-testing.cpp

clean:
	rm *.o strassen
