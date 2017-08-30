#pragma once
#include <map>
#include <iostream>
#include <vector>
using namespace std;
class WinJson
{
public:
	WinJson();
	~WinJson();
	std::map<std::string,std::string> process(std::string jsonstr);

private:
	std::string currentstr="";
	int pos = 0;
	vector<int> keys;
	vector<int> values;
	map<string, string> jsonmap;

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
	const string numberstr = "1234567890.";
	const string boolstr = "TtFf";
	const string nullstr = "Nn";

	const int JsonUnknown = 0;
	const int JsonNumber = 1;
	const int JsonObject = 2;
	const int JsonArray = 3;
	const int JsonString = 4;
	const int JsonBool = 5;
	const int JsonNull = 6;

	int JsonContext = JsonUnknown;
};