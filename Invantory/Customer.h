#pragma once
#include "afxcmn.h"
#include "CustomerBJ.h"

// Customer �Ի���

class Customer : public CDialogEx
{
	DECLARE_DYNAMIC(Customer)

public:
	Customer(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Customer();
	void show();
// �Ի�������
	enum { IDD = IDD_Customer };

protected:
	CustomerBJ m_cbj;
	CRect m_kcac;

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	CListCtrl m_L;
	afx_msg void OnNMRClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL OnInitDialog();
	afx_msg void On32771();
	afx_msg void On32772();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};
