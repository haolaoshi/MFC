#include "my.h"

extern CMyWinApp theApp;

CWinApp* AfxGetApp()
{
  return theApp.m_pCurrentWinApp;
}

BOOL CWnd::Create()
{
	cout<<"CWnd::Create  virtual   CObject-CCmdTrarget-CWnd\n";
	return TRUE;
}

BOOL CWnd::CreateEx()
{
	cout<<"CWnd::CreateEx @@@@@@@@@@@@ not virtual ; and real in CWnd;\n";
	PreCreateWindow();
	return TRUE;
}

BOOL CWnd::PreCreateWindow()
{
	cout<<"CWnd::PreCreateWindow  #### invoke near ??? ###\n";
	return TRUE;
}

BOOL CFrameWnd::Create()
{
	cout<<"CFrameWnd::Create ======= FROM CFrameWnd ; overrite virtual func.\n";
	CreateEx();
	return TRUE;
}

BOOL CFrameWnd::PreCreateWindow()
{
	cout<<"CFrameWnd::PreCreateWindow  #### invoke real #### \n";
	return TRUE;
}
