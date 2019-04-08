GCC=g++

all:
	$(GCC) src/server.cpp src/route.cpp src/pws.cpp -o bin/pws
