
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"

#include <windows.h>
#include <shellapi.h>

import std;
import jira_app;

void TestNetwork()
{
	std::string auth_url = "https://auth.atlassian.com/authorize?audience=api.atlassian.com&client_id=9kRa3WQXnsoGo2SS690tLszrk05tcjhx&scope=read%3Ajira-work%20write%3Ajira-work%20read%3Ajira-user&redirect_uri=https%3A%2F%2Falprog.github.io%2Fgiraud%2Fauth.html&state=${YOUR_USER_BOUND_VALUE}&response_type=code&prompt=consent";

	ShellExecuteA(0, 0, auth_url.c_str(), 0, 0, SW_SHOW);

	auto app = JiraApp();

	std::string code = "eyJhbGciOiJIUzI1NiJ9.eyJqdGkiOiJkOTUyYTNiMi02YzVmLTQ3YTktYTlkNS00MTZhMmQ4Y2NmMGMiLCJzdWIiOiI1NTcwNTg6YjZjYzc2ZGItN2M5MC00ODQyLWE0NWEtMzhiNWE1ZDE1OGIxIiwibmJmIjoxNzQ1ODYyMzA1LCJpc3MiOiJhdXRoLmF0bGFzc2lhbi5jb20iLCJpYXQiOjE3NDU4NjIzMDUsImV4cCI6MTc0NTg2MjYwNSwiYXVkIjoiOWtSYTNXUVhuc29HbzJTUzY5MHRMc3pyazA1dGNqaHgiLCJjbGllbnRfYXV0aF90eXBlIjoiUE9TVCIsImh0dHBzOi8vaWQuYXRsYXNzaWFuLmNvbS92ZXJpZmllZCI6dHJ1ZSwiaHR0cHM6Ly9pZC5hdGxhc3NpYW4uY29tL3VqdCI6ImQ5NTJhM2IyLTZjNWYtNDdhOS1hOWQ1LTQxNmEyZDhjY2YwYyIsInNjb3BlIjpbInJlYWQ6amlyYS11c2VyIiwicmVhZDpqaXJhLXdvcmsiLCJ3cml0ZTpqaXJhLXdvcmsiXSwiaHR0cHM6Ly9pZC5hdGxhc3NpYW4uY29tL2F0bF90b2tlbl90eXBlIjoiQVVUSF9DT0RFIiwiaHR0cHM6Ly9pZC5hdGxhc3NpYW4uY29tL2hhc1JlZGlyZWN0VXJpIjp0cnVlLCJodHRwczovL2lkLmF0bGFzc2lhbi5jb20vc2Vzc2lvbl9pZCI6Ijk0ZmQ3ZmFiLTQ0ZTktNDQyMy05MzgzLTcyOTMxYmM1Y2EyOCIsImh0dHBzOi8vaWQuYXRsYXNzaWFuLmNvbS9wcm9jZXNzUmVnaW9uIjoidXMtZWFzdC0xIn0.5Jk_mqFaSd8--9OIO87x5vGJ3P4YQXLjM2wzONTkUdU";

	httplib::Client cli("https://auth.atlassian.com");

	constexpr const char* fmt = R"({{"grant_type": "authorization_code","client_id": "{}","client_secret": "{}","code": "{}","redirect_uri": "{}"}})";

	std::string body = std::format(fmt, app.id, app.secret, code, app.redirect_uri);
	std::string contentType = "application/json";

	auto res = cli.Post("/oauth/token", body, contentType);
	res->status;
	std::string s = res->body;
}