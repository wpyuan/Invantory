#pragma once
#include "afxbutton.h"


// KuCunUpdata �Ի���

class KuCunUpdata : public CDialogEx
{
	DECLARE_DYNAMIC(KuCunUpdata)

public:
	KuCunUpdata(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~KuCunUpdata();

// �Ի�������
	enum { IDD = IDD_KuCunUpdata };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CMFCButton m_1;
	CMFCButton m_2;
	virtual BOOL OnInitDialog();
	afx_msg void OnSearch();
	afx_msg void OnUpdate();
};
