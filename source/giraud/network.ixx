module;
#include "nlohmann/json.h"
#include "kuku_json.h"
export module network;

import std;
import requests;

export class Network
{
public:
	explicit Network()
	{
	}

	TokenResponse Post(TokenRequest Request)
	{
		std::string requestText = Request.to_json().dump();
		std::string responseText = Post("/oauth/token", requestText);
		nlohmann::json responseJson = nlohmann::json::parse(responseText);
		return from_json<TokenResponse>(responseJson);
	}

	std::string Post(std::string address, std::string bodyText);
};