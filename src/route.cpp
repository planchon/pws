#include "route.hpp"

constexpr unsigned int str2int(const char* str, int h = 0) {
    return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}

void routeRequest(Request req) {
  switch (str2int(req.req_method.c_str())) {
  case str2int("GET"):
    route_GET_method(req);
    break;
  case str2int("PUT"):
    break;
  case str2int("DELETE"):
    break;
  case str2int("PATCH"):
    break;
  default:
    break;
  }
}

void route_GET_method(Request req) {
  switch (str2int(req.req_subdomain.c_str())) {
  case str2int("blog"):
    break;
  case str2int("cv"):
    break;
  case str2int("video"):
    break;
  default:
    static_generator(req, "template/main/");
    break;
  }
}
