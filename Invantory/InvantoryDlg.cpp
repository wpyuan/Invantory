
// InvantoryDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Invantory.h"
#include "InvantoryDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CInvantoryDlg �Ի���

static int times;


CInvantoryDlg::CInvantoryDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInvantoryDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CInvantoryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, m_login);
}

BEGIN_MESSAGE_MAP(CInvantoryDlg, CDialogEx)
	ON_WM_QUERYDRAGICON()
	ON_WM_PAINT()
ON_WM_TIMER()
ON_WM_LBUTTONDOWN()
ON_WM_NCHITTEST()
ON_BN_CLICKED(IDOK, &CInvantoryDlg::OnLogin)
END_MESSAGE_MAP()


// CInvantoryDlg ��Ϣ�������

BOOL CInvantoryDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	SetTimer(1,150,NULL);
	flag=129;
	m_login.SetFaceColor(RGB(50,205,255));
	m_login.SetTextColor(RGB(255,255,255));
	m_login.SetTextHotColor(RGB(255,0,255));
	Font();
	GetDlgItem(IDOK)->SetFont(&m_editFont);// ����������
	times=4;
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}




//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CInvantoryDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CInvantoryDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	//����һ��λͼ���� 
	CBitmap m_Back;
	m_Back.LoadBitmap(flag);
	//����һ���ڴ��豸��������󣨼��󱸻�������  
	CDC mdc;
	//��������Ļ�豸������ǰ�˻����������ݵ��ڴ��豸�����������󱸻�������  
    mdc.CreateCompatibleDC(&dc); 
	////��ʱ�����ܻ�ͼ����Ϊû��λͼ���豸�������ǲ��ܻ�ͼ��  
	////���潨��һ������Ļ�豸�����������ڴ��豸���������ݵ�λͼ  
	//m_Back.CreateCompatibleBitmap(&dc,800,600);  
	////��λͼѡ�뵽�ڴ��豸������  
	////ֻ��ѡ����λͼ���豸��������еط���ͼ������ָ����λͼ��  
	//CBitmap *pOldBit=mdc.SelectObject(&m_Back);
	//���ñ���ɫ��λͼ����ɾ����������õ��ǰ�ɫ��Ϊ����  
	//��Ҳ�������Լ�Ӧ���õ���ɫ 
	//��ͼ
	mdc.SelectObject(&m_Back);
	//���󱸻������е�ͼ�ο�����ǰ�˻�����  
	dc.BitBlt(0,0,553,174,&mdc,0,0,SRCCOPY);
	CBitmap m_b2;
	m_b2.LoadBitmap(IDB_BITMAP16);
	mdc.SelectObject(&m_b2);
	//���󱸻������е�ͼ�ο�����ǰ�˻�����  
	dc.BitBlt(0,174,553,200,&mdc,0,0,SRCCOPY);
	//��ͼ��ɺ������  
	m_Back.DeleteObject();  
	mdc.DeleteDC();
	m_b2.DeleteObject();
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
}

void CInvantoryDlg::OnTimer(UINT_PTR nIDEvent)
{
	CRect r(0,0,553,174);
	InvalidateRect(r,0);
	if(nIDEvent==1)
		flag++;
	if(flag==144)
		KillTimer(1);
	CDialogEx::OnTimer(nIDEvent);
}


void CInvantoryDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(point.x>=490&&point.y<=50)
		CDialogEx::OnOK();
	/*CString x;
	x.Format("%d ,%d",point.x,point.y);
	MessageBox(x);*/

	CDialogEx::OnLButtonDown(nFlags, point);
}


LRESULT CInvantoryDlg::OnNcHitTest(CPoint point)
{
	CRect rc;
	GetClientRect(&rc);
	ClientToScreen(&rc);
	int x=point.x;
	int y=point.y;
	if (x>rc.left && x<rc.right-100 && y>rc.top && y<rc.top+25) {
		return HTCAPTION;
	}
	return CDialogEx::OnNcHitTest(point);
}


void CInvantoryDlg::OnLogin()
{
	GetDlgItem(IDC_EDIT1)->GetWindowTextA(password);
	if(password=="88785268")
	{
		if(MessageBox("Ա����¼�ɹ�","��ʾ",MB_ICONEXCLAMATION|MB_OKCANCEL)==IDOK)
		{
			CDialogEx::OnOK();
			C_Menu dlg;
			dlg.DoModal();
		}
	}
	else if(password=="6335598")
	{
		if(MessageBox("����Ա��¼�ɹ�","��ʾ",MB_ICONEXCLAMATION|MB_OKCANCEL)==IDOK)
		{
			CDialogEx::OnOK();
			C_Menu dlg;
			dlg.DoModal();
		}
	}
	else
	{
		if(times!=0)
			times--;
		if(times==3)
			if(MessageBox("��������������������룬������3�λ���","��ʾ",MB_ICONEXCLAMATION|MB_OKCANCEL)==IDCANCEL)
				CDialogEx::OnOK();
		if(times==2)
			if(MessageBox("��������������������룬������2�λ���","��ʾ",MB_ICONEXCLAMATION|MB_OKCANCEL)==IDCANCEL)
				CDialogEx::OnOK();
		if(times==1)
			if(MessageBox("��������������������룬������1�λ���","��ʾ",MB_ICONEXCLAMATION|MB_OKCANCEL)==IDCANCEL)
				CDialogEx::OnOK();
		if(times==0)
			if(MessageBox("�����������3�λ������꣬ϵͳ���밲ȫ��Ĭģʽ��24Сʱ���Զ�������ҹ���Ա�����","��ʾ",MB_ICONEXCLAMATION|MB_OKCANCEL)==IDCANCEL)
				CDialogEx::OnOK();
	}
}
