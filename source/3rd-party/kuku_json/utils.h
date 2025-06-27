#pragma once

#include "serializable.h"

std::string readFileText(std::string path);

namespace json
{
	template <typename T>
	T loadFromFile(std::string path)
	{
		std::string text = readFileText(path);
		nlohmann::json json = nlohmann::json::parse(text);
		return from_json<T>(json);
	}
}