export module session;

import std;

export class Session
{
public:
	bool IsLogined() const
	{
		return !accessToken.empty();
	}

	std::string accessToken;
};