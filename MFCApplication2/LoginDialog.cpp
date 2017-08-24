// LoginDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "LoginDialog.h"
#include "afxdialogex.h"


// LoginDialog 对话框

IMPLEMENT_DYNAMIC(LoginDialog, CDialogEx)

LoginDialog::LoginDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
{

}

LoginDialog::~LoginDialog()
{
}

void LoginDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(LoginDialog, CDialogEx)
END_MESSAGE_MAP()


// LoginDialog 消息处理程序
