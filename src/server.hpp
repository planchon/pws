#include <iostream>
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

// all the common web extension used. 
struct {
  char * ext;
  char * filetype;
} extensions_mime [] = {
  {"gif", "image/gif" },  
  {"jpg", "image/jpg" }, 
  {"jpeg","image/jpeg"},
  {"png", "image/png" },  
  {"ico", "image/ico" },  
  {"zip", "image/zip" },  
  {"gz",  "image/gz"  },  
  {"tar", "image/tar" },  
  {"htm", "text/html" },  
  {"html","text/html" },
  {"css","text/css"   },
  {0,0}
};

class server {
  int port, listenSocket, hit;
  static struct sockaddr_in server_addr;
public:
  server() { port(port)} { };
  int start();
  int stop();
}
