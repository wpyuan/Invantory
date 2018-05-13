#pragma once
#include "afxbutton.h"
#include "afxdtctl.h"


// DDadd 对话框

class DDadd : public CDialogEx
{
	DECLARE_DYNAMIC(DDadd)

public:
	DDadd(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DDadd();

// 对话框数据
	enum { IDD = IDD_DDadd };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	CMFCButton m_1;
	CMFCButton m_2;
	virtual BOOL OnInitDialog();
	afx_msg void OnSave();
	CDateTimeCtrl m_d1;
	CDateTimeCtrl m_d2;
	CDateTimeCtrl m_d3;
	CDateTimeCtrl m_d4;
	CDateTimeCtrl m_d5;
	CDateTimeCtrl m_d6;
	CDateTimeCtrl m_d7;
	CDateTimeCtrl m_d8;
	CDateTimeCtrl m_d9;
	CDateTimeCtrl m_d10;
	afx_msg void OnClose();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
