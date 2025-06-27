module;
#include "nlohmann/json.h"
#include "kuku_json.h"
export module configuration;

import jira_app;
import user;
import std;

export class Configuration : public json::serializable
{
public:
	Configuration()
	{
	}

	void load()
	{
		json::loadFromFile(*this, "config.txt");

		std::ifstream stream("config.txt");
		std::ostringstream ss;
		ss << stream.rdbuf();
		std::string text = ss.str();
		nlohmann::json json = nlohmann::json::parse(text);
		*this = from_json<Configuration>(json);
	}

	//Configuration& operator=(const Configuration& config) = default;

	JiraApp app;
	std::string domain;
	std::string accessToken;

	JSCHEME(app, domain, accessToken);
};