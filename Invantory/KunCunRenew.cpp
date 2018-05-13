// KunCunRenew.cpp : 实现文件
//

#include "stdafx.h"
#include "Invantory.h"
#include "KunCunRenew.h"
#include "afxdialogex.h"


// KunCunRenew 对话框

IMPLEMENT_DYNAMIC(KunCunRenew, CDialogEx)

KunCunRenew::KunCunRenew(CWnd* pParent /*=NULL*/)
	: CDialogEx(KunCunRenew::IDD, pParent)
{

}

KunCunRenew::~KunCunRenew()
{
}

void KunCunRenew::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCBUTTON1, m_1);
	DDX_Control(pDX, IDC_MFCBUTTON2, m_2);
	DDX_Control(pDX, IDC_MFCBUTTON3, m_3);
	DDX_Control(pDX, IDC_DATETIMEPICKER7, m_time);
}


BEGIN_MESSAGE_MAP(KunCunRenew, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_MFCBUTTON2, &KunCunRenew::OnClose)
	ON_BN_CLICKED(IDC_MFCBUTTON1, &KunCunRenew::OnSearch)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_MFCBUTTON3, &KunCunRenew::OnRenew)
END_MESSAGE_MAP()


// KunCunRenew 消息处理程序


void KunCunRenew::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CBitmap m_Back;
	m_Back.LoadBitmap(IDB_BITMAP19);
	//定义一个内存设备描述表对象（即后备缓冲区）  
	CDC mdc;
	//建立与屏幕设备描述表（前端缓冲区）兼容的内存设备描述表句柄（后备缓冲区）  
    mdc.CreateCompatibleDC(&dc); 
	mdc.SelectObject(&m_Back);
	//将后备缓冲区中的图形拷贝到前端缓冲区  
	dc.BitBlt(0,0,1050,580,&mdc,0,0,SRCCOPY);
	//绘图完成后的清理  
	m_Back.DeleteObject();  
	mdc.DeleteDC();
	// 不为绘图消息调用 CDialogEx::OnPaint()
}


BOOL KunCunRenew::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_1.SetFaceColor(RGB(255, 201, 240));
	m_1.SetTextColor(RGB(11,74,125));
	m_1.SetTextHotColor(RGB(204,232,207));
	m_2.SetFaceColor(RGB(255, 201, 240));
	m_2.SetTextColor(RGB(11,74,125));
	m_2.SetTextHotColor(RGB(204,232,207));
	m_3.SetFaceColor(RGB(255, 201, 240));
	m_3.SetTextColor(RGB(11,74,125));
	m_3.SetTextHotColor(RGB(204,232,207));
	GetDlgItem(IDC_MFCBUTTON1)->SetFont(&m_editFont);// 设置新字体
	GetDlgItem(IDC_MFCBUTTON2)->SetFont(&m_editFont);// 设置新字体
	GetDlgItem(IDC_MFCBUTTON3)->SetFont(&m_editFont);// 设置新字体

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void KunCunRenew::OnClose()
{
	if(MessageBox("确定关闭？","提示：" ,MB_ICONEXCLAMATION|MB_OKCANCEL)==IDOK)
	 {
		 CDialogEx::OnOK();
		 GetDlgItem(IDC_EDIT1)->SetWindowTextA("");
		 GetDlgItem(IDC_EDIT31)->SetWindowTextA("");
		 GetDlgItem(IDC_EDIT19)->SetWindowTextA("");
		 GetDlgItem(IDC_EDIT20)->SetWindowTextA("");
		 GetDlgItem(IDC_EDIT37)->SetWindowTextA("");
		 GetDlgItem(IDC_EDIT38)->SetWindowTextA("");
		 GetDlgItem(IDC_EDIT39)->SetWindowTextA("");
		 GetDlgItem(IDC_EDIT40)->SetWindowTextA("");
		 GetDlgItem(IDC_EDIT41)->SetWindowTextA("");
	 }
}


void KunCunRenew::OnSearch()
{
	datebase();
	CString xh;
	CString kc;
	CString bz;
	CString sql;
	GetDlgItem(IDC_EDIT1)->GetWindowTextA(xh);
	sql.Format("SELECT I_kc,I_remark FROM inventory.inventory where I_type='%s';",xh);
	//执行查询
	MYSQL_RES *m_result;
	mysql_query(&m_sqlCon,sql);
	m_result=mysql_use_result(&m_sqlCon);
	CString data[2];
	MYSQL_ROW row;
	if((row=mysql_fetch_row(m_result)))
	{
		//获取数据
		data[0]=row[0];
		data[1]=row[1];
		GetDlgItem(IDC_EDIT31)->SetWindowTextA(xh);
		GetDlgItem(IDC_EDIT37)->SetWindowTextA(xh);
		GetDlgItem(IDC_EDIT19)->SetWindowTextA(data[0]);
		GetDlgItem(IDC_EDIT20)->SetWindowTextA(data[1]);
		GetDlgItem(IDC_EDIT41)->SetWindowTextA(data[1]);
	}
	else
		MessageBox("经查询，无此型号库存记录。请您复查型号是否正确输入！","提示",MB_ICONEXCLAMATION|MB_OK);
	mysql_free_result(m_result); //关联的内存会释放
}


void KunCunRenew::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(point.x>=652&&point.x<=800&&point.y>=283&&point.y<=333)
		SetCursor(LoadCursor(NULL, IDC_HAND));
	CDialogEx::OnMouseMove(nFlags, point);
}


void KunCunRenew::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	/*CString x;
	x.Format("%d ,%d", point.x,point.y);652 283 800 333
	MessageBox(x);*/
	if(point.x>=652&&point.x<=800&&point.y>=283&&point.y<=333)
	{
		CString kc,rk,ck,kcs;
		double Kc,Rk,Ck,Kcs;
		GetDlgItem(IDC_EDIT19)->GetWindowTextA(kc);
		GetDlgItem(IDC_EDIT38)->GetWindowTextA(rk);
		GetDlgItem(IDC_EDIT39)->GetWindowTextA(ck);
		Kc=atof(kc);
		Rk=atof(rk);
		Ck=atof(ck);
		Kcs=Kc+Rk-Ck;
		kcs.Format("%.1lf",Kcs);
		GetDlgItem(IDC_EDIT40)->SetWindowTextA(kcs);
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


void KunCunRenew::OnRenew()
{
	    CString rq,xh,rk,ck,kc,bz;
		CTime tm;
		m_time.GetTime(tm);
		rq=tm.Format("%Y%m%d");
		GetDlgItem(IDC_EDIT37)->GetWindowTextA(xh);
		GetDlgItem(IDC_EDIT38)->GetWindowTextA(rk);
		GetDlgItem(IDC_EDIT39)->GetWindowTextA(ck);
		GetDlgItem(IDC_EDIT40)->GetWindowTextA(kc);
		GetDlgItem(IDC_EDIT41)->GetWindowTextA(bz);
		CString sql;
		sql.Format("update inventory.inventory set I_kc=%s where I_type='%s'",kc,xh);
		if(mysql_query(&m_sqlCon,sql)!=0)
			MessageBox("更新失败","提示",MB_ICONEXCLAMATION); 
		else
		{
			MessageBox("更新成功","提示",MB_ICONEXCLAMATION);
			sql.Format("INSERT INTO inventory.history value(null, '%s', '%s', %s, %s, %s, '%s')", rq,xh,rk,ck,kc,bz );
			mysql_query(&m_sqlCon, sql);
		}
}
