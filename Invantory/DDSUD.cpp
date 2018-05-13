// DDSUD.cpp : 实现文件
//

#include "stdafx.h"
#include "Invantory.h"
#include "DDSUD.h"
#include "afxdialogex.h"


// DDSUD 对话框

IMPLEMENT_DYNAMIC(DDSUD, CDialogEx)

DDSUD::DDSUD(CWnd* pParent /*=NULL*/)
	: CDialogEx(DDSUD::IDD, pParent)
{

}

DDSUD::~DDSUD()
{
}

void DDSUD::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_L);
}


BEGIN_MESSAGE_MAP(DDSUD, CDialogEx)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_MFCBUTTON1, &DDSUD::OnSearch1)
	ON_BN_CLICKED(IDC_MFCBUTTON2, &DDSUD::OnSearch2)
	ON_BN_CLICKED(IDC_MFCBUTTON3, &DDSUD::OnDelete_Update)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// DDSUD 消息处理程序


void DDSUD::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CBitmap m_Back;
	m_Back.LoadBitmap(IDB_BITMAP23);
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



void DDSUD::OnLButtonDown(UINT nFlags, CPoint point)
{
	//CString x;
	//x.Format("%d ,%d",point.x,point.y);//650 435 799 484
	//MessageBox(x);
	if(point.x>=1000&&point.y<=45)
		CDialogEx::OnOK();
	if(point.x>=650&&point.x<=799&&point.y>=435&&point.y<=484)
	{
		CString sl,dj,je;
		double SL,DJ,JE;
		GetDlgItem(IDC_EDIT7)->GetWindowTextA(sl);
		GetDlgItem(IDC_EDIT8)->GetWindowTextA(dj);
		if(!sl.IsEmpty()&&!dj.IsEmpty())
		{
			SL=atof(sl);
			DJ=atof(dj);
			JE=SL*DJ;
			je.Format("%.1lf",JE);
			GetDlgItem(IDC_EDIT9)->SetWindowTextA(je);
		}
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


BOOL DDSUD::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  在此添加额外的初始化
	CRect rect;
	m_L.GetClientRect(&rect);
	// 为列表视图控件添加全行选中和栅格风格
	m_L.SetExtendedStyle(m_L.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	// 为列表视图控件添加8列 
	if(password=="88785268")
	{
		GetDlgItem(IDC_profitText)->ShowWindow(0);
		GetDlgItem(IDC_EDIT11)->ShowWindow(0);
		m_L.InsertColumn(0,_T("编号"),LVCFMT_CENTER,rect.Width()/8,0); //1   
		m_L.InsertColumn(1,_T("日期"),LVCFMT_CENTER,rect.Width()/8,1); //1 
		m_L.InsertColumn(2,_T("型号"),LVCFMT_CENTER,rect.Width()/8,2);//2
		m_L.InsertColumn(3,_T("客户"),LVCFMT_CENTER,rect.Width()/8,3); //3
		m_L.InsertColumn(4,_T("数量"),LVCFMT_CENTER,rect.Width()/8,4); //1 
		m_L.InsertColumn(5,_T("单价"),LVCFMT_CENTER,rect.Width()/8,5);//2
		m_L.InsertColumn(6,_T("金额"),LVCFMT_CENTER,rect.Width()/8,6); //3
		m_L.InsertColumn(7,_T("备注"),LVCFMT_CENTER,rect.Width()/8,7); //3
	}
	if(password=="6335598")
	{
		m_L.InsertColumn(0,_T("编号"),LVCFMT_CENTER,rect.Width()/9,0); //1   
		m_L.InsertColumn(1,_T("日期"),LVCFMT_CENTER,rect.Width()/9,1); //1 
		m_L.InsertColumn(2,_T("型号"),LVCFMT_CENTER,rect.Width()/9,2);//2
		m_L.InsertColumn(3,_T("客户"),LVCFMT_CENTER,rect.Width()/9,3); //3
		m_L.InsertColumn(4,_T("数量"),LVCFMT_CENTER,rect.Width()/9,4); //1 
		m_L.InsertColumn(5,_T("单价"),LVCFMT_CENTER,rect.Width()/9,5);//2
		m_L.InsertColumn(6,_T("金额"),LVCFMT_CENTER,rect.Width()/9,6); //3
		m_L.InsertColumn(7,_T("备注"),LVCFMT_CENTER,rect.Width()/9,7); //3
		m_L.InsertColumn(8,_T("利润"),LVCFMT_CENTER,rect.Width()/9,8); //3
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void DDSUD::OnSearch1()
{
	m_L.DeleteAllItems();
	CString text;
	GetDlgItem(IDC_COMBO1)->GetWindowTextA(text);
	CString lx,rq,xh,kh,sl,dj,je,bz,sql;
	GetDlgItem(IDC_EDIT1)->GetWindowTextA(lx);
	sql.Format("SELECT * FROM inventory.goods where G_type='%s';",lx);
	if(text=="客户")
		sql.Format("SELECT * FROM inventory.goods where G_customer='%s';",lx);
	//执行查询
	MYSQL_RES *m_result;
	mysql_query(&m_sqlCon,sql);
	m_result=mysql_use_result(&m_sqlCon);
	CString data[9];
	int i=0;
	MYSQL_ROW row;
	bool q=false;
	while((row=mysql_fetch_row(m_result)))
	{
		q=true;
		//获取数据
		data[0]=row[0];
		data[1]=row[1];
		data[2]=row[2];
		data[3]=row[3];
		data[4]=row[4];
		data[5]=row[5];
		data[6]=row[6];
		data[7]=row[7];
		if(password=="6335598")
			data[8]=row[8];
		// 在列表视图控件中插入列表项，并设置列表子项文本
		m_L.InsertItem(i, data[0]);
	    m_L.SetItemText(i, 1,data[1] );
		m_L.SetItemText(i, 2,data[2] );
		m_L.SetItemText(i, 3,data[3] );
		m_L.SetItemText(i, 4,data[4] );
		m_L.SetItemText(i, 5,data[5] );
		m_L.SetItemText(i, 6,data[6] );
		m_L.SetItemText(i, 7,data[7] );
		if(password=="6335598")
			m_L.SetItemText(i, 8,data[8] );
		i++;
	}
	if(!q)
		MessageBox("经查询，无此型号订单记录。请您复查型号是否正确输入！","提示",MB_ICONEXCLAMATION|MB_OK);
	mysql_free_result(m_result); //关联的内存会释放
}


void DDSUD::OnSearch2()
{
	GetDlgItem(IDC_EDIT4)->SetWindowTextA("");
	GetDlgItem(IDC_EDIT5)->SetWindowTextA("");
	GetDlgItem(IDC_EDIT6)->SetWindowTextA("");
	GetDlgItem(IDC_EDIT7)->SetWindowTextA("");
	GetDlgItem(IDC_EDIT8)->SetWindowTextA("");
	GetDlgItem(IDC_EDIT9)->SetWindowTextA("");
	GetDlgItem(IDC_EDIT10)->SetWindowTextA("");
	if(password=="6335598")
		GetDlgItem(IDC_EDIT11)->SetWindowTextA("");
	CString bh,sql;
	GetDlgItem(IDC_EDIT3)->GetWindowTextA(bh);
	sql.Format("SELECT * FROM inventory.goods where G_id=%s;",bh);
	//执行查询
	MYSQL_RES *m_result;
	mysql_query(&m_sqlCon,sql);
	m_result=mysql_use_result(&m_sqlCon);
	CString data[9];
	MYSQL_ROW row;
	if(!bh.IsEmpty())
	{
		if((row=mysql_fetch_row(m_result)))
		{
			//获取数据
			data[1]=row[1];
			data[2]=row[2];
			data[3]=row[3];
			data[4]=row[4];
			data[5]=row[5];
			data[6]=row[6];
			data[7]=row[7];
			if(password=="6335598")
				data[8]=row[8];
			GetDlgItem(IDC_EDIT4)->SetWindowTextA(data[1]);
			GetDlgItem(IDC_EDIT5)->SetWindowTextA(data[2]);
			GetDlgItem(IDC_EDIT6)->SetWindowTextA(data[3]);
			GetDlgItem(IDC_EDIT7)->SetWindowTextA(data[4]);
			GetDlgItem(IDC_EDIT8)->SetWindowTextA(data[5]);
			GetDlgItem(IDC_EDIT9)->SetWindowTextA(data[6]);
			GetDlgItem(IDC_EDIT10)->SetWindowTextA(data[7]);
			if(password=="6335598")
				GetDlgItem(IDC_EDIT11)->SetWindowTextA(data[8]);
		}
		else
			MessageBox("经查询，无此编号订单记录。请您复查编号是否正确输入！","提示",MB_ICONEXCLAMATION|MB_OK);
	}
	else
		MessageBox("莫要搞笑，您还没输入编号，系统是无法向您提供结果的。请您复查编号是否输入！","提示",MB_ICONEXCLAMATION|MB_OK);
	mysql_free_result(m_result); //关联的内存会释放
}


void DDSUD::OnDelete_Update()
{
	datebase();
	CString text;
	GetDlgItem(IDC_COMBO2)->GetWindowTextA(text);
	CString rq,xh,kh,sl,dj,je,bz,bh,lr;
	GetDlgItem(IDC_EDIT3)->GetWindowTextA(bh);
	GetDlgItem(IDC_EDIT4)->GetWindowTextA(rq);
	GetDlgItem(IDC_EDIT5)->GetWindowTextA(xh);
	GetDlgItem(IDC_EDIT6)->GetWindowTextA(kh);
	GetDlgItem(IDC_EDIT7)->GetWindowTextA(sl);
	GetDlgItem(IDC_EDIT8)->GetWindowTextA(dj);
	GetDlgItem(IDC_EDIT9)->GetWindowTextA(je);
	GetDlgItem(IDC_EDIT10)->GetWindowTextA(bz);
	GetDlgItem(IDC_EDIT11)->GetWindowTextA(lr);
	CString sql;
	if(text=="修改")
	{
		int flag=0;
		sql.Format("update inventory.goods set G_time='%s' where G_id=%s",rq,bh);
		MessageBox("修改中.....");
		if(mysql_query(&m_sqlCon,sql)==0)
			flag++;
		sql.Format("update inventory.goods set G_type='%s' where G_id=%s",xh,bh);
		if(mysql_query(&m_sqlCon,sql)==0)
			flag++;
		sql.Format("update inventory.goods set G_customer='%s' where G_id=%s",kh,bh);
		if(mysql_query(&m_sqlCon,sql)==0)
			flag++;
		sql.Format("update inventory.goods set G_number=%s where G_id=%s",sl,bh);
		if(mysql_query(&m_sqlCon,sql)==0)
			flag++;
		sql.Format("update inventory.goods set G_price=%s where G_id=%s",dj,bh);
		if(mysql_query(&m_sqlCon,sql)==0)
			flag++;
		sql.Format("update inventory.goods set G_money=%s where G_id=%s",je,bh);
		if(mysql_query(&m_sqlCon,sql)==0)
			flag++;
		sql.Format("update inventory.goods set G_remark='%s' where G_id=%s",bz,bh);
		if(mysql_query(&m_sqlCon,sql)==0)
			flag++;
		if(lr.IsEmpty())
			lr="null";
		sql.Format("update inventory.goods set G_profit=%s where G_id=%s",lr,bh);
		if(mysql_query(&m_sqlCon,sql)==0)
			flag++;
		if(flag!=8){}
			//MessageBox("修改失败","提示",MB_ICONEXCLAMATION); 
		else
			MessageBox("修改成功","提示",MB_ICONEXCLAMATION); 
	}
	if(text=="删除")
	{
		sql.Format("DELETE FROM inventory.goods where G_id=%s",bh);
		if(mysql_query(&m_sqlCon,sql)==0)
			MessageBox("删除成功","提示",MB_ICONEXCLAMATION);
	}
}


void DDSUD::OnMouseMove(UINT nFlags, CPoint point)
{
	if(point.x>=650&&point.x<=799&&point.y>=435&&point.y<=484)
		SetCursor(LoadCursor(NULL, IDC_HAND));

	CDialogEx::OnMouseMove(nFlags, point);
}
