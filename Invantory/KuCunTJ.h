#pragma once
#include "afxcmn.h"


// KuCunTJ 对话框

class KuCunTJ : public CDialogEx
{
	DECLARE_DYNAMIC(KuCunTJ)

public:
	KuCunTJ(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~KuCunTJ();
	void show();
// 对话框数据
	enum { IDD = IDD_KuCunTJ };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_L;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
