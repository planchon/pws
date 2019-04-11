GCC=g++

all:
	$(GCC) src/request.cpp src/route.cpp src/static_generator.cpp src/server.cpp src/pws.cpp -std=c++11 -w -o bin/pws
