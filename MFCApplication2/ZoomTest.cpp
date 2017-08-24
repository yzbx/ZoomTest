#include "ZoomTest.h"
//#include <iostream>
//using namespace std;

ZoomTest::ZoomTest() {
	m_pAuthServiceMgr = new CAuthServiceMgr();
	m_pMeetingServiceMgr = new CMeetingServiceMgr();
}

ZoomTest::~ZoomTest() {

	//Destroy Meeting Service.
	if (m_pMeetingServiceMgr) {
		/*if(m_pMeetingServiceMgr->UnInit()){
			cout << "uninit m_pMeetingServiceMgr okay" << endl;
		}
		else {
			cout << "uninit m_pMeetingServiceMgr failed" << endl;
		}*/
		showMessage(m_pMeetingServiceMgr->UnInit(), "uninit m_pMeetingServiceMgr");
	}
		

	//Destroy Auth Service and clean up SDK
	if (m_pAuthServiceMgr)
	{
		/*if (m_pAuthServiceMgr->LogOut()) {
			cout << "logout m_pAuthServiceMgr okay" << endl;
		}
		else {
			cout << "logout m_pAuthServiceMgr failed" << endl;
		}*/
		showMessage(m_pAuthServiceMgr->LogOut(), "logout m_pAuthServiceMgr");
		/*if (m_pAuthServiceMgr->UnInit()) {
			cout << "uninit m_pAuthServiceMgr okay" << endl;
		}
		else {
			cout << "uninit m_pAuthServiceMgr failed" << endl;
		}*/

		showMessage(m_pAuthServiceMgr->UnInit(), "uninit m_pAuthServiceMgr");
	}

	if (m_pAuthServiceMgr)
	{
		delete m_pAuthServiceMgr;
		m_pAuthServiceMgr = NULL;
	}

	if (m_pMeetingServiceMgr) {
		delete m_pMeetingServiceMgr;
		m_pMeetingServiceMgr = NULL;
	}

	//ZOOM_SDK_NAMESPACE::CleanUPSDK();
}

// step 2.1
bool ZoomTest::Login() {
	std::wstring strEmail = L"test888@123.com";
	std::wstring strPassword = L"123456";
	if (strEmail.length() <= 0 || strPassword.length() <= 0)
		return false;

	bool bRememberMe = false;

	ZOOM_SDK_NAMESPACE::LoginParam param;
	param.userName = strEmail.c_str();
	param.password = strPassword.c_str();
	param.bRememberMe = bRememberMe;

	return m_pAuthServiceMgr->Login(param);
}

//step 1
bool ZoomTest::SDKAuth() {

	std::wstring strWebDomain = L"https://www.zoomus.cn";
	std::wstring strKey = L"9c9Wqx90nlVNrF74zy1ZBZkv1xcvMVHQIIzI";
	std::wstring strSecret = L"xJiH1xKmBYyQd6NE91Qch52gMdGAnKq90rkw";
	if (strWebDomain.length() <= 0 || strKey.length() <= 0 || strSecret.length() <= 0)
		return false;
	
	ZOOM_SDK_NAMESPACE::InitParam initParam;
	initParam.strWebDomain = strWebDomain.c_str();
	if (m_pAuthServiceMgr) {
		bool flag = m_pAuthServiceMgr->Init(initParam);
		if (!flag)
			return false;
	}
	else {
		return false;
	}

	ZOOM_SDK_NAMESPACE::AuthParam authParam;
	authParam.appKey = strKey.c_str();
	authParam.appSecret = strSecret.c_str();

	bool flag = m_pAuthServiceMgr->SDKAuth(authParam);
	if (flag)
		return true;
	else
		return false;
}

//step 3: NormalUserStart
bool ZoomTest::Start() {
	ZOOM_SDK_NAMESPACE::StartParam startParam;
	startParam.userType = ZOOM_SDK_NAMESPACE::SDK_UT_NORMALUSER;
	ZOOM_SDK_NAMESPACE::StartParam4NormalUser& normalParam = startParam.param.normaluserStart;
	normalParam.meetingNumber = 18145983052;

	if (!m_pMeetingServiceMgr->Init()) {
		return false;
	}

	return m_pMeetingServiceMgr->Start(startParam);
}

bool ZoomTest::APIUserStart()
{
	std::wstring strMeetingNumber, strUserId, strUserToken, strUserName;
	strMeetingNumber = L"18145983052";
	strUserId = L"GWCkySQfQ9mTdc03O5YCRA";
	strUserToken = L"Nexej8R5LheGX6CLq7m2wyXGqaKKMihQK8tyZnatKXA.BgMYY1M1WFdHVm94eFYxYjNaQ2FKK1JQdz09QDQ4YTc1NWI5MTUwNzc1NjgxZjAwNDA5NDkwMmYyYWQ0ODJjMWUzOTkxOGQxNzc0NGRkMzhmN2QwMWNiZGQxOTUADDNDQkF1b2lZUzNzPQ";
	strUserName = L"testdev";
	if (strMeetingNumber.length() <= 0 || strUserId.length() <= 0 || strUserToken.length() <= 0 || strUserName.length() <= 0)
		return false;

	ZOOM_SDK_NAMESPACE::StartParam startParam;
	startParam.userType = ZOOM_SDK_NAMESPACE::SDK_UT_APIUSER;
	ZOOM_SDK_NAMESPACE::StartParam4APIUser& apiuserParam = startParam.param.apiuserStart;

	apiuserParam.userID = strUserId.c_str();
	apiuserParam.userToken = strUserToken.c_str();
	apiuserParam.meetingNumber = _wtoi64(strMeetingNumber.c_str());
	apiuserParam.userName = strUserName.c_str();

	if (!m_pMeetingServiceMgr->Init()) {
		return false;
	}

	return m_pMeetingServiceMgr->Start(startParam);
}

//step 4: NormalUserJoin
bool ZoomTest::Join() {
	ZOOM_SDK_NAMESPACE::JoinParam joinParam;
	joinParam.userType = ZOOM_SDK_NAMESPACE::SDK_UT_NORMALUSER;
	ZOOM_SDK_NAMESPACE::JoinParam4NormalUser& normalParam = joinParam.param.normaluserJoin;
	normalParam.meetingNumber = 18145983052;
	normalParam.userName = L"";
	normalParam.psw = L"";

	return m_pMeetingServiceMgr->Join(joinParam);
}
bool ZoomTest::End() {
	if (m_pMeetingServiceMgr == NULL)
		return false;

	return m_pMeetingServiceMgr->End();
}
bool ZoomTest::Leave() {
	if (m_pMeetingServiceMgr == NULL)
		return false;

	return m_pMeetingServiceMgr->Leave();
}

void ZoomTest::showMessage(bool status, std::string str) {

	if (status) {
		std::string outstr = str + " okay \n";
		OutputDebugStringA(outstr.c_str());
		//cout << str << " okay" << endl;
	}
	else {
		std::string outstr = str + " failed \n";
		OutputDebugStringA(outstr.c_str());
		//cout << str << " failed" << endl;
	}
}