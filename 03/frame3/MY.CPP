#include "my.h"
CMyWinApp theApp;

BOOL CMyWinApp::InitInstance()
{
	m_pMainWnd = new CMyFrameWnd;
	return TRUE;
}
CMyFrameWnd::CMyFrameWnd()
{
	Create();
}
void PrintAllClasses()
{
	CRuntimeClass* pClass;
	for(pClass = CRuntimeClass::pFirstClass; pClass != NULL;
		pClass = pClass->m_pNextClass)
		{
			cout << pClass->m_lpszClassName ;
			cout <<"\t"<< pClass->m_nObjectSize ;
			cout <<"\t"<< pClass->m_wSchema << endl;
		}
}
void main()
{
	CWinApp *pApp = AfxGetApp();
	pApp->InitApplication();
	pApp->InitInstance();
	pApp->Run();
	
	PrintAllClasses();
}