
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"

void TestNetwork()
{
	httplib::Client cli("https://yhirose.github.io");
	auto res = cli.Get("/hi");
	res->status;
	std::string s = res->body;



}