#pragma once
#include "afxcmn.h"


// KuCunHistory �Ի���

class KuCunHistory : public CDialogEx
{
	DECLARE_DYNAMIC(KuCunHistory)

public:
	KuCunHistory(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~KuCunHistory();
	void show();
// �Ի�������
	enum { IDD = IDD_history };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_L;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
