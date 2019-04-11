#include "static_generator.hpp"

void static_generator(Request req, std::string base) {
  std::string file_request = req.req_route;
  if (file_request == "/") { file_request = "index.html"; }

  if ((open((base + file_request).c_str(), O_RDONLY)) == -1) {
    req.createRespond(404, "404 Not found", "text/html");
  } else {
    std::ifstream file((base + file_request).c_str());
    std::string file_string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    std::string file_extension;
    std::string file_mime = "none";
    
    int i = file_request.size() - 1;
    while ((i > 0) && (file_request.at(i) != '.')) {
      file_mime.insert(0, 1, file_request.at(i));
      i--;
    }
    
    for (int i = 0; extensions_mime[i].ext != 0; i++) {
      long lenExt = strlen(extensions_mime[i].ext);
      if( !strncmp(file_mime.c_str(), extensions_mime[i].ext, lenExt)) {
	file_mime = std::string(extensions_mime[i].filetype);
	break;
      }
    }

    if ((std::string("none").compare(file_mime)) == 0) {
      req.createRespond(404, "404 Not found", "text/html");
    } else {
      req.createRespond(200, file_string, file_mime);
    }
  }
  req.respond();
}
