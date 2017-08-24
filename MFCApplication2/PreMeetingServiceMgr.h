#pragma once

#include <windows.h>
#include <string>
#include "zoom_sdk.h"
#include "premeeting_service_interface.h"

class CPreMeetingServiceMgr : public ZOOM_SDK_NAMESPACE::IPreMeetingServiceEvent
{
public:
	CPreMeetingServiceMgr();
	virtual ~CPreMeetingServiceMgr();


public:
	bool Init();
	bool ListMeeting();
	//ZOOM_SDK_NAMESPACE::IPreMeetingService* GetPreMeetingService();

public:
	virtual void onListMeeting(ZOOM_SDK_NAMESPACE::PremeetingAPIResult result, ZOOM_SDK_NAMESPACE::IList<UINT64 >* lstMeetingList);
	virtual void onScheduleOrEditMeeting(ZOOM_SDK_NAMESPACE::PremeetingAPIResult result, UINT64 meetingUniqueID);
	virtual void onDeleteMeeting(ZOOM_SDK_NAMESPACE::PremeetingAPIResult result);

private:
	ZOOM_SDK_NAMESPACE::IPreMeetingService* m_pPreMeetingService;
};