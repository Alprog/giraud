module;
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"
module network;

std::string Network::Post(std::string address, std::string postBody)
{
	httplib::Client cli("https://auth.atlassian.com");
	std::string contentType = "application/json";
	auto response = cli.Post(address, postBody, contentType);
	return response->body;
}
