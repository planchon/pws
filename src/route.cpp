#include "route.hpp"

void main_routage(Request req) { 
  if (strncmp(req.method.c_str(), "GET", 3) == 0) {
    get_route(req);
  }
  if (strncmp(req.method.c_str(), "PUT", 3) == 0) {
    put_route(req);
  }
  if (strncmp(req.method.c_str(), "POST", 4) == 0) {
    post_route(req);
  }
  if (strncmp(req.method.c_str(), "PATCH", 5) == 0) {
    patch_route(req);
  }
  if (strncmp(req.method.c_str(), "API", 3) == 0) {
    api_route(req);
  }
  if (strncmp(req.method.c_str(), "DELETE", 6) == 0) {
    delete_route(req);
  }
}

void post_route(Request req) {
}

void delete_route(Request req) {
}

void get_route(Request req) {
}

void put_route(Request req) {
}

void patch_route(Request req) {
}

void api_route(Request req) {
}
