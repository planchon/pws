#include <fstream>
#include <streambuf>
#include <fcntl.h>
#include <cstring>

#include "request.hpp"
#include "extension_mime.hpp"

std::string generate_mime_extension(std::string file);
void static_one_file_generator(Request req, std::string base);
void static_generator(Request req, std::string base);
