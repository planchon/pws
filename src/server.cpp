#include "server.hpp"

Server::Server(int PORT, int max_wait) {
  Server::port = PORT;
  Server::max_waiting_connexion = max_wait;
}

void Server::log(std::string message) {
  std::cout << "pws -> ERROR : " << message << std::endl;
}

void Server::start() {
  std::cout << "Server start on port " << port << std::endl;
  
  if ((Server::serverSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    log("socket creation failed");
    exit(-1);
  }

  server_addr.sin_family      = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port        = htons(port);

  if (bind(serverSocket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
    log("binding process failed");
    exit(-1);
  }

  if (listen(serverSocket, max_waiting_connexion) < 0) {
    log("listen failed");
    exit(-1);
  }
}

void Server::run() {
  pip = 0;
  int hit;
  for (hit = 1; ; hit++) {
    if ((clientSocket = accept(serverSocket, (struct sockaddr *) &client_addr, &clientLength)) < 0) {
      log("accept failed");
      exit(-1);
    }
    if ((pip = fork()) < 0) {
      log("fork process failed");
      exit(-1);
    } else {
      if (pip == 0) {
	close(serverSocket); // on close le socket qui est dans le pip.
	Request req(clientSocket);
	routeRequest(req);
      } else {
	close(clientSocket);
      }
    }
  }
}

void Server::stop() {
  if (pip > 0) {
    close(serverSocket);
    std::cout << "Server closed. Bye" << std::endl;
    exit(0);
  }
}
