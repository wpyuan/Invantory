// DDTJ.cpp : 实现文件
//

#include "stdafx.h"
#include "Invantory.h"
#include "DDTJ.h"
#include "afxdialogex.h"


// DDTJ 对话框

IMPLEMENT_DYNAMIC(DDTJ, CDialogEx)

DDTJ::DDTJ(CWnd* pParent /*=NULL*/)
	: CDialogEx(DDTJ::IDD, pParent)
{

}

DDTJ::~DDTJ()
{
}

void DDTJ::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCBUTTON2, m_1);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_d1);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_d2);
	DDX_Control(pDX, IDC_LIST1, m_L);
}


BEGIN_MESSAGE_MAP(DDTJ, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_MFCBUTTON2, &DDTJ::OnStatistics)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_LIST1, OnCustomdrawList)//cjz
END_MESSAGE_MAP()


// DDTJ 消息处理程序


void DDTJ::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CBitmap m_Back;
	m_Back.LoadBitmap(IDB_BITMAP25);
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


BOOL DDTJ::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_1.SetFaceColor(RGB(255, 201, 240));
	m_1.SetTextColor(RGB(11,74,125));
	m_1.SetTextHotColor(RGB(204,232,207));
	GetDlgItem(IDC_MFCBUTTON2)->SetFont(&m_editFont);// 设置新字体
	//m_L.SetBkColor(RGB(160,180,220)); 
	//m_L.SetTextBkColor(RGB(160,180,220));
	CRect rect;
	m_L.GetClientRect(&rect);
	// 为列表视图控件添加全行选中和栅格风格
	m_L.SetExtendedStyle(m_L.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	// 为列表视图控件添加7列 
	if(password=="88785268")
	{
		m_L.InsertColumn(0,_T("日期"),LVCFMT_CENTER,rect.Width()/7,0); //1 
		m_L.InsertColumn(1,_T("型号"),LVCFMT_CENTER,rect.Width()/7,1);//2
		m_L.InsertColumn(2,_T("客户"),LVCFMT_CENTER,rect.Width()/7,2); //3
		m_L.InsertColumn(3,_T("数量"),LVCFMT_CENTER,rect.Width()/7,3); //1 
		m_L.InsertColumn(4,_T("单价"),LVCFMT_CENTER,rect.Width()/7,4);//2
		m_L.InsertColumn(5,_T("金额"),LVCFMT_CENTER,rect.Width()/7,5); //3
		m_L.InsertColumn(6,_T("备注"),LVCFMT_CENTER,rect.Width()/7,6); //3
	}
	else
	{
		m_L.InsertColumn(0,_T("日期"),LVCFMT_CENTER,rect.Width()/8,0); //1 
		m_L.InsertColumn(1,_T("型号"),LVCFMT_CENTER,rect.Width()/8,1);//2
		m_L.InsertColumn(2,_T("客户"),LVCFMT_CENTER,rect.Width()/8,2); //3
		m_L.InsertColumn(3,_T("数量"),LVCFMT_CENTER,rect.Width()/8,3); //1 
		m_L.InsertColumn(4,_T("单价"),LVCFMT_CENTER,rect.Width()/8,4);//2
		m_L.InsertColumn(5,_T("金额"),LVCFMT_CENTER,rect.Width()/8,5); //3
		m_L.InsertColumn(6,_T("备注"),LVCFMT_CENTER,rect.Width()/8,6); //3
		m_L.InsertColumn(7,_T("利润"),LVCFMT_CENTER,rect.Width()/8,7); //3
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void DDTJ::OnCustomdrawList(NMHDR *pNMHDR, LRESULT *pResult)
{
    //////////////////////////////////////////////////////
    NMLVCUSTOMDRAW* pLVCD = reinterpret_cast<NMLVCUSTOMDRAW*>( pNMHDR );

    // Take the default processing unless we 

// set this to something else below.

    *pResult = CDRF_DODEFAULT;

    // First thing - check the draw stage. If it's the control's prepaint

// stage, then tell Windows we want messages for every item.


    if ( CDDS_PREPAINT == pLVCD->nmcd.dwDrawStage )
    {
        *pResult = CDRF_NOTIFYITEMDRAW;
    }
    else if ( CDDS_ITEMPREPAINT == pLVCD->nmcd.dwDrawStage )
    {
        COLORREF crText,crBk;
		//奇偶判断
        if ( (pLVCD->nmcd.dwItemSpec % 2) == 0 ){
            crText = RGB(0,0,0);//RGB(32,32,255);
            crBk =RGB(229,232,255);
        }
        else if ( (pLVCD->nmcd.dwItemSpec % 2) == 1 ){
            crText = RGB(0,0,0);
            crBk = RGB(240,247,249);
        }
        else{
            crText = RGB(0,0,0);
            crBk = RGB(0,0,126);
        }
		if(pLVCD->nmcd.dwItemSpec==nIndex)
		{
            crBk = RGB(135,206,235);
		}
        // Store the color back in the NMLVCUSTOMDRAW struct.

        pLVCD->clrText = crText;
        pLVCD->clrTextBk = crBk;
        //设置选择项的颜色
        if( this->m_L.GetItemState(pLVCD->nmcd.dwItemSpec, CDIS_SELECTED) ){
            crBk =RGB(75, 149, 229);//itunes//RGB(10, 36, 106);//RGB(0, 0, 64);
			crText = RGB(255,255,255);
            pLVCD->clrText = crText;
            pLVCD->clrTextBk = crBk;
            *pResult = CDRF_NEWFONT;
        }
        if(LVIS_SELECTED == m_L.GetItemState(pLVCD->nmcd.dwItemSpec,LVIS_SELECTED))
        {
            //清除选择状态，如果不清除的话，还是会显示出蓝色的高亮条
            BOOL b = m_L.SetItemState(pLVCD->nmcd.dwItemSpec,0,LVIS_SELECTED); 
            pLVCD->clrText = crText;
            pLVCD->clrTextBk = crBk;

            *pResult = CDRF_NEWFONT;
            return;
        }
        *pResult = CDRF_NEWFONT;
        //*pResult = CDRF_DODEFAULT;
    }
}
void DDTJ::OnStatistics()
{
	CTime tm;
	CString rq1,rq2,kh,xh;
	m_d1.GetTime(tm);
	rq1=tm.Format("%Y%m%d");
	m_d2.GetTime(tm);
	rq2=tm.Format("%Y%m%d");
	GetDlgItem(IDC_EDIT1)->GetWindowTextA(kh);
	GetDlgItem(IDC_EDIT2)->GetWindowTextA(xh);
	CString sql;
	m_L.DeleteAllItems();
	if(kh.IsEmpty()&&xh.IsEmpty())
		sql.Format("SELECT * FROM inventory.goods where G_time>='%s' and G_time<='%s';",rq1,rq2);
	else//1 0  ； 0 1 ； 1 1
	{
		if(!kh.IsEmpty())//1 0 ；1 1
		{
			sql.Format("SELECT * FROM inventory.goods where G_time>='%s' and G_time<='%s' and G_customer='%s';",rq1,rq2,kh);
			if(!xh.IsEmpty())
				sql.Format("SELECT * FROM inventory.goods where G_time>='%s' and G_time<='%s' and G_customer='%s' and G_type='%s';",rq1,rq2,kh,xh);
		}
		else //0 1
			sql.Format("SELECT * FROM inventory.goods where G_time>='%s' and G_time<='%s' and G_type='%s';",rq1,rq2,xh);
	}
	//执行查询
	MYSQL_RES *m_result;
	mysql_query(&m_sqlCon,sql);
	m_result=mysql_use_result(&m_sqlCon);
	CString data[9],sl,je,lr;
	double SL=0,SLSUM=0,JE=0,JESUM=0,LR=0,LRSUM=0;
	int i=0;
	nIndex = 0;
	MYSQL_ROW row;
	bool q=false;
	while((row=mysql_fetch_row(m_result)))
	{
		q=true;
		//获取数据
		data[1]=row[1];
		data[2]=row[2];
		data[3]=row[3];
		data[4]=row[4];
		data[5]=row[5];
		data[6]=row[6];
		data[7]=row[7];
		SL=atof(data[4]);
		JE=atof(data[6]);

		SLSUM=SLSUM+SL;
		JESUM=JESUM+JE;
		// 在列表视图控件中插入列表项，并设置列表子项文本
		m_L.InsertItem(i, data[1]);
	    m_L.SetItemText(i, 1,data[2] );
		m_L.SetItemText(i, 2,data[3] );
		m_L.SetItemText(i, 3,data[4] );
		m_L.SetItemText(i, 4,data[5] );
		m_L.SetItemText(i, 5,data[6] );
		m_L.SetItemText(i, 6,data[7] );
		if(password=="6335598")
		{
			data[8]=row[8];
			LR=atof(data[8]);
			LRSUM=LRSUM+LR;
			m_L.SetItemText(i, 7,data[8] );
		}
		i++;
		nIndex++;
	}
	if(!q)
		MessageBox("经查询，无此条件订单记录。","提示",MB_ICONEXCLAMATION|MB_OK);
	else
	{
		sl.Format("%.1lf",SLSUM);
		je.Format("%.1lf",JESUM);
		lr.Format("%.1lf",LRSUM);
		m_L.InsertItem(i, "-------------");
	    m_L.SetItemText(i, 1,"----总和----" );
		m_L.SetItemText(i, 2,"-------数量:" );
		m_L.SetItemText(i, 3,sl );
		m_L.SetItemText(i, 4,"-------金额:" );
		m_L.SetItemText(i, 5,je );		
		if(password=="6335598")
		{
			m_L.SetItemText(i, 6,"-------利润:" );
			m_L.SetItemText(i, 7, lr);
		}
		else m_L.SetItemText(i, 6, "-------------");
	}
	mysql_free_result(m_result); //关联的内存会释放
}
