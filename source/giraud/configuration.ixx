export module configuration;

import jira_app;
import user;

export class Configuration
{
public:
	Configuration()
		: app{ GetPublicGiraudApp() }
	{
	}

	JiraApp app;
	User user;
};