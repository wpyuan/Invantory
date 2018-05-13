#pragma once
#include "afxbutton.h"
#include "afxdtctl.h"
#include "afxcmn.h"


// DDTJ 对话框

class DDTJ : public CDialogEx
{
	DECLARE_DYNAMIC(DDTJ)

public:
	DDTJ(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DDTJ();
	int nIndex;
// 对话框数据
	enum { IDD = IDD_DDTJ };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	CMFCButton m_1;
	virtual BOOL OnInitDialog();
	CDateTimeCtrl m_d1;
	CDateTimeCtrl m_d2;
	CListCtrl m_L;
	afx_msg void OnStatistics();
	afx_msg void OnCustomdrawList(NMHDR*, LRESULT*);//cjz
};
