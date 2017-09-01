#include "WinJson.h"
#include <cassert>

WinJson::WinJson()
{
}


WinJson::~WinJson()
{
}

void WinJson::init() {
	DoubleQuotesFlag = 0;
	InclinedBarFlag = 0;
	ColonFlag = 0;
	BracesFlag = 0;
	BraketFlag = 0;

	JsonContext = JsonUnknown;
}

void WinJson::ActionDoubleQuotes()
{
	switch (DoubleQuotesFlag)
	{
	case 1:
	{
		//remove '"' for key
		this->keys.push_back(this->pos + 1);
		break;
	}
	case 2:
	{
		//remove '"' for key
		this->keys.push_back(this->pos - 1);
		break;
	}
	case 3:
	{
		if (BracesFlag == 0 && BraketFlag == 0) {
			this->values.push_back(this->pos);
		}
		break;
	}
	case 4:
	{
		if (BracesFlag == 0 && BraketFlag == 0) {

			int start = this->values.back();
			int len = this->pos - start;
			std::string valuestr = this->currentstr.substr(start, len + 1);

			int keys_len = this->keys.size();
			assert(keys_len >= 2);
			start = keys[keys_len - 2];
			len = keys[keys_len - 1] - start;
			std::string keystr = this->currentstr.substr(start, len + 1);
			this->jsonmap[keystr] = valuestr;

			this->values.push_back(this->pos);
		}
		break;
	}
	default:
		break;
	}
}

void WinJson::ActionBraces()
{
	switch (BracesFlag)
	{
	case 1:
	{
		this->values.push_back(this->pos);
		break;
	}
	case 0:
	{
		int start = this->values.back();
		int len = this->pos - start;
		std::string valuestr = this->currentstr.substr(start, len + 1);

		int keys_len = this->keys.size();
		start = keys[keys_len - 2];
		len = keys[keys_len - 1] - start;
		std::string keystr = this->currentstr.substr(start, len + 1);
		this->jsonmap[keystr] = valuestr;

		this->values.push_back(this->pos);
		break;
	}
	default:
		break;
	}
}

void WinJson::ActionBraket()
{
	switch (BraketFlag)
	{
	case 1:
	{
		this->values.push_back(this->pos);
		break;
	}
	case 0:
	{
		int start = this->values.back();
		int len = this->pos - start;
		std::string valuestr = this->currentstr.substr(start, len + 1);

		int keys_len = this->keys.size();
		start = keys[keys_len - 2];
		len = keys[keys_len - 1] - start;
		std::string keystr = this->currentstr.substr(start, len + 1);
		this->jsonmap[keystr] = valuestr;

		this->values.push_back(this->pos);
		break;
	}
	default:
		break;
	}
}

void WinJson::ActionValue()
{
	int start = this->values.back();
	int len = this->pos - start;
	std::string valuestr = this->currentstr.substr(start, len);

	int keys_len = this->keys.size();
	start = keys[keys_len - 2];
	len = keys[keys_len - 1] - start;
	//remove "," from value string
	std::string keystr = this->currentstr.substr(start, len + 1);
	this->jsonmap[keystr] = valuestr;

	this->values.push_back(this->pos);
}

std::map<std::string, std::string> WinJson::process(std::string jsonstr) {
	init();

	this->currentstr = jsonstr;
	if (currentstr[0] == '{') {
		currentstr.erase(0, 1);
		int strsize = currentstr.size();
		currentstr.erase(strsize - 1, 1);

		std::cout << "\n after change {xxx} to xxx \n" << std::endl;
		printf("currentstr is:\n %s \n", currentstr.c_str());
	}

	this->pos = 0;
	for (char c : currentstr) {
		switch (c)
		{
		case '"':
		{
			if (InclinedBarFlag % 2 == 0) {
				DoubleQuotesFlag++;

				if (ColonFlag > 0 && JsonContext == JsonUnknown) {
					JsonContext = JsonString;
				}

				if (JsonContext == JsonUnknown || JsonContext == JsonString) {
					ActionDoubleQuotes();
				}
			}
			break;
		}
		case ':':
		{
			if (JsonContext == JsonUnknown) {
				assert(DoubleQuotesFlag == 2);
			}
			ColonFlag++;
			break;
		}
		case '{':
		{
			if (InclinedBarFlag % 2 == 0) {
				BracesFlag++;
				if (ColonFlag > 0 && JsonContext == JsonUnknown) {
					JsonContext = JsonObject;
					ActionBraces();
				}
			}
			break;
		}
		case '}':
		{
			if (InclinedBarFlag % 2 == 0) {
				BracesFlag--;

				if (BracesFlag == 0 && JsonContext == JsonObject) {
					ActionBraces();
				}
			}

			break;
		}
		case '[':
		{
			if (InclinedBarFlag % 2 == 0) {
				BraketFlag++;
				if (ColonFlag > 0 && JsonContext == JsonUnknown) {
					JsonContext = JsonArray;
					ActionBraket();
				}
			}

			break;
		}
		case ']':
		{
			if (InclinedBarFlag % 2 == 0) {
				BraketFlag--;

				if (BraketFlag == 0 && JsonContext == JsonArray) {
					ActionBraket();
				}
			}

			break;
		}
		case '\\':
		{
			InclinedBarFlag++;
			break;
		}
		case ',':
		{
			bool needPartInit = false;
			if (JsonContext == JsonNumber || JsonContext == JsonBool || JsonContext == JsonNull) {
				ActionValue();
				needPartInit = true;
			}
			else if (JsonContext == JsonArray && BraketFlag == 0) {
				needPartInit = true;
			}
			else if (JsonContext == JsonObject && BracesFlag == 0) {
				needPartInit = true;
			}
			else if (JsonContext == JsonString && DoubleQuotesFlag == 4) {
				needPartInit = true;
			}

			if (needPartInit) {
				InclinedBarFlag = 0;
				DoubleQuotesFlag = 0;
				ColonFlag = 0;
				BracesFlag = 0;
				BraketFlag = 0;
				JsonContext = JsonUnknown;
			}

			break;
		}
		default:
			if (ColonFlag > 0 && JsonContext == JsonUnknown) {
				//number value
				if (this->numberstr.find(c) != -1) {
					this->JsonContext = this->JsonNumber;
					this->values.push_back(this->pos);
				}
				else if (this->boolstr.find(c) != -1) {
					JsonContext = JsonBool;
				}
				else if (this->nullstr.find(c) != -1) {
					JsonContext = JsonNull;
				}
			}

			break;
		}

		if (c != '\\') {
			InclinedBarFlag = 0;
		}

		this->pos++;
	}

	return this->jsonmap;
}