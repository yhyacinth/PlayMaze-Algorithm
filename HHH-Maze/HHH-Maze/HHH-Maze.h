
// HHH-Maze.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CHHHMazeApp:
// �� Ŭ������ ������ ���ؼ��� HHH-Maze.cpp�� �����Ͻʽÿ�.
//

class CHHHMazeApp : public CWinApp
{
public:
	CHHHMazeApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CHHHMazeApp theApp;