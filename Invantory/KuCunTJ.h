#pragma once
#include "afxcmn.h"


// KuCunTJ �Ի���

class KuCunTJ : public CDialogEx
{
	DECLARE_DYNAMIC(KuCunTJ)

public:
	KuCunTJ(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~KuCunTJ();
	void show();
// �Ի�������
	enum { IDD = IDD_KuCunTJ };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_L;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
