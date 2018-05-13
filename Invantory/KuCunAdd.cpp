// KuCunAdd.cpp : 实现文件
//

#include "stdafx.h"
#include "Invantory.h"
#include "KuCunAdd.h"
#include "afxdialogex.h"
// KuCunAdd 对话框

IMPLEMENT_DYNAMIC(KuCunAdd, CDialogEx)

KuCunAdd::KuCunAdd(CWnd* pParent /*=NULL*/)
	: CDialogEx(KuCunAdd::IDD, pParent)
{

}

KuCunAdd::~KuCunAdd()
{
}

void KuCunAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCBUTTON2, close);
	DDX_Control(pDX, IDC_MFCBUTTON3, save);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_d1);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_d2);
	DDX_Control(pDX, IDC_DATETIMEPICKER3, m_d3);
	DDX_Control(pDX, IDC_DATETIMEPICKER4, m_d4);
	DDX_Control(pDX, IDC_DATETIMEPICKER5, m_d5);
	DDX_Control(pDX, IDC_DATETIMEPICKER6, m_d6);
	DDX_Control(pDX, IDC_DATETIMEPICKER7, m_d7);
	DDX_Control(pDX, IDC_DATETIMEPICKER8, m_d8);
	DDX_Control(pDX, IDC_DATETIMEPICKER9, m_d9);
	DDX_Control(pDX, IDC_DATETIMEPICKER10, m_d10);
}


BEGIN_MESSAGE_MAP(KuCunAdd, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_MFCBUTTON2, &KuCunAdd::OnClose)
	ON_BN_CLICKED(IDC_MFCBUTTON3, &KuCunAdd::OnSave)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// KuCunAdd 消息处理程序



void KuCunAdd::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CBitmap m_Back;
	m_Back.LoadBitmap(IDB_BITMAP18);
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


BOOL KuCunAdd::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	close.SetFaceColor(RGB(255, 201, 240));
	close.SetTextColor(RGB(11,74,125));
	close.SetTextHotColor(RGB(204,232,207));
	save.SetFaceColor(RGB(255, 201, 240));
	save.SetTextColor(RGB(11,74,125));
	save.SetTextHotColor(RGB(204,232,207));
	GetDlgItem(IDC_MFCBUTTON2)->SetFont(&m_editFont);// 设置新字体
	GetDlgItem(IDC_MFCBUTTON3)->SetFont(&m_editFont);// 设置新字体
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void KuCunAdd::OnClose()
{
	 if(MessageBox("确定关闭？","提示：" ,MB_ICONEXCLAMATION|MB_OKCANCEL)==IDOK)
	 {
		 CDialogEx::OnOK();
		 for(int i=1000;i<=1092;i++)
		 {
			 if(i<=1001||i>=1035)
			 GetDlgItem(i)->SetWindowTextA("");
		 }
	 }
}


void KuCunAdd::OnSave()
{
	datebase();
	CString time;
	CTime tm;
	CString xh;
	CString rk;
	CString ck;
	CString kc;
	CString bz;
	CString sql;
	int check[10]={};
	m_d1.GetTime(tm);
	time=tm.Format("%Y%m%d");
	GetDlgItem(IDC_EDIT1)->GetWindowTextA(xh);
	GetDlgItem(IDC_EDIT2)->GetWindowTextA(rk);
	GetDlgItem(IDC_EDIT3)->GetWindowTextA(ck);
	GetDlgItem(IDC_EDIT4)->GetWindowTextA(kc);
	GetDlgItem(IDC_EDIT5)->GetWindowTextA(bz);
	sql.Format("INSERT INTO inventory.inventory value(null, '%s', '%s', %s, %s, %s, '%s')", time,xh,rk,ck,kc,bz );	
	if(  mysql_query(&m_sqlCon, sql)==0 )
	{
		check[0]=1;
		sql.Format("INSERT INTO inventory.history value(null, '%s', '%s', %s, %s, %s, '%s')", time,xh,rk,ck,kc,bz );
		mysql_query(&m_sqlCon, sql);
	}
	m_d2.GetTime(tm);
	time=tm.Format("%Y%m%d");
	GetDlgItem(IDC_EDIT7)->GetWindowTextA(xh);
	GetDlgItem(IDC_EDIT8)->GetWindowTextA(rk);
	GetDlgItem(IDC_EDIT9)->GetWindowTextA(ck);
	GetDlgItem(IDC_EDIT10)->GetWindowTextA(kc);
	GetDlgItem(IDC_EDIT11)->GetWindowTextA(bz);
	sql.Format("INSERT INTO inventory.inventory value(null, '%s', '%s', %s, %s, %s, '%s')", time,xh,rk,ck,kc,bz );
	if(  mysql_query(&m_sqlCon, sql)==0 )
	{
		check[1]=1;
		sql.Format("INSERT INTO inventory.history value(null, '%s', '%s', %s, %s, %s, '%s')", time,xh,rk,ck,kc,bz );
		mysql_query(&m_sqlCon, sql);
	}

	m_d3.GetTime(tm);
	time=tm.Format("%Y%m%d");
	GetDlgItem(IDC_EDIT13)->GetWindowTextA(xh);
	GetDlgItem(IDC_EDIT14)->GetWindowTextA(rk);
	GetDlgItem(IDC_EDIT15)->GetWindowTextA(ck);
	GetDlgItem(IDC_EDIT16)->GetWindowTextA(kc);
	GetDlgItem(IDC_EDIT17)->GetWindowTextA(bz);
	sql.Format("INSERT INTO inventory.inventory value(null, '%s', '%s', %s, %s, %s, '%s')", time,xh,rk,ck,kc,bz );
	sql.Format("INSERT INTO inventory.history value(null, '%s', '%s', %s, %s, %s, '%s')", time,xh,rk,ck,kc,bz );	
	if(  mysql_query(&m_sqlCon, sql)==0 )
	{
		check[2]=1;
		sql.Format("INSERT INTO inventory.history value(null, '%s', '%s', %s, %s, %s, '%s')", time,xh,rk,ck,kc,bz );
		mysql_query(&m_sqlCon, sql);
	}

	m_d4.GetTime(tm);
	time=tm.Format("%Y%m%d");
	GetDlgItem(IDC_EDIT19)->GetWindowTextA(xh);
	GetDlgItem(IDC_EDIT20)->GetWindowTextA(rk);
	GetDlgItem(IDC_EDIT21)->GetWindowTextA(ck);
	GetDlgItem(IDC_EDIT22)->GetWindowTextA(kc);
	GetDlgItem(IDC_EDIT23)->GetWindowTextA(bz);
	sql.Format("INSERT INTO inventory.inventory value(null, '%s', '%s', %s, %s, %s, '%s')", time,xh,rk,ck,kc,bz );
	sql.Format("INSERT INTO inventory.history value(null, '%s', '%s', %s, %s, %s, '%s')", time,xh,rk,ck,kc,bz );	
	if(  mysql_query(&m_sqlCon, sql)==0 )
	{
		check[3]=1;
		sql.Format("INSERT INTO inventory.history value(null, '%s', '%s', %s, %s, %s, '%s')", time,xh,rk,ck,kc,bz );
		mysql_query(&m_sqlCon, sql);
	}

	m_d5.GetTime(tm);
	time=tm.Format("%Y%m%d");
	GetDlgItem(IDC_EDIT25)->GetWindowTextA(xh);
	GetDlgItem(IDC_EDIT26)->GetWindowTextA(rk);
	GetDlgItem(IDC_EDIT27)->GetWindowTextA(ck);
	GetDlgItem(IDC_EDIT28)->GetWindowTextA(kc);
	GetDlgItem(IDC_EDIT29)->GetWindowTextA(bz);
	sql.Format("INSERT INTO inventory.inventory value(null, '%s', '%s', %s, %s, %s, '%s')", time,xh,rk,ck,kc,bz );
	sql.Format("INSERT INTO inventory.history value(null, '%s', '%s', %s, %s, %s, '%s')", time,xh,rk,ck,kc,bz );	
	if(  mysql_query(&m_sqlCon, sql)==0 )
	{
		check[4]=1;
		sql.Format("INSERT INTO inventory.history value(null, '%s', '%s', %s, %s, %s, '%s')", time,xh,rk,ck,kc,bz );
		mysql_query(&m_sqlCon, sql);
	}

	m_d6.GetTime(tm);
	time=tm.Format("%Y%m%d");
	GetDlgItem(IDC_EDIT31)->GetWindowTextA(xh);
	GetDlgItem(IDC_EDIT32)->GetWindowTextA(rk);
	GetDlgItem(IDC_EDIT33)->GetWindowTextA(ck);
	GetDlgItem(IDC_EDIT34)->GetWindowTextA(kc);
	GetDlgItem(IDC_EDIT35)->GetWindowTextA(bz);
	sql.Format("INSERT INTO inventory.inventory value(null, '%s', '%s', %s, %s, %s, '%s')", time,xh,rk,ck,kc,bz );
	sql.Format("INSERT INTO inventory.history value(null, '%s', '%s', %s, %s, %s, '%s')", time,xh,rk,ck,kc,bz );	
	if(  mysql_query(&m_sqlCon, sql)==0 )
	{
		check[5]=1;
		sql.Format("INSERT INTO inventory.history value(null, '%s', '%s', %s, %s, %s, '%s')", time,xh,rk,ck,kc,bz );
		mysql_query(&m_sqlCon, sql);
	}
	m_d7.GetTime(tm);
	time=tm.Format("%Y%m%d");
	GetDlgItem(IDC_EDIT37)->GetWindowTextA(xh);
	GetDlgItem(IDC_EDIT38)->GetWindowTextA(rk);
	GetDlgItem(IDC_EDIT39)->GetWindowTextA(ck);
	GetDlgItem(IDC_EDIT40)->GetWindowTextA(kc);
	GetDlgItem(IDC_EDIT41)->GetWindowTextA(bz);
	sql.Format("INSERT INTO inventory.inventory value(null, '%s', '%s', %s, %s, %s, '%s')", time,xh,rk,ck,kc,bz );
	sql.Format("INSERT INTO inventory.history value(null, '%s', '%s', %s, %s, %s, '%s')", time,xh,rk,ck,kc,bz );	
	if(  mysql_query(&m_sqlCon, sql)==0 )
	{
		check[6]=1;
		sql.Format("INSERT INTO inventory.history value(null, '%s', '%s', %s, %s, %s, '%s')", time,xh,rk,ck,kc,bz );
		mysql_query(&m_sqlCon, sql);
	}

	m_d8.GetTime(tm);
	time=tm.Format("%Y%m%d");
	GetDlgItem(IDC_EDIT43)->GetWindowTextA(xh);
	GetDlgItem(IDC_EDIT44)->GetWindowTextA(rk);
	GetDlgItem(IDC_EDIT45)->GetWindowTextA(ck);
	GetDlgItem(IDC_EDIT46)->GetWindowTextA(kc);
	GetDlgItem(IDC_EDIT47)->GetWindowTextA(bz);
	sql.Format("INSERT INTO inventory.inventory value(null, '%s', '%s', %s, %s, %s, '%s')", time,xh,rk,ck,kc,bz );
	sql.Format("INSERT INTO inventory.history value(null, '%s', '%s', %s, %s, %s, '%s')", time,xh,rk,ck,kc,bz );		
	if(  mysql_query(&m_sqlCon, sql)==0 )
	{
		check[7]=1;
		sql.Format("INSERT INTO inventory.history value(null, '%s', '%s', %s, %s, %s, '%s')", time,xh,rk,ck,kc,bz );
		mysql_query(&m_sqlCon, sql);
	}

	m_d9.GetTime(tm);
	time=tm.Format("%Y%m%d");
	GetDlgItem(IDC_EDIT49)->GetWindowTextA(xh);
	GetDlgItem(IDC_EDIT50)->GetWindowTextA(rk);
	GetDlgItem(IDC_EDIT51)->GetWindowTextA(ck);
	GetDlgItem(IDC_EDIT52)->GetWindowTextA(kc);
	GetDlgItem(IDC_EDIT53)->GetWindowTextA(bz);
	sql.Format("INSERT INTO inventory.inventory value(null, '%s', '%s', %s, %s, %s, '%s')", time,xh,rk,ck,kc,bz );
	sql.Format("INSERT INTO inventory.history value(null, '%s', '%s', %s, %s, %s, '%s')", time,xh,rk,ck,kc,bz );		
	if(  mysql_query(&m_sqlCon, sql)==0 )
	{
		check[8]=1;
		sql.Format("INSERT INTO inventory.history value(null, '%s', '%s', %s, %s, %s, '%s')", time,xh,rk,ck,kc,bz );
		mysql_query(&m_sqlCon, sql);
	}
	m_d10.GetTime(tm);
	time=tm.Format("%Y%m%d");
	GetDlgItem(IDC_EDIT55)->GetWindowTextA(xh);
	GetDlgItem(IDC_EDIT56)->GetWindowTextA(rk);
	GetDlgItem(IDC_EDIT57)->GetWindowTextA(ck);
	GetDlgItem(IDC_EDIT58)->GetWindowTextA(kc);
	GetDlgItem(IDC_EDIT59)->GetWindowTextA(bz);
	sql.Format("INSERT INTO inventory.inventory value(null, '%s', '%s', %s, %s, %s, '%s')", time,xh,rk,ck,kc,bz );
	sql.Format("INSERT INTO inventory.history value(null, '%s', '%s', %s, %s, %s, '%s')", time,xh,rk,ck,kc,bz );		
	if(  mysql_query(&m_sqlCon, sql)==0 )
	{
		check[9]=1;
		sql.Format("INSERT INTO inventory.history value(null, '%s', '%s', %s, %s, %s, '%s')", time,xh,rk,ck,kc,bz );
		mysql_query(&m_sqlCon, sql);
	}
	CString text=0;
	bool s=false;
	for(int i=0;i<10;i++)
	{   
		if(i!=0)  
		{       
			GetDlgItem(1039+(i-1)*6)->GetWindowTextA(xh);
			if(!xh.IsEmpty())
				s=true;
		}
		else 
		{
			GetDlgItem(IDC_EDIT1)->GetWindowTextA(xh);
			if(!xh.IsEmpty())
				s=true;
		}
		if( !check[i] && !xh.IsEmpty() )
		{
			GetDlgItem(1038+i*6)->SetWindowTextA("出错");
			GetDlgItem(1038+i*6)->GetWindowTextA(text);
		}
	}
	if(text.IsEmpty())
	{
		if(s)
		{
			if(MessageBox("保存成功，是否继续添加？","提示：" ,MB_ICONEXCLAMATION|MB_OKCANCEL)==IDOK)
			{
				for(int i=1000;i<=1092;i++)
				{
					if(i<=1001||i>=1035)
					GetDlgItem(i)->SetWindowTextA("");
				}
			}
		}
		else
			MessageBox("莫要搞笑，您还没有输入任何数据，系统难以帮您存入数据。","提示：" );
		
	}
	else 
	{
		if(MessageBox("某行保存出错，是否返回修改？","提示：" ,MB_ICONEXCLAMATION|MB_OKCANCEL)==IDCANCEL)
		{
			for(int i=1000;i<=1092;i++)
			{
				if(i<=1001||i>=1035)
					GetDlgItem(i)->SetWindowTextA("");
			}
		}
		else
		{
			
			for(int i=0;i<10;i++)
			{
				GetDlgItem(1038+i*6)->GetWindowTextA(text);
				if(text.IsEmpty()|| check[i])
				{
					if(i==0)
					{
						GetDlgItem(1000)->SetWindowTextA("");
						GetDlgItem(1001)->SetWindowTextA("");
						GetDlgItem(1035)->SetWindowTextA("");
						GetDlgItem(1036)->SetWindowTextA("");
						GetDlgItem(1037)->SetWindowTextA("");
						GetDlgItem(1038)->SetWindowTextA("");
					}
					else
					{
						GetDlgItem(1039+(i-1)*6)->SetWindowTextA("");
						GetDlgItem(1040+(i-1)*6)->SetWindowTextA("");
						GetDlgItem(1041+(i-1)*6)->SetWindowTextA("");
						GetDlgItem(1042+(i-1)*6)->SetWindowTextA("");
						GetDlgItem(1043+(i-1)*6)->SetWindowTextA("");
						GetDlgItem(1044+(i-1)*6)->SetWindowTextA("");
					}
				}
			}
		}
	}
	
}


void KuCunAdd::OnMouseMove(UINT nFlags, CPoint point)
{
	if(point.x>=651&&point.x<=798&&point.y>=7&&point.y<=32)
		SetCursor(LoadCursor(NULL, IDC_HAND));
	CDialogEx::OnMouseMove(nFlags, point);
}


void KuCunAdd::OnLButtonDown(UINT nFlags, CPoint point)
{
	/*CString x;
	x.Format("%d ,%d",point.x,point.y);651 7 798 32
	MessageBox(x);*/
	if(point.x>=651&&point.x<=798&&point.y>=7&&point.y<=32)
	{
		CString rk,ck,kc;
		double Rk,Ck,Kc;
		GetDlgItem(IDC_EDIT2)->GetWindowTextA(rk);
		GetDlgItem(IDC_EDIT3)->GetWindowTextA(ck);
		if(!rk.IsEmpty()&&!ck.IsEmpty())
		{
			Rk=atof(rk);
			Ck=atof(ck);
			Kc=Rk-Ck;
			kc.Format("%.1lf",Kc);
			GetDlgItem(IDC_EDIT4)->SetWindowTextA(kc);
		}
		for(int i=1;i<10;i++)
		{
			GetDlgItem(1040+(i-1)*6)->GetWindowTextA(rk);
			GetDlgItem(1041+(i-1)*6)->GetWindowTextA(ck);
			if(!rk.IsEmpty()&&!ck.IsEmpty())
			{
				Rk=atof(rk);
				Ck=atof(ck);
				Kc=Rk-Ck;
				kc.Format("%.1lf",Kc);
				GetDlgItem(1042+(i-1)*6)->SetWindowTextA(kc);
			}
		}
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}
