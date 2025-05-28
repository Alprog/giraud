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

	const Configuration& GetConfig() const { return config; }
	const Database& GetDatabase() const { return database; }

private:
	Configuration& config;
	Database& database;
};