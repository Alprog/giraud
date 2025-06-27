module;
#include "kuku_json.h"
export module configuration;

import jira_app;
import user;
import std;

export class Configuration : public json::serializable
{
public:
	void load()
	{
		*this = json::loadFromFile<Configuration>("config.txt");
		if (!app.IsValid())
		{
			app = GetPublicGiraudApp();
		}
	}

	//Configuration& operator=(const Configuration& config) = default;

	JiraApp app;
	std::string domain;
	std::string accessToken;

	JSCHEME(app, domain, accessToken);
};