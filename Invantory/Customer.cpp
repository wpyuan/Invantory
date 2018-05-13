// Customer.cpp : 实现文件
//

#include "stdafx.h"
#include "Invantory.h"
#include "Customer.h"
#include "afxdialogex.h"

// Customer 对话框

IMPLEMENT_DYNAMIC(Customer, CDialogEx)

Customer::Customer(CWnd* pParent /*=NULL*/)
	: CDialogEx(Customer::IDD, pParent)
{

}

Customer::~Customer()
{
}

void Customer::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_L);
}


BEGIN_MESSAGE_MAP(Customer, CDialogEx)
	ON_WM_PAINT()
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, &Customer::OnNMRClickList1)
	ON_COMMAND(ID_32771, &Customer::On32771)
	ON_COMMAND(ID_32772, &Customer::On32772)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// Customer 消息处理程序


void Customer::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CBitmap m_Back;
	m_Back.LoadBitmap(IDB_BITMAP29);
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


void Customer::OnNMRClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	 NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
           if(pNMListView->iItem != -1)
           {
                DWORD dwPos = GetMessagePos();
                CPoint point( LOWORD(dwPos), HIWORD(dwPos) );
                CMenu menu;
                VERIFY( menu.LoadMenu( IDR_MENU1 ) );
                CMenu* popup = menu.GetSubMenu(0);
                ASSERT( popup != NULL );
                popup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this );

				int i=m_L.GetSelectionMark();//获得选 中行的行标
				customer_name=m_L.GetItemText(i,0);//i是行，j是列。m_list是个list control 对象
		   } 
	*pResult = 0;
}
void Customer::show()
{
	m_L.DeleteAllItems();
	CString sql;
	CString text="";
	GetDlgItem(IDC_EDIT1)->GetWindowTextA(text);
	if(text.IsEmpty())
		sql.Format("SELECT * FROM inventory.customer;");
	else
		sql.Format("SELECT * FROM inventory.customer where C_name like '%s%s%s' or C_phone like '%s%s%s'  or C_address like '%s%s%s' or C_wuliu like '%s%s%s';","%",text,"%","%",text,"%","%",text,"%","%",text,"%");
	//执行查询
	MYSQL_RES *m_result;
	mysql_query(&m_sqlCon,sql);
	m_result=mysql_use_result(&m_sqlCon);
	int i=0;
	CString data[5];
	MYSQL_ROW row;
	while((row=mysql_fetch_row(m_result)))
	{
		//获取数据
		data[1]=row[1];
		data[2]=row[2];
		data[3]=row[3];
		data[4]=row[4];
		// 在列表视图控件中插入列表项，并设置列表子项文本
		m_L.InsertItem(i, data[1]);
	    m_L.SetItemText(i, 1,data[2] );
		m_L.SetItemText(i, 2,data[3] );
		m_L.SetItemText(i, 3,data[4] );
		i++;
	}	
	mysql_free_result(m_result); //关联的内存会释放
}
BOOL Customer::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CRect rect;
	m_L.GetClientRect(&rect);
	// 为列表视图控件添加全行选中和栅格风格
	m_L.SetExtendedStyle(m_L.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	// 为列表视图控件添加4列   
	m_L.InsertColumn(0,_T("姓名"),LVCFMT_CENTER,rect.Width()/8,0); //1 
	m_L.InsertColumn(1,_T("联系方式"),LVCFMT_CENTER,rect.Width()*3/8,1); //3
	m_L.InsertColumn(2,_T("联系地址"),LVCFMT_CENTER,rect.Width()*3/8,2); //3
	m_L.InsertColumn(3,_T("发货物流"),LVCFMT_CENTER,rect.Width()/8,3); //3
	show();
	m_cbj.Create(IDD_CustomerBJ,this);
	GetDlgItem(IDC_CBJ)->GetWindowRect(&m_kcac);  
    ScreenToClient(m_kcac);
	m_cbj.MoveWindow(m_kcac);
	m_cbj.ShowWindow(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void Customer::On32771()
{
	//MessageBox("编辑");
	m_L.ShowWindow(0);
	GetDlgItem(IDC_EDIT1)->ShowWindow(0);
	m_cbj.ShowWindow(1);
	edit=true;
	edit_flag=true;
}


void Customer::On32772()
{
	int j=atoi(customer_name);
	if(m_L.DeleteAllItems()!=0)
	{	   
			CString sql;
			sql.Format("DELETE FROM inventory.customer where C_name='%s'",customer_name);
			mysql_query(&m_sqlCon,sql);
	}
}
void Customer::OnLButtonDown(UINT nFlags, CPoint point)
{/*
	CString x;
	x.Format("%d ,%d",point.x,point.y); 
	MessageBox(x);*/
	if(point.x>=497&&point.x<=541&&point.y>=492&&point.y<=534)
	{
		m_L.ShowWindow(0);
		GetDlgItem(IDC_EDIT1)->ShowWindow(0);
		m_cbj.ShowWindow(1);
	}
	if(point.x>=1002&&point.x<=1047&&point.y>=0&&point.y<=45)
	{
		/*MessageBox("搜索");*/
		m_L.ShowWindow(1);
		GetDlgItem(IDC_EDIT1)->ShowWindow(1);
		show();
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


void Customer::OnMouseMove(UINT nFlags, CPoint point)
{
	if(point.x>=1002&&point.x<=1047&&point.y>=0&&point.y<=45)
		SetCursor(LoadCursor(NULL, IDC_HAND));
	if(point.x>=497&&point.x<=541&&point.y>=492&&point.y<=534)
		SetCursor(LoadCursor(NULL, IDC_HAND));
	CDialogEx::OnMouseMove(nFlags, point);
}
