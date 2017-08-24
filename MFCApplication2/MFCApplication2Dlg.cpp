
// MFCApplication2Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "ZoomTest.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
	
}


void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication2Dlg �Ի���



CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	zoomtest = new ZoomTest();
}

CMFCApplication2Dlg::~CMFCApplication2Dlg()
{
	delete zoomtest;
	zoomtest = NULL;
}


void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_QRTITLE, m_font);
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCApplication2Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_MFCLINK1, &CMFCApplication2Dlg::OnBnClickedMfclink1)
END_MESSAGE_MAP()


// CMFCApplication2Dlg ��Ϣ�������

BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	QRTitle_font.CreatePointFont(140, L"Arial",NULL);
	m_font.SetFont(&QRTitle_font, true);
	m_font.SetWindowText(L"��ά��ɨ���¼");

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCApplication2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCApplication2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication2Dlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	
}


void CMFCApplication2Dlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMFCApplication2Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	if (zoomtest->SDKAuth()) {
		MessageBox(_T("SDK auth okay!"), _T("SDK auth"));
	}
	else {
		MessageBox(_T("SDK auth faild!"), _T("SDK auth"));
	}

	//zoomtest->showMessage(zoomtest->SDKAuth(), "SDK auth");

	/*if (zoomtest->Login()) {
		MessageBox(_T("Login okay!"), _T("Login"));
	}
	else {
		MessageBox(_T("Login faild!"), _T("Login"));
	}*/

	//zoomtest->showMessage(zoomtest->Login(), "Login");

	/*if (zoomtest->Start()) {
		MessageBox(_T("Start okay!"), _T("Start"));
	}
	else {
		MessageBox(_T("Start faild!"), _T("Start"));
	}*/

	//zoomtest->showMessage(zoomtest->Start(), "Start");

	if (zoomtest->APIUserStart()) {
		MessageBox(_T("APIUserStart okay!"), _T("APIUserStart"));
	}
	else {
		MessageBox(_T("APIUserStart faild!"), _T("APIUserStart"));
	}
	//zoomtest->showMessage(zoomtest->APIUserStart(), "APIUserStart");

}


void CMFCApplication2Dlg::OnBnClickedMfclink1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MessageBox(_T("����Ҫ��ôע�᣿"), _T("Start"));
}

HBRUSH CMFCApplication2Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	if (IDC_STATIC_QRTITLE == pWnd->GetDlgCtrlID()||IDC_STATIC_PHONE==pWnd->GetDlgCtrlID())//�жϷ�����Ϣ�Ŀռ��Ƿ��Ǹþ�̬�ı���
	{
		pDC->SetTextColor(RGB(255, 0, 0));//�����ı���ɫΪ��ɫ
		//pDC->SetBkMode(OPAQUE);//�����ı�����ģʽΪ͸��
		//pDC->SetBkColor(RGB(0, 0, 255));//�����ı�����Ϊ��ɫ
		//hbr = CreateSolidBrush(RGB(0, 255, 0));//�ؼ��ı���ɫΪ��ɫ
	}
	return hbr;//���������ػ�ؼ������Ļ�ˢ
}