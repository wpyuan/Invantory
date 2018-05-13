
// InvantoryDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Invantory.h"
#include "InvantoryDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CInvantoryDlg 对话框

static int times;


CInvantoryDlg::CInvantoryDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInvantoryDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CInvantoryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, m_login);
}

BEGIN_MESSAGE_MAP(CInvantoryDlg, CDialogEx)
	ON_WM_QUERYDRAGICON()
	ON_WM_PAINT()
ON_WM_TIMER()
ON_WM_LBUTTONDOWN()
ON_WM_NCHITTEST()
ON_BN_CLICKED(IDOK, &CInvantoryDlg::OnLogin)
END_MESSAGE_MAP()


// CInvantoryDlg 消息处理程序

BOOL CInvantoryDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	SetTimer(1,150,NULL);
	flag=129;
	m_login.SetFaceColor(RGB(50,205,255));
	m_login.SetTextColor(RGB(255,255,255));
	m_login.SetTextHotColor(RGB(255,0,255));
	Font();
	GetDlgItem(IDOK)->SetFont(&m_editFont);// 设置新字体
	times=4;
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}




//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CInvantoryDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CInvantoryDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	//定义一个位图对象 
	CBitmap m_Back;
	m_Back.LoadBitmap(flag);
	//定义一个内存设备描述表对象（即后备缓冲区）  
	CDC mdc;
	//建立与屏幕设备描述表（前端缓冲区）兼容的内存设备描述表句柄（后备缓冲区）  
    mdc.CreateCompatibleDC(&dc); 
	////这时还不能绘图，因为没有位图的设备描述表是不能绘图的  
	////下面建立一个与屏幕设备描述表（或者内存设备描述表）兼容的位图  
	//m_Back.CreateCompatibleBitmap(&dc,800,600);  
	////将位图选入到内存设备描述表  
	////只有选入了位图的设备描述表才有地方绘图，画到指定的位图上  
	//CBitmap *pOldBit=mdc.SelectObject(&m_Back);
	//先用背景色将位图清除干净，这里我用的是白色作为背景  
	//你也可以用自己应该用的颜色 
	//绘图
	mdc.SelectObject(&m_Back);
	//将后备缓冲区中的图形拷贝到前端缓冲区  
	dc.BitBlt(0,0,553,174,&mdc,0,0,SRCCOPY);
	CBitmap m_b2;
	m_b2.LoadBitmap(IDB_BITMAP16);
	mdc.SelectObject(&m_b2);
	//将后备缓冲区中的图形拷贝到前端缓冲区  
	dc.BitBlt(0,174,553,200,&mdc,0,0,SRCCOPY);
	//绘图完成后的清理  
	m_Back.DeleteObject();  
	mdc.DeleteDC();
	m_b2.DeleteObject();
	// 不为绘图消息调用 CDialogEx::OnPaint()
}

void CInvantoryDlg::OnTimer(UINT_PTR nIDEvent)
{
	CRect r(0,0,553,174);
	InvalidateRect(r,0);
	if(nIDEvent==1)
		flag++;
	if(flag==144)
		KillTimer(1);
	CDialogEx::OnTimer(nIDEvent);
}


void CInvantoryDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(point.x>=490&&point.y<=50)
		CDialogEx::OnOK();
	/*CString x;
	x.Format("%d ,%d",point.x,point.y);
	MessageBox(x);*/

	CDialogEx::OnLButtonDown(nFlags, point);
}


LRESULT CInvantoryDlg::OnNcHitTest(CPoint point)
{
	CRect rc;
	GetClientRect(&rc);
	ClientToScreen(&rc);
	int x=point.x;
	int y=point.y;
	if (x>rc.left && x<rc.right-100 && y>rc.top && y<rc.top+25) {
		return HTCAPTION;
	}
	return CDialogEx::OnNcHitTest(point);
}


void CInvantoryDlg::OnLogin()
{
	GetDlgItem(IDC_EDIT1)->GetWindowTextA(password);
	if(password=="88785268")
	{
		if(MessageBox("员工登录成功","提示",MB_ICONEXCLAMATION|MB_OKCANCEL)==IDOK)
		{
			CDialogEx::OnOK();
			C_Menu dlg;
			dlg.DoModal();
		}
	}
	else if(password=="6335598")
	{
		if(MessageBox("管理员登录成功","提示",MB_ICONEXCLAMATION|MB_OKCANCEL)==IDOK)
		{
			CDialogEx::OnOK();
			C_Menu dlg;
			dlg.DoModal();
		}
	}
	else
	{
		if(times!=0)
			times--;
		if(times==3)
			if(MessageBox("输入密码错误，请重新输入，您还有3次机会","提示",MB_ICONEXCLAMATION|MB_OKCANCEL)==IDCANCEL)
				CDialogEx::OnOK();
		if(times==2)
			if(MessageBox("输入密码错误，请重新输入，您还有2次机会","提示",MB_ICONEXCLAMATION|MB_OKCANCEL)==IDCANCEL)
				CDialogEx::OnOK();
		if(times==1)
			if(MessageBox("输入密码错误，请重新输入，您还有1次机会","提示",MB_ICONEXCLAMATION|MB_OKCANCEL)==IDCANCEL)
				CDialogEx::OnOK();
		if(times==0)
			if(MessageBox("输入密码错误，3次机会用完，系统进入安全静默模式，24小时后自动解除或找管理员解除！","提示",MB_ICONEXCLAMATION|MB_OKCANCEL)==IDCANCEL)
				CDialogEx::OnOK();
	}
}
