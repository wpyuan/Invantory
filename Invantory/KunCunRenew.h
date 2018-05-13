#pragma once
#include "afxbutton.h"
#include "afxdtctl.h"


// KunCunRenew 对话框

class KunCunRenew : public CDialogEx
{
	DECLARE_DYNAMIC(KunCunRenew)

public:
	KunCunRenew(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~KunCunRenew();

// 对话框数据
	enum { IDD = IDD_KuCunGX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	CMFCButton m_1;
	CMFCButton m_2;
	CMFCButton m_3;
	afx_msg void OnClose();
	afx_msg void OnSearch();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRenew();
	CDateTimeCtrl m_time;
};
