#pragma once
#include "afxbutton.h"


// Profit 对话框

class Profit : public CDialogEx
{
	DECLARE_DYNAMIC(Profit)

public:
	Profit(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Profit();
	void show();
	void sanwInitDialog();
	int pageMax,page;
	CString data[10][10][10];//页 行 列

// 对话框数据
	enum { IDD = IDD_Profit };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	CMFCButton m_1;
	CMFCButton m_2;
	CMFCButton m_3;
	CMFCButton m_4;
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	afx_msg void OnUpPage();
	afx_msg void OnDownPage();
	afx_msg void OnSave();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
