#pragma once
#include "afxcmn.h"


// DDSUD 对话框

class DDSUD : public CDialogEx
{
	DECLARE_DYNAMIC(DDSUD)

public:
	DDSUD(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DDSUD();

// 对话框数据
	enum { IDD = IDD_DDSUD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual BOOL OnInitDialog();
	afx_msg void OnSearch1();
	CListCtrl m_L;
	afx_msg void OnSearch2();
	afx_msg void OnDelete_Update();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};
