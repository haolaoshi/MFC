#include <iostream>

using namespace std;

class CObject
{
public:
	CObject::CObject() {	cout<< "[01] CObject Constructor."<<endl; }
	CObject::~CObject() {  cout<< "[1-0] CObject Destructor."<<endl; }
};

class CCmdTarget : public CObject
{
public:
	CCmdTarget::CCmdTarget() { cout << "[02] CCmdTarget construct."<< endl; }
	CCmdTarget::~CCmdTarget() { cout << "[2->1] CCmdTarget Destructor. " << endl; }
	
};

class CWinThread : public CCmdTarget
{
public:
	CWinThread::CWinThread() { cout << " [03] CWinThread Constructor." << endl; }
	CWinThread::~CWinThread() { cout << "[3->2] CWinThread Destructor ." << endl; }
	
};

class CWinApp : public CWinThread
{
public :
	CWinApp* m_pCurrentWinApp;
	
public:
	CWinApp::CWinApp() { 
		m_pCurrentWinApp = this;
		cout << "[04]  Constructor.[m_pCurrentWinApp = this;]" << endl; 
	}
	CWinApp::~CWinApp() { cout << "[4->3] CWinApp Destructor ." << endl; }
};

class CDocument : public CCmdTarget
{
public:
	CDocument::CDocument() { cout << "CDocument Constructor. " << endl; }
	CDocument::~CDocument() { cout << " CDocument Destructor ." << endl; }
	
};

class CWnd : public CCmdTarget
{
public:
	CWnd::CWnd() { cout << " CWnd constructor . " << endl; }
	CWnd::~CWnd() { cout << " CWnd Destructor . " << endl; }
	
};

class CFrameWnd : public CWnd
{
public:
	CFrameWnd :: CFrameWnd() { cout<< " CFrameWnd Constructor . " << endl; }
	CFrameWnd :: ~CFrameWnd() { cout << "CFrameWnd Destructor . " << endl; }
	
};

class CView : public CWnd
{
public:
	CView::CView() { cout << " CView Constructor." << endl; }
	CView::~CView() { cout << " CView Destructor . " << endl; }
};

CWinApp  *AfxGetApp();
