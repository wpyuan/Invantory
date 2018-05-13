// KuCunTJ.cpp : 实现文件
//

#include "stdafx.h"
#include "Invantory.h"
#include "KuCunTJ.h"
#include "afxdialogex.h"


// KuCunTJ 对话框

IMPLEMENT_DYNAMIC(KuCunTJ, CDialogEx)

KuCunTJ::KuCunTJ(CWnd* pParent /*=NULL*/)
	: CDialogEx(KuCunTJ::IDD, pParent)
{

}

KuCunTJ::~KuCunTJ()
{
}

void KuCunTJ::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_L);
}


BEGIN_MESSAGE_MAP(KuCunTJ, CDialogEx)
 
//	ON_WM_PAINT()
END_MESSAGE_MAP()



void KuCunTJ::show()
{
	datebase();
	m_L.DeleteAllItems();
	CString sql;
	sql.Format("SELECT I_type,I_kc,I_remark FROM inventory.inventory;");
	//执行查询
	MYSQL_RES *m_result;
	mysql_query(&m_sqlCon,sql);
	m_result=mysql_use_result(&m_sqlCon);
	int i=0;
	CString data[3];
	MYSQL_ROW row;
	while((row=mysql_fetch_row(m_result)))
	{
		//获取数据
		data[0]=row[0];
		data[1]=row[1];
		data[2]=row[2];
		// 在列表视图控件中插入列表项，并设置列表子项文本
		m_L.InsertItem(i, data[0]);
	    m_L.SetItemText(i, 1,data[1] );
		m_L.SetItemText(i, 2,data[2] );
		i++;
	}	
	mysql_free_result(m_result); //关联的内存会释放
}
BOOL KuCunTJ::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CRect rect;
	m_L.GetClientRect(&rect);
	// 为列表视图控件添加全行选中和栅格风格
	m_L.SetExtendedStyle(m_L.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	// 为列表视图控件添加3列   
	m_L.InsertColumn(0,_T("型号"),LVCFMT_CENTER,rect.Width()/3,0); //1 
    m_L.InsertColumn(1,_T("库存"),LVCFMT_CENTER,rect.Width()/3,1);//2
	m_L.InsertColumn(2,_T("备注"),LVCFMT_CENTER,rect.Width()/3,2); //3
	show();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}



BOOL KuCunTJ::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(KCTJ) 
	{
		show();
		KCTJ=false;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
