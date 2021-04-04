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

IMPLEMENT_DYNAMIC(CMyFrameWnd,CFrameWnd)
IMPLEMENT_DYNAMIC(CMyDoc,CDocument)
IMPLEMENT_DYNAMIC(CMyView,CView)

void main()
{
 
	CMyDoc* pMyDoc = new CMyDoc;
	CMyView* pMyView = new CMyView;
	
	cout<<pMyDoc->IsKindOf(RUNTIME_CLASS(CMyDoc));
	cout<<pMyDoc->IsKindOf(RUNTIME_CLASS(CDocument));
	cout<<pMyDoc->IsKindOf(RUNTIME_CLASS(CCmdTarget));
	cout<<pMyDoc->IsKindOf(RUNTIME_CLASS(CObject));
	cout<<pMyDoc->IsKindOf(RUNTIME_CLASS(CWinApp));
	cout<<pMyDoc->IsKindOf(RUNTIME_CLASS(CView));
	
	cout<<pMyView->IsKindOf(RUNTIME_CLASS(CView));
	cout<<pMyView->IsKindOf(RUNTIME_CLASS(CObject));
	cout<<pMyView->IsKindOf(RUNTIME_CLASS(CWnd));
	cout<<pMyView->IsKindOf(RUNTIME_CLASS(CFrameWnd));
}