export module configuration;

import jira_app;

export class Configuration
{
public:
	Configuration()
		: app{ GetPublicGiraudApp() }
	{
	}

	JiraApp app;
};