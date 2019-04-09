#include "request.hpp"

void printRequest(Request req) {
  std::cout << "Method : " << req.method << std::endl;
  std::cout << "Route : " << req.route << std::endl;
  std::cout << "Host : " << req.host << std::endl;
  std::cout << "Buffer : " << req.buffer << std::endl;
}

Request parseRequest(std::string buffer) {
  Request new_request;
  new_request.method  = buffer.substr(0, buffer.find(' '));
  new_request.route   = buffer.substr(buffer.find(' ') + 1, buffer.find("HTTP") - 4);

  // pour trouver la position du \n 
  int back_pos;
  int i = buffer.find('Host:') + 1;
  bool found = false;
  while ((not found) && i < buffer.size()) {
    if (buffer[i] == '\n') {
      found = true;
      back_pos = i;
    } else {
      i++;
    }
  }
  
  new_request.host    = buffer.substr(buffer.find('Host:') + 2, back_pos);
  new_request.buffer  = buffer;

  return new_request;
}
