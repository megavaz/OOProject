test: 
	g++ -Wall -Wextra -g -O0 -std=c++11 CPPs/flight.cpp CPPs/test.cpp -I./Hs

clean:
	rm -f td5
	rm -rf build
