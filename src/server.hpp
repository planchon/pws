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

#include "route.hpp"

#define MAX_WAITING_CONNEXION 64
#define BUFSIZE 8096

// all the common web extension used. 
struct {
  char * ext;
  char * filetype;
} extensions_mime [] = {
  {"gif" ,"image/gif" },  
  {"jpg" ,"image/jpg" }, 
  {"jpeg","image/jpeg"},
  {"png" ,"image/png" },  
  {"ico" ,"image/ico" },  
  {"zip" ,"image/zip" },  
  {"gz"  ,"image/gz"  },  
  {"tar" ,"image/tar" },  
  {"htm" ,"text/html" },  
  {"html","text/html" },
  {"css" ,"text/css"  },
  {0,0}
};

class Server {
  int listenSocket, pip, clientSocket, hit, port;
  struct sockaddr_in server_addr;
  struct sockaddr_in client_addr;
  socklen_t clientLength = sizeof(client_addr);
public:
  Server(int PORT);
  int start();
  int run();
  int processInput(int client, int hit);
};

Request parseRequest(std::string buffer);
void printRequest(Request req);
