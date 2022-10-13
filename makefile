all: main.cpp loadbalancer.cpp webserver.cpp
	g++ -std=c++17 -o loadbalancer *.cpp
clean:
	rm -f loadbalancer *.txt