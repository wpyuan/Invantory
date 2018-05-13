#pragma once
#include "afxbutton.h"
#include "afxdtctl.h"
#include "afxcmn.h"


// KuCunSearch 对话框

class KuCunSearch : public CDialogEx
{
	DECLARE_DYNAMIC(KuCunSearch)

public:
	KuCunSearch(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~KuCunSearch();

// 对话框数据
	enum { IDD = IDD_KuCunSearch };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	CMFCButton m_1;
	virtual BOOL OnInitDialog();
	afx_msg void OnSearch();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CDateTimeCtrl m_d1;
	CDateTimeCtrl m_d2;
	CListCtrl m_L;
	CMFCButton m_2;
	afx_msg void OnLS_Search();
};
