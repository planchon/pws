#include <iostream>
#include <string>

struct Request {
  std::string route;
  std::string host;
  std::string buffer;
  std::string method;
};

void printRequest(Request req);
Request parseRequest(std::string buffer);
