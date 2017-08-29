#include "MyForm.h"
#include <Windows.h>
#include <winhttp.h>
#include <stdio.h>
#include <string>
#include <sstream>

//wstring高字节不为0，返回FALSE
std::string WinHttpDemo::WStringToString(const std::wstring &wstr)
{
	std::string str = "";
	int nLen = (int)wstr.length();
	str.resize(nLen, ' ');

	int nResult = WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)wstr.c_str(), nLen, (LPSTR)str.c_str(), nLen, NULL, NULL);

	if (nResult == 0)
	{
		return "";
	}

	return str;
}

void WinHttpDemo::MyForm::WinHttpTest()
{
	DWORD dwSize = 0;
	DWORD dwDownloaded = 0;
	LPSTR pszOutBuffer = NULL;
	HINTERNET  hSession = NULL,
		hConnect = NULL,
		hRequest = NULL;

	BOOL  bResults = FALSE;

	hSession = WinHttpOpen(L"User-Agent", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
	if(hSession){
		Console::WriteLine("Http Open Okay \n");
	}
	else {
		Console::WriteLine("http Open Failed \n");
		printf("Error %u in WinHttpTest2.\n", GetLastError());
	}

	if (hSession)
	{
		//not start with https://
		hConnect = WinHttpConnect(hSession, L"www.suimeeting.cn", INTERNET_DEFAULT_HTTP_PORT, 0);

		if (hConnect) {
			Console::WriteLine("http connect okay! \n");
		}
		else {
			Console::WriteLine("http connect failed! \n");
			printf("Error %u in WinHttpTest2.\n", GetLastError());
		}
	}

	if (hConnect)
	{
		//not start with "/Api/User/login..."
		hRequest = WinHttpOpenRequest(hConnect, L"POST", L"Api/User/login.html", L"HTTP/1.1", WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, 0);

		if (hRequest) {
			Console::WriteLine("Http Open Request Okay! \n");
		}
		else {
			Console::WriteLine("Http Open Request failed! \n");
			printf("Error %u in WinHttpTest2.\n", GetLastError());
		}
	}



	LPCWSTR header = L"Content-type: application/x-www-form-urlencoded/r/n";

	SIZE_T len = lstrlenW(header);

	WinHttpAddRequestHeaders(hRequest, header, DWORD(len), WINHTTP_ADDREQ_FLAG_ADD);

	if (hRequest)
	{
		//not start with "?a=xxx&b=xxx"
		std::string data = "apiversion=v1&safecode=c989e271e11455ea290252ec9e216912&site_id=0&phone=18210560183&password=123456";

		const void *ss = (const char *)data.c_str();

		bResults = WinHttpSendRequest(hRequest, 0, 0, const_cast<void *>(ss), data.length(), data.length(), 0);

		if (bResults) {
			Console::WriteLine("Http Send Request Okay! \n");
		}
		else {
			Console::WriteLine("Http Send Request Failed! \n");
			printf("Error %u in WinHttpTest2.\n", GetLastError());
		}

		////bResults=WinHttpSendRequest(hRequest,WINHTTP_NO_ADDITIONAL_HEADERS, 0,WINHTTP_NO_REQUEST_DATA, 0, 0, 0 );
	}

	if (bResults)
	{
		bResults = WinHttpReceiveResponse(hRequest, NULL);
		if (bResults) {
			Console::WriteLine("WinHttpReceiveResponse Okay! \n");
		}
		else {
			Console::WriteLine("WinHttpReceiveResponse Failed! \n");
			printf("Error %u in WinHttpTest2.\n", GetLastError());
		}
	}

	if (bResults)
	{
		std::stringstream ss;
		do
		{
			// Check for available data.

			dwSize = 0;

			if (!WinHttpQueryDataAvailable(hRequest, &dwSize))
			{
				printf("Error %u in WinHttpQueryDataAvailable.\n", GetLastError());

				break;
			}

			if (!dwSize)
				break;

			pszOutBuffer = new char[dwSize + 1];

			if (!pszOutBuffer)
			{
				printf("Out of memory\n");
				break;
			}

			ZeroMemory(pszOutBuffer, dwSize + 1);

			if (!WinHttpReadData(hRequest, (LPVOID)pszOutBuffer, dwSize, &dwDownloaded))
			{
				printf("Error %u in WinHttpReadData.\n", GetLastError());
			}
			else
			{
				printf("%s", pszOutBuffer);
				ss << pszOutBuffer;
			}

			delete[] pszOutBuffer;

			if (!dwDownloaded)
				break;

		} while (dwSize > 0);
		
		std::string readstr;
		ss >> readstr;
		printf("read all str is: \n %s", readstr.c_str());
	}



	if (hRequest) WinHttpCloseHandle(hRequest);
	if (hConnect) WinHttpCloseHandle(hConnect);
	if (hSession) WinHttpCloseHandle(hSession);
}

std::string WinHttpDemo::MyForm::WinHttpPost(std::map<std::string, std::wstring> param_map)
{
	std::wstring hostname=param_map["hostname"];
	std::wstring urlpath = param_map["urlpath"];
	std::wstring apiversion = param_map["apiversion"];
	std::wstring password = param_map["password"];
	std::wstring phone = param_map["phone"];
	std::wstring safecode = param_map["safecode"];
	std::wstring site_id = param_map["site_id"];
	

	DWORD dwSize = 0;
	DWORD dwDownloaded = 0;
	LPSTR pszOutBuffer = NULL;
	HINTERNET  hSession = NULL,
		hConnect = NULL,
		hRequest = NULL;

	BOOL  bResults = FALSE;

	hSession = WinHttpOpen(L"User-Agent", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
	if (hSession) {
		Console::WriteLine("Http Open Okay \n");
	}
	else {
		Console::WriteLine("http Open Failed \n");
		printf("Error %u in WinHttpTest2.\n", GetLastError());
	}

	if (hSession)
	{
		//not start with https://
		hConnect = WinHttpConnect(hSession, hostname.c_str(), INTERNET_DEFAULT_HTTP_PORT, 0);

		if (hConnect) {
			Console::WriteLine("http connect okay! \n");
		}
		else {
			Console::WriteLine("http connect failed! \n");
			printf("Error %u in WinHttpTest2.\n", GetLastError());
		}
	}

	if (hConnect)
	{
		//not start with "/Api/User/login..."
		hRequest = WinHttpOpenRequest(hConnect, L"POST", urlpath.c_str(), L"HTTP/1.1", WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, 0);

		if (hRequest) {
			Console::WriteLine("Http Open Request Okay! \n");
		}
		else {
			Console::WriteLine("Http Open Request failed! \n");
			printf("Error %u in WinHttpTest2.\n", GetLastError());
		}
	}



	LPCWSTR header = L"Content-type: application/x-www-form-urlencoded/r/n";

	SIZE_T len = lstrlenW(header);

	WinHttpAddRequestHeaders(hRequest, header, DWORD(len), WINHTTP_ADDREQ_FLAG_ADD);

	if (hRequest)
	{
		//not start with "?a=xxx&b=xxx"
		std::string data = "";
		data = data + "apiversion=" + WStringToString(apiversion);
		data = data +"&safecode="+ WStringToString(safecode);
		data = data + "&site_id=" + WStringToString(site_id);
		data = data + "&phone=" + WStringToString(phone);
		data = data + "&password=" + WStringToString(password);

		const void *ss = (const char *)data.c_str();

		bResults = WinHttpSendRequest(hRequest, 0, 0, const_cast<void *>(ss), data.length(), data.length(), 0);

		if (bResults) {
			Console::WriteLine("Http Send Request Okay! \n");
		}
		else {
			Console::WriteLine("Http Send Request Failed! \n");
			printf("Error %u in WinHttpTest2.\n", GetLastError());
		}

		////bResults=WinHttpSendRequest(hRequest,WINHTTP_NO_ADDITIONAL_HEADERS, 0,WINHTTP_NO_REQUEST_DATA, 0, 0, 0 );
	}

	if (bResults)
	{
		bResults = WinHttpReceiveResponse(hRequest, NULL);
		if (bResults) {
			Console::WriteLine("WinHttpReceiveResponse Okay! \n");
		}
		else {
			Console::WriteLine("WinHttpReceiveResponse Failed! \n");
			printf("Error %u in WinHttpTest2.\n", GetLastError());
		}
	}

	std::string returnstr = "";
	if (bResults)
	{
		std::stringstream ss;
		do
		{
			// Check for available data.

			dwSize = 0;

			if (!WinHttpQueryDataAvailable(hRequest, &dwSize))
			{
				printf("Error %u in WinHttpQueryDataAvailable.\n", GetLastError());

				break;
			}

			if (!dwSize)
				break;

			pszOutBuffer = new char[dwSize + 1];

			if (!pszOutBuffer)
			{
				printf("Out of memory\n");
				break;
			}

			ZeroMemory(pszOutBuffer, dwSize + 1);

			if (!WinHttpReadData(hRequest, (LPVOID)pszOutBuffer, dwSize, &dwDownloaded))
			{
				printf("Error %u in WinHttpReadData.\n", GetLastError());
			}
			else
			{
				printf("%s", pszOutBuffer);
				ss << pszOutBuffer;
			}

			delete[] pszOutBuffer;

			if (!dwDownloaded)
				break;

		} while (dwSize > 0);

		ss >> returnstr;
	}



	if (hRequest) WinHttpCloseHandle(hRequest);
	if (hConnect) WinHttpCloseHandle(hConnect);
	if (hSession) WinHttpCloseHandle(hSession);

	return returnstr;
}
