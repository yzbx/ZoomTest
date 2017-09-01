#pragma once
#include <Windows.h>
#include <winhttp.h>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
using namespace System;
class WinHttp001
{
public:
	WinHttp001();
	~WinHttp001();
	std::string WStringToString(const std::wstring &wstr);
	void WinHttpTest();
	std::string WinHttpPost(std::map<std::string, std::wstring> param_map);
};

