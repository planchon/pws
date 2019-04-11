#include <unistd.h>
#include <iostream>

#define BUFSIZE 8192

class Request {
  char buffer[BUFSIZE];
public:
  Request(int socket);
  void print_me();
};
