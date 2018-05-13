// KunCunRenew.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Invantory.h"
#include "KunCunRenew.h"
#include "afxdialogex.h"


// KunCunRenew �Ի���

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


// KunCunRenew ��Ϣ�������


void KunCunRenew::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CBitmap m_Back;
	m_Back.LoadBitmap(IDB_BITMAP19);
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
	GetDlgItem(IDC_MFCBUTTON1)->SetFont(&m_editFont);// ����������
	GetDlgItem(IDC_MFCBUTTON2)->SetFont(&m_editFont);// ����������
	GetDlgItem(IDC_MFCBUTTON3)->SetFont(&m_editFont);// ����������

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void KunCunRenew::OnClose()
{
	if(MessageBox("ȷ���رգ�","��ʾ��" ,MB_ICONEXCLAMATION|MB_OKCANCEL)==IDOK)
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
	//ִ�в�ѯ
	MYSQL_RES *m_result;
	mysql_query(&m_sqlCon,sql);
	m_result=mysql_use_result(&m_sqlCon);
	CString data[2];
	MYSQL_ROW row;
	if((row=mysql_fetch_row(m_result)))
	{
		//��ȡ����
		data[0]=row[0];
		data[1]=row[1];
		GetDlgItem(IDC_EDIT31)->SetWindowTextA(xh);
		GetDlgItem(IDC_EDIT37)->SetWindowTextA(xh);
		GetDlgItem(IDC_EDIT19)->SetWindowTextA(data[0]);
		GetDlgItem(IDC_EDIT20)->SetWindowTextA(data[1]);
		GetDlgItem(IDC_EDIT41)->SetWindowTextA(data[1]);
	}
	else
		MessageBox("����ѯ���޴��ͺſ���¼�����������ͺ��Ƿ���ȷ���룡","��ʾ",MB_ICONEXCLAMATION|MB_OK);
	mysql_free_result(m_result); //�������ڴ���ͷ�
}


void KunCunRenew::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(point.x>=652&&point.x<=800&&point.y>=283&&point.y<=333)
		SetCursor(LoadCursor(NULL, IDC_HAND));
	CDialogEx::OnMouseMove(nFlags, point);
}


void KunCunRenew::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
			MessageBox("����ʧ��","��ʾ",MB_ICONEXCLAMATION); 
		else
		{
			MessageBox("���³ɹ�","��ʾ",MB_ICONEXCLAMATION);
			sql.Format("INSERT INTO inventory.history value(null, '%s', '%s', %s, %s, %s, '%s')", rq,xh,rk,ck,kc,bz );
			mysql_query(&m_sqlCon, sql);
		}
}
