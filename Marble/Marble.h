
// Marble.h : Marble ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMarbleApp:
// �� Ŭ������ ������ ���ؼ��� Marble.cpp�� �����Ͻʽÿ�.
//

class CMarbleApp : public CWinApp
{
public:
	CMarbleApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMarbleApp theApp;
