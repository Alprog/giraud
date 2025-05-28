#pragma once

#include "field.h"

import std;

namespace json
{
	class scheme
	{
	public:
		scheme(std::vector<json::base_field*> fields)
			: fields{ fields }
		{
		}

		std::vector<json::base_field*> fields;
	};
}
