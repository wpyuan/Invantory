// KuCunHistory.cpp : 实现文件
//

#include "stdafx.h"
#include "Invantory.h"
#include "KuCunHistory.h"
#include "afxdialogex.h"


// KuCunHistory 对话框

IMPLEMENT_DYNAMIC(KuCunHistory, CDialogEx)

KuCunHistory::KuCunHistory(CWnd* pParent /*=NULL*/)
	: CDialogEx(KuCunHistory::IDD, pParent)
{

}

KuCunHistory::~KuCunHistory()
{
}

void KuCunHistory::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_L);
}


BEGIN_MESSAGE_MAP(KuCunHistory, CDialogEx)
END_MESSAGE_MAP()


// KuCunHistory 消息处理程序

void KuCunHistory::show()
{
	datebase();
	m_L.DeleteAllItems();
	CString data[7];
	CString sql;
	sql.Format("SELECT * FROM inventory.history;");
	//执行查询
	MYSQL_RES *m_result;
	mysql_query(&m_sqlCon,sql);
	m_result=mysql_use_result(&m_sqlCon);
	int i=0;
	MYSQL_ROW row;
	while((row=mysql_fetch_row(m_result)))
	{
		//获取数据
		data[1]=row[1];
		data[2]=row[2];
		data[3]=row[3];
		data[4]=row[4];
		data[5]=row[5];
		data[6]=row[6];
		// 在列表视图控件中插入列表项，并设置列表子项文本
		m_L.InsertItem(i, data[1]);
	    m_L.SetItemText(i, 1,data[2] );
		m_L.SetItemText(i, 2,data[3] );
		m_L.SetItemText(i, 3,data[4] );
		m_L.SetItemText(i, 4,data[5] );
		m_L.SetItemText(i, 5,data[6] );
		i++;
	}	
	mysql_free_result(m_result); //关联的内存会释放
}
BOOL KuCunHistory::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CRect rect;
	m_L.GetClientRect(&rect);
	// 为列表视图控件添加全行选中和栅格风格
	m_L.SetExtendedStyle(m_L.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	// 为列表视图控件添加6列   
	m_L.InsertColumn(0,_T("日期"),LVCFMT_CENTER,rect.Width()/6,0); //1 
    m_L.InsertColumn(1,_T("型号"),LVCFMT_CENTER,rect.Width()/6,1);//2
	m_L.InsertColumn(2,_T("入库"),LVCFMT_CENTER,rect.Width()/6,2); //3
	m_L.InsertColumn(3,_T("出库"),LVCFMT_CENTER,rect.Width()/6,3); //1 
    m_L.InsertColumn(4,_T("库存"),LVCFMT_CENTER,rect.Width()/6,4);//2
	m_L.InsertColumn(5,_T("备注"),LVCFMT_CENTER,rect.Width()/6,5); //3
	show();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


BOOL KuCunHistory::PreTranslateMessage(MSG* pMsg)
{
	if(KCLS)
	{
		KCLS=false;
		show();
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}
