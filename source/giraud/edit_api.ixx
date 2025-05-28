export module edit_api;

import configuration;
import database;

export class EditAPI
{
public:
	EditAPI(Configuration& config, Database& database)
		: config{ config }
		, database{ database }
	{
	}

private:
	Configuration& config;
	Database& database;
};