GCC=g++

all:
	$(GCC) src/request.cpp src/server.cpp src/route.cpp src/pws.cpp -o bin/pws
