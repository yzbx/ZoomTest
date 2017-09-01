#pragma once
#include <map>
#include <iostream>
#include <vector>
class WinJson
{
public:
	WinJson();
	~WinJson();
	std::map<std::string, std::string> process(std::string jsonstr);

private:
	std::string currentstr = "";
	int pos = 0;
	std::vector<int> keys;
	std::vector<int> values;
	std::map<std::string, std::string> jsonmap;

	void init();
	void ActionDoubleQuotes();
	void ActionBraces();
	void ActionBraket();
	void ActionValue();

	const char DoubleQuotes = '"';
	int DoubleQuotesFlag = 0;
	const char InclinedBar = '\\';
	int InclinedBarFlag = 0;
	const char Colon = ':';
	int ColonFlag = 0;
	const char LeftBraces = '{';
	const char RightBraces = '}';
	int BracesFlag = 0;
	const char LeftBraket = '[';
	const char RightBraket = ']';
	int BraketFlag = 0;
	const std::string numberstr = "1234567890.";
	const std::string boolstr = "TtFf";
	const std::string nullstr = "Nn";

	const int JsonUnknown = 0;
	const int JsonNumber = 1;
	const int JsonObject = 2;
	const int JsonArray = 3;
	const int JsonString = 4;
	const int JsonBool = 5;
	const int JsonNull = 6;

	int JsonContext = JsonUnknown;
};