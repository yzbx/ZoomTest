
// MFCApplication2Dlg.h : 头文件
//

#pragma once
#include "ZoomTest.h"
#include "afxwin.h"

// CMFCApplication2Dlg 对话框
class CMFCApplication2Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication2Dlg(CWnd* pParent = NULL);	// 标准构造函数
	~CMFCApplication2Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	ZoomTest* zoomtest;
	CFont QRTitle_font;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedMfclink1();
	// 自定义字体
	CStatic m_font;
};
