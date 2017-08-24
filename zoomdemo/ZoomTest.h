#pragma once
#include "authservicemgr.h"
#include "MeetingServiceMgr.h"

class ZoomTest
{
public:
	CAuthServiceMgr* m_pAuthServiceMgr;
	CMeetingServiceMgr* m_pMeetingServiceMgr;

public:
	ZoomTest();
	~ZoomTest();
	bool Login();
	bool SDKAuth();
	bool Start();
	bool APIUserStart();
	bool APIUserStart(std::wstring strMeetingNumber, std::wstring strUserId, std::wstring strUserToken, std::wstring strUserName);
	bool Join();
	bool End();
	bool Leave();
	void showMessage(bool status,std::string str);
};