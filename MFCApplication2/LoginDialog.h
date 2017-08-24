#pragma once


// LoginDialog 对话框

class LoginDialog : public CDialogEx
{
	DECLARE_DYNAMIC(LoginDialog)

public:
	LoginDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~LoginDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION2_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
