// ZagDll.h: ������� ���� ��������� ��� DLL ZagDll
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CZagDllApp
// ��� ���������� ������� ������ ��. ZagDll.cpp
//

class CZagDllApp : public CWinApp
{
public:
	CZagDllApp();

// ���������������
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
