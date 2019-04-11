#include "server.hpp"

int main(int argc, char* argv[]) {
  Server server(atoi(argv[1]), 8192);
  server.start();
  server.run();
  server.stop();

  return 0;
}
