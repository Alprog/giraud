#include "utils.h"

#include <fstream>

std::string readFileText(std::string path)
{
	std::ifstream stream(path);
	std::ostringstream ss;
	ss << stream.rdbuf();
	return ss.str();
}