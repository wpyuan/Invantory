// C_Menu.cpp : 实现文件
//

#include "stdafx.h"
#include "Invantory.h"
#include "C_Menu.h"
#include "afxdialogex.h"


// C_Menu 对话框

IMPLEMENT_DYNAMIC(C_Menu, CDialogEx)

C_Menu::C_Menu(CWnd* pParent /*=NULL*/)
	: CDialogEx(C_Menu::IDD, pParent)
{

}

C_Menu::~C_Menu()
{
}

void C_Menu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCBUTTON1, m_1);
	DDX_Control(pDX, IDC_MFCBUTTON2, m_2);
	DDX_Control(pDX, IDC_MFCBUTTON3, m_3);
	DDX_Control(pDX, IDC_MFCBUTTON4, m_4);
	DDX_Control(pDX, IDC_MFCBUTTON5, m_5);
	DDX_Control(pDX, IDC_MFCBUTTON6, m_6);
	DDX_Control(pDX, IDC_MFCBUTTON7, m_7);
	DDX_Control(pDX, IDC_MFCBUTTON8, m_8);
	DDX_Control(pDX, IDC_MFCBUTTON9, m_9);
	DDX_Control(pDX, IDC_MFCBUTTON10, m_10);
	DDX_Control(pDX, IDC_MFCBUTTON11, m_11);
	DDX_Control(pDX, IDC_MFCBUTTON12, m_12);
	DDX_Control(pDX, IDC_MFCBUTTON13, m_13);
	DDX_Control(pDX, IDC_MFCBUTTON14, m_14);
	DDX_Control(pDX, IDC_MFCBUTTON15, m_15);
	DDX_Control(pDX, IDC_MFCBUTTON16, m_16);
	DDX_Control(pDX, IDC_MFCBUTTON17, m_17);
	DDX_Control(pDX, IDC_MFCBUTTON18, m_18);
	DDX_Control(pDX, IDC_EDIT1, m_time);
	DDX_Control(pDX, IDC_SHOCKWAVEFLASH1, m_exit);
}


BEGIN_MESSAGE_MAP(C_Menu, CDialogEx)
	ON_BN_CLICKED(IDC_MFCBUTTON1, &C_Menu::OnKuCunMenu)
	ON_BN_CLICKED(IDC_MFCBUTTON2, &C_Menu::OnDingDanMenu)
	ON_BN_CLICKED(IDC_MFCBUTTON3, &C_Menu::OnCustomerMenu)
//	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_MFCBUTTON4, &C_Menu::OnRenew)
	ON_BN_CLICKED(IDC_MFCBUTTON5, &C_Menu::OnKunCunAdd)
	ON_BN_CLICKED(IDC_MFCBUTTON6, &C_Menu::OnKuCunSearch)
	ON_BN_CLICKED(IDC_MFCBUTTON7, &C_Menu::OnKuCunStatistics)
	ON_BN_CLICKED(IDC_MFCBUTTON8, &C_Menu::OnKuCunHistory)
	ON_BN_CLICKED(IDC_MFCBUTTON9, &C_Menu::OnKuCunUpdata)
	ON_BN_CLICKED(IDC_MFCBUTTON10, &C_Menu::OnDingDanAdd)
	ON_BN_CLICKED(IDC_MFCBUTTON11, &C_Menu::OnDD_s_u_d)
	ON_BN_CLICKED(IDC_MFCBUTTON12, &C_Menu::OnDDtj)
	ON_BN_CLICKED(IDC_MFCBUTTON14, &C_Menu::OnProfit)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// C_Menu 消息处理程序


BOOL C_Menu::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_exit.LoadMovie(0,_T("D:\\进销存\\X.swf") );
	m_exit.Play();
	 SYSTEMTIME st;
	CString strDate,strTime;
	GetLocalTime(&st);
	strDate.Format("%4d-%2d-%2d",st.wYear,st.wMonth,st.wDay);
	strTime.Format("%2d:%2d:%2d",st.wHour,st.wMinute,st.wSecond);
	m_time.SetWindowTextA("启动系统时间："+strDate+"  "+strTime); 
	GetDlgItem(IDC_MFCBUTTON1)->SetFont(&m_editFont);// 设置新字体
	GetDlgItem(IDC_MFCBUTTON2)->SetFont(&m_editFont);// 设置新字体
	GetDlgItem(IDC_MFCBUTTON3)->SetFont(&m_editFont);// 设置新字体
	
	GetDlgItem(IDC_MFCBUTTON4)->SetFont(&m_Font2);// 设置新字体
	GetDlgItem(IDC_EDIT1)->SetFont(&m_Font3);
	int i=1008;
	for(i=1008;i<=1022;i++)
		if(i!=1010)
			GetDlgItem(i)->SetFont(&m_Font2);// 设置新字体
	

	m_1.SetFaceColor(RGB(11,74,125));
	m_1.SetTextColor(RGB(255,255,255));
	m_1.SetTextHotColor(RGB(255,0,255));
	m_2.SetFaceColor(RGB(11,74,125));
	m_2.SetTextColor(RGB(255,255,255));
	m_2.SetTextHotColor(RGB(255,0,255));
	m_3.SetFaceColor(RGB(11,74,125));
	m_3.SetTextColor(RGB(255,255,255));
	m_3.SetTextHotColor(RGB(255,0,255));

	m_4.SetFaceColor(RGB(255, 201, 240));
	m_5.SetFaceColor(RGB(255, 201, 240));
	m_6.SetFaceColor(RGB(255, 201, 240));
	m_7.SetFaceColor(RGB(255, 201, 240));
	m_8.SetFaceColor(RGB(255, 201, 240));
	m_9.SetFaceColor(RGB(255, 201, 240));
	m_10.SetFaceColor(RGB(255, 201, 240));
	m_11.SetFaceColor(RGB(255, 201, 240));
	m_12.SetFaceColor(RGB(255, 201, 240));
	m_13.SetFaceColor(RGB(255, 201, 240));
	m_14.SetFaceColor(RGB(255, 201, 240));
	m_15.SetFaceColor(RGB(255, 201, 240));
	m_16.SetFaceColor(RGB(255, 201, 240));
	m_17.SetFaceColor(RGB(255, 201, 240));
	m_18.SetFaceColor(RGB(255, 201, 240));

	m_4.SetTextColor(RGB(11,74,125));
	m_4.SetTextHotColor(RGB(204,232,207));
	m_5.SetTextColor(RGB(11,74,125));
	m_5.SetTextHotColor(RGB(204,232,207));
	m_6.SetTextColor(RGB(11,74,125));
	m_6.SetTextHotColor(RGB(204,232,207));
	m_7.SetTextColor(RGB(11,74,125));
	m_7.SetTextHotColor(RGB(204,232,207));
	m_8.SetTextColor(RGB(11,74,125));
	m_8.SetTextHotColor(RGB(204,232,207));
	m_9.SetTextColor(RGB(11,74,125));
	m_9.SetTextHotColor(RGB(204,232,207));
	m_10.SetTextColor(RGB(11,74,125));
	m_10.SetTextHotColor(RGB(204,232,207));
	m_11.SetTextColor(RGB(11,74,125));
	m_11.SetTextHotColor(RGB(204,232,207));
	m_12.SetTextColor(RGB(11,74,125));
	m_12.SetTextHotColor(RGB(204,232,207));
	m_13.SetTextColor(RGB(11,74,125));
	m_13.SetTextHotColor(RGB(204,232,207));
	m_14.SetTextColor(RGB(11,74,125));
	m_14.SetTextHotColor(RGB(204,232,207));
	m_15.SetTextColor(RGB(11,74,125));
	m_15.SetTextHotColor(RGB(204,232,207));
	m_16.SetTextColor(RGB(11,74,125));
	m_16.SetTextHotColor(RGB(204,232,207));
	m_17.SetTextColor(RGB(11,74,125));
	m_17.SetTextHotColor(RGB(204,232,207));
	m_18.SetTextColor(RGB(11,74,125));
	m_18.SetTextHotColor(RGB(204,232,207));

	m_kca.Create(IDD_KuCunADD,this); 
	m_kcr.Create(IDD_KuCunGX,this);
	m_kctj.Create(IDD_KuCunTJ,this);
	m_kch.Create(IDD_history,this);
	m_kcu.Create(IDD_KuCunUpdata,this);
	m_dda.Create(IDD_DDadd,this);
	m_dd3.Create(IDD_DDSUD,this);
	m_kcs.Create(IDD_KuCunSearch,this);
	m_ddtj.Create(IDD_DDTJ,this);
	m_ddp.Create(IDD_Profit,this);
	m_c.Create(IDD_Customer,this);
	GetDlgItem(IDC_Child)->GetWindowRect(&m_kcac);  
    ScreenToClient(m_kcac);
	m_kca.MoveWindow(m_kcac);
	m_kca.ShowWindow(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void C_Menu::OnKuCunMenu()
{
	m_kca.ShowWindow(0);
	m_kcr.ShowWindow(0);
	m_kctj.ShowWindow(0);
	m_kch.ShowWindow(0);
	m_kcu.ShowWindow(0);
	m_kcs.ShowWindow(0);

	m_dda.ShowWindow(0);
	m_dd3.ShowWindow(0);
	m_ddtj.ShowWindow(0);
	m_ddp.ShowWindow(0);

	m_c.ShowWindow(0);
	GetDlgItem(IDC_MFCBUTTON4)->ShowWindow(1);
	GetDlgItem(IDC_MFCBUTTON5)->ShowWindow(1);
	GetDlgItem(IDC_MFCBUTTON6)->ShowWindow(1);
	GetDlgItem(IDC_MFCBUTTON7)->ShowWindow(1);
	GetDlgItem(IDC_MFCBUTTON8)->ShowWindow(1);
	GetDlgItem(IDC_MFCBUTTON9)->ShowWindow(1);

	GetDlgItem(IDC_MFCBUTTON10)->ShowWindow(0);
	GetDlgItem(IDC_MFCBUTTON11)->ShowWindow(0);
	GetDlgItem(IDC_MFCBUTTON12)->ShowWindow(0);
	GetDlgItem(IDC_MFCBUTTON13)->ShowWindow(0);
	GetDlgItem(IDC_MFCBUTTON14)->ShowWindow(0);

	GetDlgItem(IDC_MFCBUTTON15)->ShowWindow(0);
	GetDlgItem(IDC_MFCBUTTON16)->ShowWindow(0);
	GetDlgItem(IDC_MFCBUTTON17)->ShowWindow(0);
	GetDlgItem(IDC_MFCBUTTON18)->ShowWindow(0);

	m_1.SetFaceColor(RGB(11,100,125));
	m_2.SetFaceColor(RGB(11,74,125));
	m_3.SetFaceColor(RGB(11,74,125));
	m_4.SetFaceColor(RGB(255, 201, 240));
	m_5.SetFaceColor(RGB(255, 201, 240));
	m_6.SetFaceColor(RGB(255, 201, 240));
	m_7.SetFaceColor(RGB(255, 201, 240));
	m_8.SetFaceColor(RGB(255, 201, 240));
	m_9.SetFaceColor(RGB(255, 201, 240));
	m_10.SetFaceColor(RGB(255, 201, 240));
	m_11.SetFaceColor(RGB(255, 201, 240));
	m_12.SetFaceColor(RGB(255, 201, 240));
	m_13.SetFaceColor(RGB(255, 201, 240));
	m_14.SetFaceColor(RGB(255, 201, 240));
	m_15.SetFaceColor(RGB(255, 201, 240));
	m_16.SetFaceColor(RGB(255, 201, 240));
	m_17.SetFaceColor(RGB(255, 201, 240));
	m_18.SetFaceColor(RGB(255, 201, 240));
}


void C_Menu::OnDingDanMenu()
{
	m_kca.ShowWindow(0);
	m_kcr.ShowWindow(0);
	m_kctj.ShowWindow(0);
	m_kch.ShowWindow(0);
	m_kcu.ShowWindow(0);
	m_kcs.ShowWindow(0);

	m_dda.ShowWindow(0);
	m_dd3.ShowWindow(0);
	m_ddtj.ShowWindow(0);
	m_ddp.ShowWindow(0);

	m_c.ShowWindow(0);
	GetDlgItem(IDC_MFCBUTTON4)->ShowWindow(0);
	GetDlgItem(IDC_MFCBUTTON5)->ShowWindow(0);
	GetDlgItem(IDC_MFCBUTTON6)->ShowWindow(0);
	GetDlgItem(IDC_MFCBUTTON7)->ShowWindow(0);
	GetDlgItem(IDC_MFCBUTTON8)->ShowWindow(0);
	GetDlgItem(IDC_MFCBUTTON9)->ShowWindow(0);

	GetDlgItem(IDC_MFCBUTTON15)->ShowWindow(0);
	GetDlgItem(IDC_MFCBUTTON16)->ShowWindow(0);
	GetDlgItem(IDC_MFCBUTTON17)->ShowWindow(0);
	GetDlgItem(IDC_MFCBUTTON18)->ShowWindow(0);

	GetDlgItem(IDC_MFCBUTTON10)->ShowWindow(1);
	GetDlgItem(IDC_MFCBUTTON11)->ShowWindow(1);
	GetDlgItem(IDC_MFCBUTTON12)->ShowWindow(1);
	GetDlgItem(IDC_MFCBUTTON13)->ShowWindow(1);
	if(password=="88785268")
		GetDlgItem(IDC_MFCBUTTON14)->ShowWindow(0);
	else
		GetDlgItem(IDC_MFCBUTTON14)->ShowWindow(1);

	m_2.SetFaceColor(RGB(11,100,125));
	m_1.SetFaceColor(RGB(11,74,125));
	m_3.SetFaceColor(RGB(11,74,125));
	m_4.SetFaceColor(RGB(255, 201, 240));
	m_5.SetFaceColor(RGB(255, 201, 240));
	m_6.SetFaceColor(RGB(255, 201, 240));
	m_7.SetFaceColor(RGB(255, 201, 240));
	m_8.SetFaceColor(RGB(255, 201, 240));
	m_9.SetFaceColor(RGB(255, 201, 240));
	m_10.SetFaceColor(RGB(255, 201, 240));
	m_11.SetFaceColor(RGB(255, 201, 240));
	m_12.SetFaceColor(RGB(255, 201, 240));
	m_13.SetFaceColor(RGB(255, 201, 240));
	m_14.SetFaceColor(RGB(255, 201, 240));
	m_15.SetFaceColor(RGB(255, 201, 240));
	m_16.SetFaceColor(RGB(255, 201, 240));
	m_17.SetFaceColor(RGB(255, 201, 240));
	m_18.SetFaceColor(RGB(255, 201, 240));
}


void C_Menu::OnCustomerMenu()
{
	m_kca.ShowWindow(0);
	m_kcr.ShowWindow(0);
	m_kctj.ShowWindow(0);
	m_kch.ShowWindow(0);
	m_kcu.ShowWindow(0);
	m_kcs.ShowWindow(0);

	m_dda.ShowWindow(0);
	m_dd3.ShowWindow(0);
	m_ddtj.ShowWindow(0);
	m_ddp.ShowWindow(0);

	m_c.MoveWindow(m_kcac);
	m_c.ShowWindow(1);
	GetDlgItem(IDC_MFCBUTTON4)->ShowWindow(0);
	GetDlgItem(IDC_MFCBUTTON5)->ShowWindow(0);
	GetDlgItem(IDC_MFCBUTTON6)->ShowWindow(0);
	GetDlgItem(IDC_MFCBUTTON7)->ShowWindow(0);
	GetDlgItem(IDC_MFCBUTTON8)->ShowWindow(0);
	GetDlgItem(IDC_MFCBUTTON9)->ShowWindow(0);

	GetDlgItem(IDC_MFCBUTTON10)->ShowWindow(0);
	GetDlgItem(IDC_MFCBUTTON11)->ShowWindow(0);
	GetDlgItem(IDC_MFCBUTTON12)->ShowWindow(0);
	GetDlgItem(IDC_MFCBUTTON13)->ShowWindow(0);
	GetDlgItem(IDC_MFCBUTTON14)->ShowWindow(0);

	GetDlgItem(IDC_MFCBUTTON15)->ShowWindow(1);
	GetDlgItem(IDC_MFCBUTTON16)->ShowWindow(1);
	GetDlgItem(IDC_MFCBUTTON17)->ShowWindow(1);
	GetDlgItem(IDC_MFCBUTTON18)->ShowWindow(1);

	m_3.SetFaceColor(RGB(11,100,125));
	m_1.SetFaceColor(RGB(11,74,125));
	m_2.SetFaceColor(RGB(11,74,125));
	m_4.SetFaceColor(RGB(255, 201, 240));
	m_5.SetFaceColor(RGB(255, 201, 240));
	m_6.SetFaceColor(RGB(255, 201, 240));
	m_7.SetFaceColor(RGB(255, 201, 240));
	m_8.SetFaceColor(RGB(255, 201, 240));
	m_9.SetFaceColor(RGB(255, 201, 240));
	m_10.SetFaceColor(RGB(255, 201, 240));
	m_11.SetFaceColor(RGB(255, 201, 240));
	m_12.SetFaceColor(RGB(255, 201, 240));
	m_13.SetFaceColor(RGB(255, 201, 240));
	m_14.SetFaceColor(RGB(255, 201, 240));
	m_15.SetFaceColor(RGB(255, 201, 240));
	m_16.SetFaceColor(RGB(255, 201, 240));
	m_17.SetFaceColor(RGB(255, 201, 240));
	m_18.SetFaceColor(RGB(255, 201, 240));
}


//void C_Menu::OnLButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	CDialogEx::OnLButtonDown(nFlags, point);
//}


void C_Menu::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CBitmap m_Back;
	m_Back.LoadBitmap(IDB_BITMAP17);
	//定义一个内存设备描述表对象（即后备缓冲区）  
	CDC mdc;
	//建立与屏幕设备描述表（前端缓冲区）兼容的内存设备描述表句柄（后备缓冲区）  
    mdc.CreateCompatibleDC(&dc); 
	mdc.SelectObject(&m_Back);
	//将后备缓冲区中的图形拷贝到前端缓冲区  
	dc.BitBlt(0,50,1366,799,&mdc,10,0,SRCCOPY);
	//绘图完成后的清理  
	m_Back.DeleteObject();  
	mdc.DeleteDC();
	// 不为绘图消息调用 CDialogEx::OnPaint()
}


void C_Menu::OnRenew()
{
	m_kca.ShowWindow(0);
	m_kctj.ShowWindow(0);
	m_kch.ShowWindow(0);
	m_kcu.ShowWindow(0);
	m_kcs.ShowWindow(0);
	m_kcr.MoveWindow(m_kcac);
	m_kcr.ShowWindow(1);

	m_4.SetFaceColor(RGB(255,255,255));
	m_5.SetFaceColor(RGB(255, 201, 240));
	m_6.SetFaceColor(RGB(255, 201, 240));
	m_7.SetFaceColor(RGB(255, 201, 240));
	m_8.SetFaceColor(RGB(255, 201, 240));
	m_9.SetFaceColor(RGB(255, 201, 240));
	
}



void C_Menu::OnKunCunAdd()
{
	m_5.SetFaceColor(RGB(255,255,255));
	m_4.SetFaceColor(RGB(255, 201, 240));
	m_6.SetFaceColor(RGB(255, 201, 240));
	m_7.SetFaceColor(RGB(255, 201, 240));
	m_8.SetFaceColor(RGB(255, 201, 240));
	m_9.SetFaceColor(RGB(255, 201, 240));
	m_kcr.ShowWindow(0);
	m_kctj.ShowWindow(0);
	m_kch.ShowWindow(0);
	m_kcu.ShowWindow(0);
	m_kcs.ShowWindow(0);
	m_kca.ShowWindow(1);

	
}


void C_Menu::OnKuCunSearch()
{
	m_6.SetFaceColor(RGB(255,255,255));
	m_4.SetFaceColor(RGB(255, 201, 240));
	m_5.SetFaceColor(RGB(255, 201, 240));
	m_7.SetFaceColor(RGB(255, 201, 240));
	m_8.SetFaceColor(RGB(255, 201, 240));
	m_9.SetFaceColor(RGB(255, 201, 240));
	m_kcr.ShowWindow(0);
	m_kca.ShowWindow(0);
	m_kctj.ShowWindow(0);
	m_kch.ShowWindow(0);
	m_kcu.ShowWindow(0);
	m_kcs.MoveWindow(m_kcac);
	m_kcs.ShowWindow(1);
}


void C_Menu::OnKuCunStatistics()
{
	m_kcr.ShowWindow(0);
	m_kca.ShowWindow(0);
	m_kch.ShowWindow(0);
	m_kcu.ShowWindow(0);
	m_kcs.ShowWindow(0);
	m_kctj.MoveWindow(m_kcac);
	m_kctj.ShowWindow(1);
	KCTJ=true;
	m_7.SetFaceColor(RGB(255,255,255));
	m_4.SetFaceColor(RGB(255, 201, 240));
	m_5.SetFaceColor(RGB(255, 201, 240));
	m_6.SetFaceColor(RGB(255, 201, 240));
	m_8.SetFaceColor(RGB(255, 201, 240));
	m_9.SetFaceColor(RGB(255, 201, 240));
}


void C_Menu::OnKuCunHistory()
{
	m_kcr.ShowWindow(0);
	m_kca.ShowWindow(0);
	m_kctj.ShowWindow(0);
	m_kcu.ShowWindow(0);
	m_kcs.ShowWindow(0);
	m_kch.MoveWindow(m_kcac);
	m_kch.ShowWindow(1);
	KCLS=true;
	m_8.SetFaceColor(RGB(255,255,255));
	m_4.SetFaceColor(RGB(255, 201, 240));
	m_5.SetFaceColor(RGB(255, 201, 240));
	m_7.SetFaceColor(RGB(255, 201, 240));
	m_6.SetFaceColor(RGB(255, 201, 240));
	m_9.SetFaceColor(RGB(255, 201, 240));
	
}


void C_Menu::OnKuCunUpdata()
{
	m_kcr.ShowWindow(0);
	m_kca.ShowWindow(0);
	m_kctj.ShowWindow(0);
	m_kch.ShowWindow(0);
	m_kcs.ShowWindow(0);
	m_kcu.MoveWindow(m_kcac);
	m_kcu.ShowWindow(1);

	m_9.SetFaceColor(RGB(255,255,255));
	m_4.SetFaceColor(RGB(255, 201, 240));
	m_5.SetFaceColor(RGB(255, 201, 240));
	m_7.SetFaceColor(RGB(255, 201, 240));
	m_6.SetFaceColor(RGB(255, 201, 240));
	m_8.SetFaceColor(RGB(255, 201, 240));
}


void C_Menu::OnDingDanAdd()
{
	m_dd3.ShowWindow(0);
	m_ddtj.ShowWindow(0);
	m_ddp.ShowWindow(0);
	m_dda.MoveWindow(m_kcac);
	m_dda.ShowWindow(1);
	m_10.SetFaceColor(RGB(255,255,255));
	m_11.SetFaceColor(RGB(255, 201, 240));
	m_12.SetFaceColor(RGB(255, 201, 240));
	m_13.SetFaceColor(RGB(255, 201, 240));
	m_14.SetFaceColor(RGB(255, 201, 240));
}


void C_Menu::OnDD_s_u_d()
{
	m_dda.ShowWindow(0);
	m_ddtj.ShowWindow(0);
	m_ddp.ShowWindow(0);
	m_dd3.MoveWindow(m_kcac);
	m_dd3.ShowWindow(1);
	m_11.SetFaceColor(RGB(255,255,255));
	m_10.SetFaceColor(RGB(255, 201, 240));
	m_12.SetFaceColor(RGB(255, 201, 240));
	m_13.SetFaceColor(RGB(255, 201, 240));
	m_14.SetFaceColor(RGB(255, 201, 240));
}


void C_Menu::OnDDtj()
{
	m_dda.ShowWindow(0);
	m_dd3.ShowWindow(0);
	m_ddp.ShowWindow(0);
	m_ddtj.MoveWindow(m_kcac);
	m_ddtj.ShowWindow(1);
	m_12.SetFaceColor(RGB(255,255,255));
	m_10.SetFaceColor(RGB(255, 201, 240));
	m_11.SetFaceColor(RGB(255, 201, 240));
	m_13.SetFaceColor(RGB(255, 201, 240));
	m_14.SetFaceColor(RGB(255, 201, 240));
}


void C_Menu::OnProfit()
{
	m_dda.ShowWindow(0);
	m_dd3.ShowWindow(0);
	m_ddtj.ShowWindow(0);
	m_ddp.MoveWindow(m_kcac);
	m_ddp.ShowWindow(1);
	LR_flag=true;
	m_14.SetFaceColor(RGB(255,255,255));
	m_10.SetFaceColor(RGB(255, 201, 240));
	m_11.SetFaceColor(RGB(255, 201, 240));
	m_12.SetFaceColor(RGB(255, 201, 240));
	m_13.SetFaceColor(RGB(255, 201, 240));
}


BOOL C_Menu::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(pMsg->message==WM_LBUTTONDOWN)
	{
		/*CString x;
		x.Format("%d ,%d",pMsg->pt.x,pMsg->pt.y);  1236 693 1356 711
			MessageBox(x);*/
		if(pMsg->pt.x>=1236&&pMsg->pt.x<=1356&&pMsg->pt.y>=693&&pMsg->pt.y<=711)
			if(MessageBox("确定退出系统？","提示",MB_ICONEXCLAMATION|MB_OKCANCEL)==IDOK)
				CDialogEx::OnOK();
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


void C_Menu::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SendMessage(WM_SYSCOMMAND,SC_MOVE|HTCAPTION,0);
	CDialogEx::OnLButtonDown(nFlags, point);
}
