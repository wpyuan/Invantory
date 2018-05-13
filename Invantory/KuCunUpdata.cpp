// KuCunUpdata.cpp : 实现文件
//

#include "stdafx.h"
#include "Invantory.h"
#include "KuCunUpdata.h"
#include "afxdialogex.h"


// KuCunUpdata 对话框

IMPLEMENT_DYNAMIC(KuCunUpdata, CDialogEx)

KuCunUpdata::KuCunUpdata(CWnd* pParent /*=NULL*/)
	: CDialogEx(KuCunUpdata::IDD, pParent)
{

}

KuCunUpdata::~KuCunUpdata()
{
}

void KuCunUpdata::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCBUTTON4, m_1);
	DDX_Control(pDX, IDC_MFCBUTTON3, m_2);
}


BEGIN_MESSAGE_MAP(KuCunUpdata, CDialogEx)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_MFCBUTTON4, &KuCunUpdata::OnSearch)
	ON_BN_CLICKED(IDC_MFCBUTTON3, &KuCunUpdata::OnUpdate)
END_MESSAGE_MAP()


// KuCunUpdata 消息处理程序


void KuCunUpdata::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CBitmap m_Back;
	m_Back.LoadBitmap(IDB_BITMAP20);
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


void KuCunUpdata::OnLButtonDown(UINT nFlags, CPoint point)
{
	//CString x;
	//x.Format("%d,%d",point.x,point.y);//1017 2  1045 32
	//MessageBox(x);
	if(point.x>=1017&&point.x<=1045&&point.y>=2&&point.y<=32)
	{
		
		if(MessageBox("确定关闭？","提示：" ,MB_ICONEXCLAMATION|MB_OKCANCEL)==IDOK)
		{
			 CDialogEx::OnOK();
			 GetDlgItem(IDC_EDIT19)->SetWindowTextA("");
			 GetDlgItem(IDC_EDIT1)->SetWindowTextA("");
			 GetDlgItem(IDC_EDIT13)->SetWindowTextA("");
			 GetDlgItem(IDC_EDIT14)->SetWindowTextA("");
			 GetDlgItem(IDC_EDIT15)->SetWindowTextA("");
			 GetDlgItem(IDC_EDIT16)->SetWindowTextA("");
			 GetDlgItem(IDC_EDIT17)->SetWindowTextA("");
		}
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


BOOL KuCunUpdata::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_1.SetFaceColor(RGB(255, 201, 240));
	m_1.SetTextColor(RGB(11,74,125));
	m_1.SetTextHotColor(RGB(204,232,207));
	m_2.SetFaceColor(RGB(255, 201, 240));
	m_2.SetTextColor(RGB(11,74,125));
	m_2.SetTextHotColor(RGB(204,232,207));
	GetDlgItem(IDC_MFCBUTTON3)->SetFont(&m_editFont);// 设置新字体
	GetDlgItem(IDC_MFCBUTTON4)->SetFont(&m_editFont);// 设置新字体

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void KuCunUpdata::OnSearch()
{
	datebase();
	CString xh,kc,bz,sql;
	GetDlgItem(IDC_EDIT1)->GetWindowTextA(xh);
	sql.Format("SELECT * FROM inventory.inventory where I_type='%s';",xh);
	//执行查询
	MYSQL_RES *m_result;
	mysql_query(&m_sqlCon,sql);
	m_result=mysql_use_result(&m_sqlCon);
	CString data[7];
	MYSQL_ROW row;
	if((row=mysql_fetch_row(m_result)))
	{
		//获取数据
		data[1]=row[1];
		data[2]=row[2];
		data[3]=row[3];
		data[4]=row[4];
		data[5]=row[5];
		data[6]=row[6];
		GetDlgItem(IDC_EDIT19)->SetWindowTextA(data[1]);
		GetDlgItem(IDC_EDIT13)->SetWindowTextA(xh);
		GetDlgItem(IDC_EDIT14)->SetWindowTextA(data[3]);
		GetDlgItem(IDC_EDIT15)->SetWindowTextA(data[4]);
		GetDlgItem(IDC_EDIT16)->SetWindowTextA(data[5]);
		GetDlgItem(IDC_EDIT17)->SetWindowTextA(data[6]);
	}
	else
		MessageBox("经查询，无此型号库存记录。请您复查型号是否正确输入！","提示",MB_ICONEXCLAMATION|MB_OK);
	mysql_free_result(m_result); //关联的内存会释放
}


void KuCunUpdata::OnUpdate()
{
	CString rq,xh,rk,ck,kc,bz,XH;
	GetDlgItem(IDC_EDIT1)->GetWindowTextA(XH);
	GetDlgItem(IDC_EDIT19)->GetWindowTextA(rq);
	GetDlgItem(IDC_EDIT13)->GetWindowTextA(xh);
	GetDlgItem(IDC_EDIT14)->GetWindowTextA(rk);
	GetDlgItem(IDC_EDIT15)->GetWindowTextA(ck);
	GetDlgItem(IDC_EDIT16)->GetWindowTextA(kc);
	GetDlgItem(IDC_EDIT17)->GetWindowTextA(bz);
	int flag=0;
	CString sql;
	sql.Format("update inventory.inventory set I_date='%s' where I_type='%s'",rq,XH);
	if(mysql_query(&m_sqlCon,sql)==0)
		flag++;
    sql.Format("update inventory.inventory set I_type='%s' where I_type='%s'",xh,XH);
	if(mysql_query(&m_sqlCon,sql)==0)
		flag++;
	sql.Format("update inventory.inventory set I_rk=%s where I_type='%s'",rk,XH);
	if(mysql_query(&m_sqlCon,sql)==0)
		flag++;
	sql.Format("update inventory.inventory set I_ck=%s where I_type='%s'",ck,XH);
	if(mysql_query(&m_sqlCon,sql)==0)
		flag++;
	sql.Format("update inventory.inventory set I_kc=%s where I_type='%s'",kc,XH);
	if(mysql_query(&m_sqlCon,sql)==0)
		flag++;
	sql.Format("update inventory.inventory set I_remark='%s' where I_type='%s'",bz,XH);
	if(mysql_query(&m_sqlCon,sql)==0)
		flag++;
	if(flag!=6)
	{}
		//MessageBox("修改失败","提示",MB_ICONEXCLAMATION); 
	else
		MessageBox("修改成功","提示",MB_ICONEXCLAMATION); 
}
