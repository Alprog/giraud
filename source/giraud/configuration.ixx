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

	JiraApp app;
	std::string domain;

	JSCHEME(app, domain);
};