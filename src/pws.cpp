#include "server.hpp"

int main() {
  Server server(3000, 8192);
  server.start();
  server.run();
  server.stop();

  return 0;
}
