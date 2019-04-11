GCC=g++

all:
	$(GCC) src/request.cpp src/server.cpp src/pws.cpp -std=c++11 -o bin/pws
