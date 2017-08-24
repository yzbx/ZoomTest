#include "MyForm.h"
using namespace zoomdemo;
#pragma comment(lib, "Wininet.lib")

#include <WinInet.h>
void webget(void)
{
	// TODO: Add extra validation here  
	HINTERNET hssetion;
	HINTERNET hConnect;
	HINTERNET hRequrest;

	hssetion = InternetOpen(L"httpDownload", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	if (NULL == hssetion)
	{
		MessageBox::Show("open failed");
		return;
	}

	hConnect = InternetConnect(hssetion, L"www.baidu.com", INTERNET_DEFAULT_HTTP_PORT,
		NULL, NULL, INTERNET_SERVICE_HTTP, 0, 0);
	if (NULL == hConnect)
	{
		MessageBox::Show("connect failed");
		return;
	}

	LPCWSTR pFileType = L"*/*";
	hRequrest = HttpOpenRequest(hConnect, L"GET",L"/index.html", L"HTTP/1.1", NULL,
		&pFileType, INTERNET_FLAG_RELOAD, 0);

	if (NULL == hRequrest)
	{
		MessageBox::Show("open requrest failed");
		return;
	}

	BOOL bBet = HttpSendRequest(hRequrest, NULL, 0, NULL, 0);
	if (!bBet)
	{
		MessageBox::Show("send request failed");
		return;
	}
	DWORD BufLen = 4 * 1024 * 10;
	char buffer[4 * 1024 * 10] = { 0 };
	DWORD infoLen = 4 * 1024 * 10;

	DWORD dwIndex = 0;
	bool RetQueryInfo = HttpQueryInfo(hRequrest,
		HTTP_QUERY_CONTENT_LENGTH,
		buffer, &infoLen,
		&dwIndex);
	if (!RetQueryInfo)
	{
		MessageBox::Show("query info failed");
		return;
	}
	int FileSize = atoi(buffer); // 文件大小  


	DWORD dwRequest; // 请求下载的字节数  
	DWORD dwRead; // 实际读出的字节数  
	dwRequest = BufLen;


	FILE* f = fopen("Download", "ab");
	while (true)
	{
		memset(buffer, 0, BufLen);
		bool ReadReturn = InternetReadFile(hRequrest,
			(LPVOID)buffer,
			dwRequest,
			&dwRead);
		if (!ReadReturn)break;
		if (dwRead == 0)break;
		// 保存数据  
		//  buffer[dwRead]='\0';  

		//  FileWrite(iFileHandle, buffer, dwRead);  
		fwrite(buffer, 1, dwRead, f);
		//  dwCount = dwCount + dwRead;  
		// 发出下载进程事件  

	}
}
int main(array<System::String^>^args) {
	//webget();
	Application::EnableVisualStyles();
	Application::Run(gcnew MyForm());
	return 0;
}
