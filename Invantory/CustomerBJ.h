#pragma once

// CustomerBJ �Ի���

class CustomerBJ : public CDialogEx
{
	DECLARE_DYNAMIC(CustomerBJ)

public:
	CustomerBJ(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CustomerBJ();
	void show();
// �Ի�������
	enum { IDD = IDD_CustomerBJ };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
