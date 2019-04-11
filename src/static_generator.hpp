#include <fstream>
#include <streambuf>
#include <fcntl.h>
#include <cstring>

#include "request.hpp"
#include "extension_mime.hpp"

void static_generator(Request req, std::string base);
