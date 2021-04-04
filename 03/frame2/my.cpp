#include "my.h"

CMyWinApp theApp;

BOOL CMyWinApp::InitInstance()
{
	cout<<"CMyWinApp::InitInstance; Because i Made it!\n";
	m_pMainWnd = new CMFrameWnd;
	return TRUE;
}
CMFrameWnd::CMFrameWnd()
{
	cout<<"CMFrameWnd::CMFrameWnd\n";
	Create();
}

void main()
{ 
	CWinApp* pApp = AfxGetApp();//CMyWinApp 
	
	cout<<"\t\tpApp->InitApplication()"<<endl;
	pApp->InitApplication();
	
	cout<<"\t\tInitInstance()"<<endl;
	pApp->InitInstance();
	
	cout<<"\t\tpApp->Run()"<<endl;
	pApp->Run();
	
}
