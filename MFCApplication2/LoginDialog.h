#pragma once


// LoginDialog �Ի���

class LoginDialog : public CDialogEx
{
	DECLARE_DYNAMIC(LoginDialog)

public:
	LoginDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~LoginDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION2_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
