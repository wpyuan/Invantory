// Profit.cpp : 实现文件
//

#include "stdafx.h"
#include "Invantory.h"
#include "Profit.h"
#include "afxdialogex.h"


// Profit 对话框

IMPLEMENT_DYNAMIC(Profit, CDialogEx)

Profit::Profit(CWnd* pParent /*=NULL*/)
	: CDialogEx(Profit::IDD, pParent)
{

}

Profit::~Profit()
{
}

void Profit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCBUTTON1, m_1);
	DDX_Control(pDX, IDC_MFCBUTTON2, m_2);
	DDX_Control(pDX, IDC_MFCBUTTON3, m_3);
	DDX_Control(pDX, IDC_MFCBUTTON4, m_4);
}


BEGIN_MESSAGE_MAP(Profit, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_MFCBUTTON1, &Profit::OnClose)
	ON_BN_CLICKED(IDC_MFCBUTTON2, &Profit::OnUpPage)
	ON_BN_CLICKED(IDC_MFCBUTTON3, &Profit::OnDownPage)
	ON_BN_CLICKED(IDC_MFCBUTTON4, &Profit::OnSave)
END_MESSAGE_MAP()


// Profit 消息处理程序


void Profit::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CBitmap m_Back;
	m_Back.LoadBitmap(IDB_BITMAP28);
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
void Profit::show()
{
	sanwInitDialog();
	CString rq,xh,kh,sl,dj,je,bz;
	CString sql;
	sql.Format("SELECT * FROM inventory.goods where G_profit is null;");
	//执行查询
	MYSQL_RES *m_result;
	mysql_query(&m_sqlCon,sql);
	m_result=mysql_use_result(&m_sqlCon);
	int i=0;
	MYSQL_ROW row;
	while((row=mysql_fetch_row(m_result)))
	{
		//获取数据
		data[pageMax][i][0]=row[0];
		data[pageMax][i][1]=row[1];
		data[pageMax][i][2]=row[2];
		data[pageMax][i][3]=row[3];
		data[pageMax][i][4]=row[4];
		data[pageMax][i][5]=row[5];
		data[pageMax][i][6]=row[6];
		data[pageMax][i][7]=row[7];
		i++;
		if(i==10)
		{
			i=0;
			pageMax++;
		}
		if(pageMax==10) break;
	}
	for(i=0;i<10;i++)
	{
		GetDlgItem(1098+i)->SetWindowTextA("");
		if(i==0)
		{
			GetDlgItem(IDC_EDIT72)->SetWindowTextA(data[0][i][1]);
			GetDlgItem(IDC_EDIT1)->SetWindowTextA(data[0][i][2]);
			GetDlgItem(IDC_EDIT61)->SetWindowTextA(data[0][i][3]);
			GetDlgItem(IDC_EDIT3)->SetWindowTextA(data[0][i][4]);
			GetDlgItem(IDC_EDIT6)->SetWindowTextA(data[0][i][5]);
			GetDlgItem(IDC_EDIT4)->SetWindowTextA(data[0][i][6]);
			GetDlgItem(IDC_EDIT5)->SetWindowTextA(data[0][i][7]);
		}
		else
		{
			GetDlgItem(1108+i)->SetWindowTextA(data[0][i][1]);
			GetDlgItem(1039+(i-1)*6)->SetWindowTextA(data[0][i][2]);
			GetDlgItem(1040+(i-1)*6)->SetWindowTextA(data[0][i][3]);
			GetDlgItem(1041+(i-1)*6)->SetWindowTextA(data[0][i][4]);
			GetDlgItem(1044+(i-1)*6)->SetWindowTextA(data[0][i][5]);
			GetDlgItem(1042+(i-1)*6)->SetWindowTextA(data[0][i][6]);
			GetDlgItem(1043+(i-1)*6)->SetWindowTextA(data[0][i][7]);
		}
	}
	mysql_free_result(m_result); //关联的内存会释放
}
void Profit::sanwInitDialog()
{
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			for(int k=0;k<10;k++)
			{
				data[i][j][k]="";
			}
		}
	}
	pageMax=0;
	page=0;
	GetDlgItem(IDC_Page)->SetWindowTextA("1");
}
BOOL Profit::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_1.SetFaceColor(RGB(113, 0, 0));
	m_1.SetTextColor(RGB(0,100,0));
	m_1.SetTextHotColor(RGB(255,255,255));
	m_2.SetFaceColor(RGB(233, 71, 41));
	m_2.SetTextColor(RGB(0,200,0));
	m_2.SetTextHotColor(RGB(255,255,255));
	m_3.SetFaceColor(RGB(233, 71, 41));
	m_3.SetTextColor(RGB(0,200,0));
	m_3.SetTextHotColor(RGB(255,255,255));
	m_4.SetFaceColor(RGB(113, 0, 0));
	m_4.SetTextColor(RGB(0,100,0));
	m_4.SetTextHotColor(RGB(255,255,255));
	GetDlgItem(IDC_MFCBUTTON1)->SetFont(&m_editFont);// 设置新字体
	GetDlgItem(IDC_MFCBUTTON2)->SetFont(&m_editFont);// 设置新字体
	GetDlgItem(IDC_MFCBUTTON3)->SetFont(&m_editFont);// 设置新字体
	GetDlgItem(IDC_MFCBUTTON4)->SetFont(&m_editFont);// 设置新字体
	page=0;pageMax=0;
	CString p;
	p.Format("%d",page+1);
	GetDlgItem(IDC_Page)->SetWindowTextA(p);
	sanwInitDialog();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void Profit::OnClose()
{
	sanwInitDialog();
	CDialogEx::OnOK();
}


void Profit::OnUpPage()
{
	if(page>0)
	{
		page--;
		CString p;
		p.Format("%d",page+1);
		GetDlgItem(IDC_Page)->SetWindowTextA(p);
		for(int i=0;i<10;i++)
		{
			GetDlgItem(1098+i)->SetWindowTextA("");
			if(i==0)
			{
				GetDlgItem(IDC_EDIT72)->SetWindowTextA(data[page][i][1]);
				GetDlgItem(IDC_EDIT1)->SetWindowTextA(data[page][i][2]);
				GetDlgItem(IDC_EDIT61)->SetWindowTextA(data[page][i][3]);
				GetDlgItem(IDC_EDIT3)->SetWindowTextA(data[page][i][4]);
				GetDlgItem(IDC_EDIT6)->SetWindowTextA(data[page][i][5]);
				GetDlgItem(IDC_EDIT4)->SetWindowTextA(data[page][i][6]);
				GetDlgItem(IDC_EDIT5)->SetWindowTextA(data[page][i][7]);
			}
			else
			{
				GetDlgItem(1108+i)->SetWindowTextA(data[page][i][1]);
				GetDlgItem(1039+(i-1)*6)->SetWindowTextA(data[page][i][2]);
				GetDlgItem(1040+(i-1)*6)->SetWindowTextA(data[page][i][3]);
				GetDlgItem(1041+(i-1)*6)->SetWindowTextA(data[page][i][4]);
				GetDlgItem(1044+(i-1)*6)->SetWindowTextA(data[page][i][5]);
				GetDlgItem(1042+(i-1)*6)->SetWindowTextA(data[page][i][6]);
				GetDlgItem(1043+(i-1)*6)->SetWindowTextA(data[page][i][7]);
			}
		}
	}
}


void Profit::OnDownPage()
{
	if(page<pageMax&&page!=9)
	{
		page++;
		CString p;
		p.Format("%d",page+1);
		GetDlgItem(IDC_Page)->SetWindowTextA(p);
		for(int i=0;i<10;i++)
		{
			GetDlgItem(1098+i)->SetWindowTextA("");
			if(i==0)
			{
				GetDlgItem(IDC_EDIT72)->SetWindowTextA(data[page][i][1]);
				GetDlgItem(IDC_EDIT1)->SetWindowTextA(data[page][i][2]);
				GetDlgItem(IDC_EDIT61)->SetWindowTextA(data[page][i][3]);
				GetDlgItem(IDC_EDIT3)->SetWindowTextA(data[page][i][4]);
				GetDlgItem(IDC_EDIT6)->SetWindowTextA(data[page][i][5]);
				GetDlgItem(IDC_EDIT4)->SetWindowTextA(data[page][i][6]);
				GetDlgItem(IDC_EDIT5)->SetWindowTextA(data[page][i][7]);
			}
			else
			{
				GetDlgItem(1108+i)->SetWindowTextA(data[page][i][1]);
				GetDlgItem(1039+(i-1)*6)->SetWindowTextA(data[page][i][2]);
				GetDlgItem(1040+(i-1)*6)->SetWindowTextA(data[page][i][3]);
				GetDlgItem(1041+(i-1)*6)->SetWindowTextA(data[page][i][4]);
				GetDlgItem(1044+(i-1)*6)->SetWindowTextA(data[page][i][5]);
				GetDlgItem(1042+(i-1)*6)->SetWindowTextA(data[page][i][6]);
				GetDlgItem(1043+(i-1)*6)->SetWindowTextA(data[page][i][7]);
			}
		}
	}
}


void Profit::OnSave()
{
	CString x;
	GetDlgItem(IDC_Page)->GetWindowTextA(x);//获取页数
	int X=atoi(x);
	CString profit=0;
	CString sql;
	int i=0;
	for(i=0;i<10;i++)
	{
		GetDlgItem(1098+i)->GetWindowTextA(profit);
		if(!profit.IsEmpty())
		{
			sql.Format("update inventory.goods set G_profit=%s where G_id=%s",profit,data[X-1][i][0]);
			mysql_query(&m_sqlCon,sql);
		}
	}
	show();
}


BOOL Profit::PreTranslateMessage(MSG* pMsg)
{
	if(LR_flag)
	{
		LR_flag=false;
		show();
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}
