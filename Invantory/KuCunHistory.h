#pragma once
#include "afxcmn.h"


// KuCunHistory 对话框

class KuCunHistory : public CDialogEx
{
	DECLARE_DYNAMIC(KuCunHistory)

public:
	KuCunHistory(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~KuCunHistory();
	void show();
// 对话框数据
	enum { IDD = IDD_history };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_L;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
