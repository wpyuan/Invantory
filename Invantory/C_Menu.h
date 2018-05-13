#pragma once
#include "afxbutton.h"
#include "KuCunAdd.h"
#include "afxwin.h"
#include "KunCunRenew.h"
#include "KuCunTJ.h"
#include "KuCunHistory.h"
#include "KuCunUpdata.h"
#include "KuCunSearch.h"
#include "DDadd.h"
#include "DDSUD.h"
#include "DDTJ.h"
#include "Profit.h"
#include "Customer.h"
#include "shockwaveflash1.h"
// C_Menu 对话框

class C_Menu : public CDialogEx
{
	DECLARE_DYNAMIC(C_Menu)

public:
	C_Menu(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~C_Menu();

// 对话框数据
	enum { IDD = IDD_Menu };

protected:
	KuCunAdd m_kca;
	KunCunRenew m_kcr;
	KuCunTJ m_kctj;
	KuCunHistory m_kch;
	KuCunUpdata m_kcu;
	KuCunSearch m_kcs;
	DDSUD m_dd3;
	DDadd m_dda;
	DDTJ m_ddtj;
	Profit m_ddp;
	Customer m_c;
	CRect m_kcac;

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CMFCButton m_1;
	CMFCButton m_2;
	CMFCButton m_3;
	CMFCButton m_4;
	CMFCButton m_5;
	CMFCButton m_6;
	CMFCButton m_7;
	CMFCButton m_8;
	CMFCButton m_9;
	afx_msg void OnKuCunMenu();
	afx_msg void OnDingDanMenu();
	afx_msg void OnCustomerMenu();
	CMFCButton m_10;
	CMFCButton m_11;
	CMFCButton m_12;
	CMFCButton m_13;
	CMFCButton m_14;
	CMFCButton m_15;
	CMFCButton m_16;
	CMFCButton m_17;
	CMFCButton m_18;
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnRenew();
//	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CEdit m_time;
	afx_msg void OnKunCunAdd();
	afx_msg void OnKuCunSearch();
	afx_msg void OnKuCunStatistics();
	afx_msg void OnKuCunHistory();
	afx_msg void OnKuCunUpdata();
	afx_msg void OnDingDanAdd();
	afx_msg void OnDD_s_u_d();
	afx_msg void OnDDtj();
	afx_msg void OnProfit();
	CShockwaveflash1 m_exit;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
