module;
#include "nlohmann/json.h"
#include "kuku_json.h"
export module network;

import std;
import configuration;
import requests;
import session;

export class Network
{
public:
	explicit Network(const Configuration& config)
		: config{ config }
	{
	}

	const Configuration& GetConfig() const { return config; }
	Session& GetSession() { return session; }

	void Login(std::string code)
	{
		TokenRequest request;
		request.grant_type = "authorization_code";
		request.client_id = config.app.id;
		request.client_secret = config.app.secret;
		request.code = code;
		request.redirect_uri = config.app.redirect_uri;

		TokenResponse response = Post(request);
		session.accessToken = response.access_token;
	}

	void Logout()
	{
		session.accessToken = {};
	}

	TokenResponse Post(TokenRequest Request)
	{
		std::string requestText = Request.to_json().dump();
		std::string responseText = Post("/oauth/token", requestText);
		nlohmann::json responseJson = nlohmann::json::parse(responseText);
		return from_json<TokenResponse>(responseJson);
	}

	std::string Post(std::string address, std::string bodyText);

private:
	const Configuration& config;
	Session session;
};