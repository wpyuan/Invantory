
// Invantory.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CInvantoryApp:
// �йش����ʵ�֣������ Invantory.cpp
//

class CInvantoryApp : public CWinApp
{
public:
	CInvantoryApp();

// ��д
public:
	virtual BOOL InitInstance();
// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CInvantoryApp theApp;