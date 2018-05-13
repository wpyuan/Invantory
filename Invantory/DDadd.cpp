// DDadd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Invantory.h"
#include "DDadd.h"
#include "afxdialogex.h"


// DDadd �Ի���

IMPLEMENT_DYNAMIC(DDadd, CDialogEx)

DDadd::DDadd(CWnd* pParent /*=NULL*/)
	: CDialogEx(DDadd::IDD, pParent)
{

}

DDadd::~DDadd()
{
}

void DDadd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCBUTTON2, m_1);
	DDX_Control(pDX, IDC_MFCBUTTON3, m_2);
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


BEGIN_MESSAGE_MAP(DDadd, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_MFCBUTTON3, &DDadd::OnSave)
	ON_BN_CLICKED(IDC_MFCBUTTON2, &DDadd::OnClose)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// DDadd ��Ϣ�������


void DDadd::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CBitmap m_Back;
	m_Back.LoadBitmap(IDB_BITMAP22);
	//����һ���ڴ��豸��������󣨼��󱸻�������  
	CDC mdc;
	//��������Ļ�豸������ǰ�˻����������ݵ��ڴ��豸�����������󱸻�������  
    mdc.CreateCompatibleDC(&dc); 
	mdc.SelectObject(&m_Back);
	//���󱸻������е�ͼ�ο�����ǰ�˻�����  
	dc.BitBlt(0,0,1050,580,&mdc,0,0,SRCCOPY);
	//��ͼ��ɺ������  
	m_Back.DeleteObject();  
	mdc.DeleteDC();
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
}


BOOL DDadd::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_1.SetFaceColor(RGB(255, 201, 240));
	m_1.SetTextColor(RGB(11,74,125));
	m_1.SetTextHotColor(RGB(204,232,207));
	m_2.SetFaceColor(RGB(255, 201, 240));
	m_2.SetTextColor(RGB(11,74,125));
	m_2.SetTextHotColor(RGB(204,232,207));
	GetDlgItem(IDC_MFCBUTTON3)->SetFont(&m_editFont);// ����������
	GetDlgItem(IDC_MFCBUTTON2)->SetFont(&m_editFont);// ����������

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void DDadd::OnSave()
{
	CString time;
	CTime tm;
	CString xh;
	CString kh;
	CString sl;
	CString dj;
	CString je;
	CString bz;
	int check[10]={};
	m_d1.GetTime(tm);
	time=tm.Format("%Y%m%d");
	GetDlgItem(IDC_EDIT1)->GetWindowTextA(xh);
	GetDlgItem(IDC_EDIT2)->GetWindowTextA(kh);
	GetDlgItem(IDC_EDIT3)->GetWindowTextA(sl);
	GetDlgItem(IDC_EDIT6)->GetWindowTextA(dj);
	GetDlgItem(IDC_EDIT4)->GetWindowTextA(je);
	GetDlgItem(IDC_EDIT5)->GetWindowTextA(bz);
	CString sql;
	sql.Format("INSERT INTO inventory.goods value(null, '%s', '%s', '%s', %s, %s, %s ,'%s',%s)", time,xh,kh,sl,dj,je,bz,NULL );	
	if(  mysql_query(&m_sqlCon, sql)==0 )
		check[0]=1;
	for(int i=1;i<10;i++)
	{
		if(i==1)
		{
			m_d2.GetTime(tm);
			time=tm.Format("%Y%m%d");
		}
		if(i==2)
		{
			m_d3.GetTime(tm);
			time=tm.Format("%Y%m%d");
		}
		if(i==3)
		{
			m_d4.GetTime(tm);
			time=tm.Format("%Y%m%d");
		}
		if(i==4)
		{
			m_d5.GetTime(tm);
			time=tm.Format("%Y%m%d");
		}
		if(i==5)
		{
			m_d6.GetTime(tm);
			time=tm.Format("%Y%m%d");
		}
		if(i==6)
		{
			m_d7.GetTime(tm);
			time=tm.Format("%Y%m%d");
		}
		if(i==7)
		{
			m_d8.GetTime(tm);
			time=tm.Format("%Y%m%d");
		}
		if(i==8)
		{
			m_d9.GetTime(tm);
			time=tm.Format("%Y%m%d");
		}
		if(i==9)
		{
			m_d10.GetTime(tm);
			time=tm.Format("%Y%m%d");
		}
		GetDlgItem(1039+(i-1)*6)->GetWindowTextA(xh);
		GetDlgItem(1040+(i-1)*6)->GetWindowTextA(kh);
		GetDlgItem(1041+(i-1)*6)->GetWindowTextA(sl);
		GetDlgItem(1044+(i-1)*6)->GetWindowTextA(dj);
		GetDlgItem(1042+(i-1)*6)->GetWindowTextA(je);
		GetDlgItem(1043+(i-1)*6)->GetWindowTextA(bz);
		sql.Format("INSERT INTO inventory.goods value(null, '%s', '%s', '%s', %s, %s, %s ,'%s',%s)", time,xh,kh,sl,dj,je,bz,NULL );	
		if(  mysql_query(&m_sqlCon, sql)==0 )
			check[i]=1;
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
				GetDlgItem(1093+i)->SetWindowTextA("����");
				GetDlgItem(1093+i)->GetWindowTextA(text);		
		}
	}
	if(text.IsEmpty())
	{
		if(s)
		{
			if(MessageBox("����ɹ����Ƿ������ӣ�","��ʾ��" ,MB_ICONEXCLAMATION|MB_OKCANCEL)==IDOK)
			{
				for(int i=1000;i<=1102;i++)
				{
					if(i<=1001||i>=1035)
					GetDlgItem(i)->SetWindowTextA("");
				}
			}
		}
		else
			MessageBox("ĪҪ��Ц������û�������κ����ݣ�ϵͳ���԰����������ݡ�","��ʾ��" );
		
	}
	else 
	{
		if(MessageBox("ĳ�б�������Ƿ񷵻��޸ģ�","��ʾ��" ,MB_ICONEXCLAMATION|MB_OKCANCEL)==IDCANCEL)
		{
			for(int i=1000;i<=1102;i++)
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


void DDadd::OnClose()
{
	if(MessageBox("ȷ���رգ�","��ʾ��" ,MB_ICONEXCLAMATION|MB_OKCANCEL)==IDOK)
	 {
		 CDialogEx::OnOK();
		 for(int i=1000;i<=1092;i++)
		 {
			 if(i<=1001||i>=1035)
			 GetDlgItem(i)->SetWindowTextA("");
		 }
	 }
}


void DDadd::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(point.x>=650&&point.x<=799&&point.y>=6&&point.y<=33)
		SetCursor(LoadCursor(NULL, IDC_HAND));
	CDialogEx::OnMouseMove(nFlags, point);
}


void DDadd::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	/*CString x;
	x.Format("%d ,%d",point.x,point.y); 650 6 799 33
	MessageBox(x);*/
	if(point.x>=650&&point.x<=799&&point.y>=6&&point.y<=33)
	{
		CString sl,dj,je;
		double SL,DJ,JE;
		GetDlgItem(IDC_EDIT3)->GetWindowTextA(sl);
		GetDlgItem(IDC_EDIT6)->GetWindowTextA(dj);
		if(!sl.IsEmpty()&&!dj.IsEmpty())
		{
			SL=atof(sl);
			DJ=atof(dj);
			JE=SL*DJ;
			je.Format("%.1lf",JE);
			GetDlgItem(IDC_EDIT4)->SetWindowTextA(je);
		}
		for(int i=1;i<10;i++)
		{
		
			GetDlgItem(1041+(i-1)*6)->GetWindowTextA(sl);
			GetDlgItem(1044+(i-1)*6)->GetWindowTextA(dj);
			if(!sl.IsEmpty()&&!dj.IsEmpty())
		    {
				SL=atof(sl);
				DJ=atof(dj);
				JE=SL*DJ;
				je.Format("%.1lf",JE);
				GetDlgItem(1042+(i-1)*6)->SetWindowTextA(je);
			}
		}
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}
