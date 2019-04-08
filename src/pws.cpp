#include "server.hpp"

int main() {
  Server server(9191);
  server.start();
  server.run();

  return 0;
}
