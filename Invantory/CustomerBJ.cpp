// CustomerBJ.cpp : 实现文件
//

#include "stdafx.h"
#include "Invantory.h"
#include "CustomerBJ.h"
#include "afxdialogex.h"


// CustomerBJ 对话框

IMPLEMENT_DYNAMIC(CustomerBJ, CDialogEx)

CustomerBJ::CustomerBJ(CWnd* pParent /*=NULL*/)
	: CDialogEx(CustomerBJ::IDD, pParent)
{

}

CustomerBJ::~CustomerBJ()
{
}

void CustomerBJ::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CustomerBJ, CDialogEx)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CustomerBJ 消息处理程序


void CustomerBJ::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CBitmap m_Back;
	m_Back.LoadBitmap(IDB_BITMAP30);
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


void CustomerBJ::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	/*CString x;
	x.Format("%d ,%d",point.x,point.y);     
	MessageBox(x);*/
	if(point.x>=45&&point.x<=109&&point.y>=494&&point.y<=566)
	{
		CDialogEx::OnOK();
	}
	if(point.x>=958&&point.x<=1000&&point.y>=493&&point.y<=537)
	{
		CString xm,dh,dz,wl;
		GetDlgItem(IDC_EDIT1)->GetWindowTextA(xm);
		GetDlgItem(IDC_EDIT2)->GetWindowTextA(dh);
		GetDlgItem(IDC_EDIT3)->GetWindowTextA(dz);
		GetDlgItem(IDC_EDIT4)->GetWindowTextA(wl);
		CString sql;
		if(!xm.IsEmpty())
			sql.Format("INSERT INTO inventory.customer value(null, '%s', '%s', '%s', '%s')", xm,dh,dz,wl );	
		if(edit)
			sql.Format("update inventory.customer set C_name='%s',C_phone='%s',C_address='%s',C_wuliu='%s' where C_name='%s'", xm,dh,dz,wl, customer_name);
		if(  mysql_query(&m_sqlCon, sql)==0 )
		{

			MessageBox("保存成功","提示");
			edit=false;
			GetDlgItem(IDC_EDIT1)->SetWindowTextA("");
			GetDlgItem(IDC_EDIT2)->SetWindowTextA("");
			GetDlgItem(IDC_EDIT3)->SetWindowTextA("");
			GetDlgItem(IDC_EDIT4)->SetWindowTextA("");
			CDialogEx::OnOK();
		}
		else{
			MessageBox("保存失败，名字重复","提示");
		}
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CustomerBJ::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(point.x>=45&&point.x<=109&&point.y>=494&&point.y<=566)
		SetCursor(LoadCursor(NULL, IDC_HAND));
	if(point.x>=958&&point.x<=1000&&point.y>=493&&point.y<=537)
		SetCursor(LoadCursor(NULL, IDC_HAND));
	CDialogEx::OnMouseMove(nFlags, point);
}

void CustomerBJ::show()
{
	CString data[5],sql;
		sql.Format("SELECT * FROM inventory.customer where C_name='%s';",customer_name);
		//执行查询
		MYSQL_RES *m_result;
		mysql_query(&m_sqlCon,sql);
		m_result=mysql_use_result(&m_sqlCon);
		MYSQL_ROW row;
		if((row=mysql_fetch_row(m_result)))
		{
			//获取数据
			data[1]=row[1];
			data[2]=row[2];
			data[3]=row[3];
			data[4]=row[4];
			// 在列表视图控件中插入列表项，并设置列表子项文本
			GetDlgItem(IDC_EDIT1)->SetWindowTextA(data[1]);
			GetDlgItem(IDC_EDIT2)->SetWindowTextA(data[2]);
			GetDlgItem(IDC_EDIT3)->SetWindowTextA(data[3]);
			GetDlgItem(IDC_EDIT4)->SetWindowTextA(data[4]);
		}	
		mysql_free_result(m_result); //关联的内存会释放
}
BOOL CustomerBJ::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	if(edit)
		show();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


BOOL CustomerBJ::PreTranslateMessage(MSG* pMsg)
{
	if(edit&&edit_flag)
	{
		show();
		edit_flag=false;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
