//        _                  _                   _       
//       | |                | |                 (_)      
//  _ __ | | __ _ _ __   ___| |__   ___  _ __    _  ___  
// | '_ \| |/ _` | '_ \ / __| '_ \ / _ \| '_ \  | |/ _ \ 
// | |_) | | (_| | | | | (__| | | | (_) | | | |_| | (_) |
// | .__/|_|\__,_|_| |_|\___|_| |_|\___/|_| |_(_)_|\___/ 
// | |                                                   
// |_|                                                   

//             pauls Web Server - pws v1

//   a very compact web server created by Paul Planchon
// in order to host planchon.io on the smallest webserver
//       possible. All code under MIT licence.

#include "server.hpp"
#include "route.hpp"

Server::Server(int PORT) {
  port = PORT;
}

int Server::start() {
  std::cout << "\n\t pauls Web Server v1\n\n";
  std::cout << "server running on port : " << port << std::endl;

  if ((listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
    std::cout << "pws -> ERROR (socket creation) (" << errno << ") : " << strerror(errno) << std::endl;
    return -1;
  }

  server_addr.sin_family	= AF_INET;
  server_addr.sin_addr.s_addr	= htonl(INADDR_ANY);
  server_addr.sin_port		= htons(port);

  if ((bind(listenSocket, (struct sockaddr*) &server_addr, sizeof(server_addr))) < 0) {
    std::cout << "pws -> ERROR (bind socket) (" << errno << ") : " << strerror(errno) << std::endl;
    return -1;
  }

  if (listen(listenSocket, MAX_WAITING_CONNEXION) < 0) {
    std::cout << "pws -> ERROR (listening) (" << errno << ") : " << strerror(errno) << std::endl;
    return -1;
  }

  std::cout << "\n\t...server initialized..." << std::endl;
}

int Server::run() {
  // boucle principale qui gere toutes les request
  for (hit = 1; ; hit++) {
    if ((clientSocket = accept(listenSocket, (struct sockaddr *) &client_addr, &clientLength)) < 0) {
      std::cout << "pws -> ERROR (accept) (" << errno << ") : " << strerror(errno) << std::endl;
      exit(3);
    }

    if ((pip = fork()) < 0) {
      std::cout << "pws -> ERROR (pip) ("<< errno << strerror(errno) << ")" << std::endl;
      exit(3);
    } else {
      if (pip == 0) { // dans l'enfant
	(void) close(listenSocket);
	processInput(clientSocket, hit);
      } else {
	(void) close(clientSocket);
      }
    }
  }
}

int Server::processInput(int client, int hit) {
  static char requestBuffer[BUFSIZE + 1];
  int request = read(client, requestBuffer, BUFSIZE);
  std::string buffer(requestBuffer);

  routage(buffer.substr(0, buffer.find(' ')), buffer.substr(buffer.find(' ') + 1, buffer.find("HTTP") - 4));
}
