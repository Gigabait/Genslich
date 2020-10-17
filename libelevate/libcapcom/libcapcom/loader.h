#pragma once

#include <fstream>
#include "native.h"

namespace loader
{
	bool load_vuln_driver(uint8_t* driver, int size, const std::wstring& path, const std::wstring& service)
	{
		std::ofstream file(path.c_str(), std::ios_base::out | std::ios_base::binary);
		file.write((char*)driver, size);
		file.close();
		return native::load_driver(path, service);
	}

	bool unload_vuln_driver(const std::wstring& path, const std::wstring& service)
	{
		if (!native::unload_driver(service))
			return false;
		return !std::remove(std::string(path.begin(), path.end()).c_str());
	}
}