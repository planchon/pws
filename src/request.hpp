#pragma once

#include <unistd.h>
#include <iostream>
#include <vector>

#define BUFSIZE 8192

class Request {
public:
  int  req_socket;
  char req_char_buffer[BUFSIZE];
  std::string req_buffer;
  
  std::string req_method;
  std::string req_route;
  std::string req_host;
  std::string req_subdomain;

  std::string req_respond;
  Request(int socket);
  void print_me();
  void parseRequest();
  void createRespond(int code, std::string file, std::string content);
  void respond();
  
private:
  std::vector<std::string> splitOnSpace();
  bool verifyIntegrety();
  void sanitize();
  std::string findSubDomain();
};
