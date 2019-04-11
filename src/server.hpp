#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "request.hpp"
#include "route.hpp"

class Server {
  int port, serverSocket, clientSocket, max_waiting_connexion, pip;
  struct sockaddr_in server_addr;
  struct sockaddr_in client_addr;
  socklen_t clientLength = sizeof(client_addr);
public:  
  Server(int PORT, int max_wait);
  void start();
  void run();
  void stop();
  void log(std::string message);
};
