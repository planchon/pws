#include "request.hpp"

Request::Request(int in_request) {
  req_socket = in_request;
  (void) read(in_request, req_char_buffer, BUFSIZE);
  req_buffer = std::string(req_char_buffer);
  parseRequest();
  verifyIntegrety(); // do nothing for the moment
  sanitize();
}

std::vector<std::string> Request::splitOnSpace() {
  std::vector<std::string> words;
  std::string current_word;
  for (int i = 0; i < req_buffer.size(); i++) {
    if ((req_char_buffer[i] == ' ') || (req_char_buffer[i] == '\n')) {
      words.push_back(current_word);
      current_word = "";
    } else {
      current_word += req_char_buffer[i];
    }
  }

  return words;
}

std::string Request::findSubDomain() {
  if ((req_host.at(0) != 'l') || (req_host.at(0) != 'p')) {
    return req_host.substr(0, req_host.find('.'));
  } else {
    return "";
  }
}

void Request::parseRequest() {
  std::vector<std::string> words = splitOnSpace();

  req_method = words.at(0);
  req_route  = words.at(1);
  req_host   = words.at(4);
  
  req_subdomain = findSubDomain();
}

bool Request::verifyIntegrety() {
  // TODO
  // verify method
  std::vector<std::string> supported_methods = {"GET", "POST", "PUT", "DELETE", "PATCH"};
  bool isVerify = false;
  
  for (int i = 0; i < supported_methods.size(); i++) {
    if (req_method == supported_methods.at(i)) isVerify = true;
  }

  return isVerify;
}

void Request::sanitize() {
}

void Request::print_me() {
  std::cout << "METHOD : " << req_method      << std::endl;
  std::cout << "ROUTE  : " << req_route       << std::endl;
  std::cout << "HOST   : " << req_host        << std::endl;
  std::cout << "SUBD.  : " << req_subdomain   << std::endl;
}

void Request::respond() {
  (void) write(req_socket, req_respond.c_str(), req_respond.size());
  sleep(1);
  close(req_socket);
  exit(1);
}

void Request::createRespond(int code, std::string file_to_send, std::string content_type) {
  req_respond += "HTTP/1.1 ";

  switch (code) {
  case 200:
    req_respond += "200 OK\n";
    break;
  case 404:
    req_respond += "404 Not found\n";
    break;
  default:
    break;
  }
  
  req_respond += "Server: Pauls Web Server (pws)\n";
  req_respond += "Content-Length: " + std::to_string(file_to_send.size()) + "\n";
  req_respond += "Content-Type: " + content_type + "\n";
  req_respond += "\n";
  req_respond += file_to_send;
}
