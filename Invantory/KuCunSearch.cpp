// KuCunSearch.cpp : 实现文件
//

#include "stdafx.h"
#include "Invantory.h"
#include "KuCunSearch.h"
#include "afxdialogex.h"


// KuCunSearch 对话框

IMPLEMENT_DYNAMIC(KuCunSearch, CDialogEx)

KuCunSearch::KuCunSearch(CWnd* pParent /*=NULL*/)
	: CDialogEx(KuCunSearch::IDD, pParent)
{

}

KuCunSearch::~KuCunSearch()
{
}

void KuCunSearch::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCBUTTON1, m_1);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_d1);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_d2);
	DDX_Control(pDX, IDC_LIST1, m_L);
	DDX_Control(pDX, IDC_MFCBUTTON2, m_2);
}


BEGIN_MESSAGE_MAP(KuCunSearch, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_MFCBUTTON1, &KuCunSearch::OnSearch)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_MFCBUTTON2, &KuCunSearch::OnLS_Search)
END_MESSAGE_MAP()


// KuCunSearch 消息处理程序


void KuCunSearch::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CBitmap m_Back;
	m_Back.LoadBitmap(IDB_BITMAP26);
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


BOOL KuCunSearch::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_1.SetFaceColor(RGB(11,74,100));
	m_1.SetTextColor(RGB(255,255,255));
	m_1.SetTextHotColor(RGB(11,74,255));
	GetDlgItem(IDC_MFCBUTTON1)->SetFont(&m_editFont);// 设置新字体
	m_2.SetFaceColor(RGB(11,74,100));
	m_2.SetTextColor(RGB(255,255,255));
	m_2.SetTextHotColor(RGB(11,74,255));
	GetDlgItem(IDC_MFCBUTTON2)->SetFont(&m_editFont);// 设置新字体
	CRect rect;
	m_L.GetClientRect(&rect);
	// 为列表视图控件添加全行选中和栅格风格
	m_L.SetExtendedStyle(m_L.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	// 为列表视图控件添加6列   
	m_L.InsertColumn(0,_T("日期"),LVCFMT_CENTER,rect.Width()/6,0); //1 
    m_L.InsertColumn(1,_T("型号"),LVCFMT_CENTER,rect.Width()/6,1);//2
	m_L.InsertColumn(2,_T("入库"),LVCFMT_CENTER,rect.Width()/6,2); //3
	m_L.InsertColumn(3,_T("出库"),LVCFMT_CENTER,rect.Width()/6,3); //1 
    m_L.InsertColumn(4,_T("库存"),LVCFMT_CENTER,rect.Width()/6,4);//2
	m_L.InsertColumn(5,_T("备注"),LVCFMT_CENTER,rect.Width()/6,5); //3
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void KuCunSearch::OnSearch()
{
	datebase();
	CString xh,kc,bz,sql;
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
		GetDlgItem(IDC_EDIT3)->SetWindowTextA(xh);
		GetDlgItem(IDC_EDIT4)->SetWindowTextA(data[0]);
		GetDlgItem(IDC_EDIT5)->SetWindowTextA(data[1]);
	}
	else
		MessageBox("经查询，无此型号库存记录。请您复查型号是否正确输入！","提示",MB_ICONEXCLAMATION|MB_OK);
	mysql_free_result(m_result); //关联的内存会释放
}


void KuCunSearch::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(point.x>=1004&&point.x<=1032&&point.y>=11&&point.y<=39)
		SetCursor(LoadCursor(NULL, IDC_HAND));
	CDialogEx::OnMouseMove(nFlags, point);
}


void KuCunSearch::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(point.x>=1004&&point.x<=1032&&point.y>=11&&point.y<=39)
	{
		GetDlgItem(IDC_EDIT1)->SetWindowTextA("");
		GetDlgItem(IDC_EDIT3)->SetWindowTextA("");
		GetDlgItem(IDC_EDIT4)->SetWindowTextA("");
		GetDlgItem(IDC_EDIT5)->SetWindowTextA("");
		CDialogEx::OnOK();
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


void KuCunSearch::OnLS_Search()
{
	m_L.DeleteAllItems();
	CString rq1,rq2,sql,xh;
	CTime tm;
	m_d1.GetTime(tm);
	rq1=tm.Format("%Y%m%d");
	m_d2.GetTime(tm);
	rq2=tm.Format("%Y%m%d");

	GetDlgItem(IDC_EDIT6)->GetWindowTextA(xh);
	if(xh.IsEmpty())
		sql.Format("SELECT * FROM inventory.history where H_time>='%s' and H_time<='%s';",rq1,rq2);
	else
		sql.Format("SELECT * FROM inventory.history where H_time>='%s' and H_time<='%s' and H_type='%s';",rq1,rq2,xh);
	//执行查询
	MYSQL_RES *m_result;
	mysql_query(&m_sqlCon,sql);
	m_result=mysql_use_result(&m_sqlCon);
	CString data[7];
	MYSQL_ROW row;
	bool x=false;
	int i=0;
	while((row=mysql_fetch_row(m_result)))
	{
		x=true;
		//获取数据
		data[1]=row[1];
		data[2]=row[2];
		data[3]=row[3];
		data[4]=row[4];
		data[5]=row[5];
		data[6]=row[6];
		// 在列表视图控件中插入列表项，并设置列表子项文本
		m_L.InsertItem(i, data[1]);
	    m_L.SetItemText(i, 1,data[2] );
		m_L.SetItemText(i, 2,data[3] );
		m_L.SetItemText(i, 3,data[4] );
		m_L.SetItemText(i, 4,data[5] );
		m_L.SetItemText(i, 5,data[6] );
		i++;
	}
	if(!x)
		MessageBox("经查询，无此筛选条件历史记录。请您复查筛选条件是否正确输入！","提示",MB_ICONEXCLAMATION|MB_OK);
	mysql_free_result(m_result); //关联的内存会释放
}
