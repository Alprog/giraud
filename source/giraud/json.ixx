module;
#include "kuku_json/serializable.h"
#include "kuku_json/scheme.h"
export module json;

import std;

export nlohmann::detail::json_sax_dom_callback_parser;

export namespace json
{
	std::string readFileText(std::string path)
	{
		std::ifstream stream(path);
		std::ostringstream ss;
		ss << stream.rdbuf();
		return ss.str();
	}

	template <typename T>
	T loadFromFile(T& object, std::string path)
	{
		std::string text = readFileText(path);
		nlohmann::json json = nlohmann::json::parse(text);
		//from_json<T>(json);

		return {};
	}
}
