#pragma once

// CustomerBJ 对话框

class CustomerBJ : public CDialogEx
{
	DECLARE_DYNAMIC(CustomerBJ)

public:
	CustomerBJ(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CustomerBJ();
	void show();
// 对话框数据
	enum { IDD = IDD_CustomerBJ };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
