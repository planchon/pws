#include "request.hpp"

Request::Request(int in_request) {
  (void) read(in_request, buffer, BUFSIZE);
  std::cout << buffer << std::endl;
}

void Request::print_me() {
  
}
