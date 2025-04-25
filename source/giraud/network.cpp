
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"

import std;

void TestNetwork()
{
	std::string auth_url = "https://auth.atlassian.com/authorize?audience=api.atlassian.com&client_id=9kRa3WQXnsoGo2SS690tLszrk05tcjhx&scope=read%3Ajira-work%20write%3Ajira-work%20read%3Ajira-user&redirect_uri=https%3A%2F%2Falprog.github.io%2Fgiraud%2Fauth_code.html&state=${YOUR_USER_BOUND_VALUE}&response_type=code&prompt=consent";

	std::string client_id = "9kRa3WQXnsoGo2SS690tLszrk05tcjhx";
	std::string secret = "";

	std::string code = "eyJhbGciOiJIUzI1NiJ9.eyJqdGkiOiIyNTMwYzQ5Yy03Mzc1LTRhYWYtYjIwNy00YTBmZjU0N2YyM2EiLCJzdWIiOiI1NTcwNTg6YjZjYzc2ZGItN2M5MC00ODQyLWE0NWEtMzhiNWE1ZDE1OGIxIiwibmJmIjoxNzQ1NTkxODcxLCJpc3MiOiJhdXRoLmF0bGFzc2lhbi5jb20iLCJpYXQiOjE3NDU1OTE4NzEsImV4cCI6MTc0NTU5MjE3MSwiYXVkIjoiOWtSYTNXUVhuc29HbzJTUzY5MHRMc3pyazA1dGNqaHgiLCJjbGllbnRfYXV0aF90eXBlIjoiUE9TVCIsImh0dHBzOi8vaWQuYXRsYXNzaWFuLmNvbS92ZXJpZmllZCI6dHJ1ZSwiaHR0cHM6Ly9pZC5hdGxhc3NpYW4uY29tL3VqdCI6IjI1MzBjNDljLTczNzUtNGFhZi1iMjA3LTRhMGZmNTQ3ZjIzYSIsInNjb3BlIjpbInJlYWQ6amlyYS11c2VyIiwicmVhZDpqaXJhLXdvcmsiLCJ3cml0ZTpqaXJhLXdvcmsiXSwiaHR0cHM6Ly9pZC5hdGxhc3NpYW4uY29tL2F0bF90b2tlbl90eXBlIjoiQVVUSF9DT0RFIiwiaHR0cHM6Ly9pZC5hdGxhc3NpYW4uY29tL2hhc1JlZGlyZWN0VXJpIjp0cnVlLCJodHRwczovL2lkLmF0bGFzc2lhbi5jb20vc2Vzc2lvbl9pZCI6IjBlZDkxYTNjLWI5YTMtNDAwZC04MWQzLWRjZGE3ZTAzODljNiIsImh0dHBzOi8vaWQuYXRsYXNzaWFuLmNvbS9wcm9jZXNzUmVnaW9uIjoidXMtZWFzdC0xIn0.YG6uJLwP4uj--tYxE1eZeTaGet0YFKdHsHcwVc9zniM";
	std::string redirect_uri = "https://github.com/alprog/giraud";

	httplib::Client cli("https://auth.atlassian.com");

	constexpr const char* fmt = R"({{"grant_type": "authorization_code","client_id": "{}","client_secret": "{}","code": "{}","redirect_uri": "{}"}})";

	std::string body = std::format(fmt, client_id, secret, code, redirect_uri);
	std::string contentType = "application/json";

	auto res = cli.Post("/oauth/token", body, contentType);
	res->status;
	std::string s = res->body;



}