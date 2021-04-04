#include <iostream>
#include <windows.h>

using namespace std;


class CObject
{
	public :
	  CObject::CObject(){cout<<"CObject Constructor \n";}
	  CObject::~CObject(){cout<<"CObject Destructor \n";}
};

class CCmdTrarget : public CObject
{
	public:
	  CCmdTrarget::CCmdTrarget(){cout<<"CCmdTrarget Constructor\n";}
	  CCmdTrarget::~CCmdTrarget(){cout<<"CCmdTrarget Destructor\n";}
};

class CWinThread : public CCmdTrarget
{
	public:
	  CWinThread::CWinThread(){cout<<"CWinThread Constructor\n";}
	  CWinThread::~CWinThread(){cout<<"CWinThread Destructor\n";}
	  
	  virtual BOOL InitInstance(){
		  cout<<"virtual CWinThread :: InitInstance\n";
		  return TRUE;
	  }
	  
	  virtual int Run(){
		  cout<<"virtual CWinThread :: Run\n";
		  return 1;
	  }
	  
};
class CWnd ;

class CWinApp : public CWinThread
{
	public:
	  CWinApp * m_pCurrentWinApp;
	  CWnd *		m_pMainWnd;
	  
	public:
	
	  CWinApp::CWinApp(){m_pCurrentWinApp = this; cout<<"this="<<this<<endl;}
	  CWinApp::~CWinApp(){cout<<"Destructor CWinApp\n";}
	  
	  virtual BOOL InitInstance(){
		  cout<< "virtual CWinApp InitInstance ******** virtual \n";
		  return TRUE;
	  }
	  
	  virtual int Run(){
		  cout<< "virtual CWin Running ++++++ virtual \n";
		   return CWinThread::Run();
	  }
	  
	  virtual BOOL InitApplication(){
		  cout<<"virtual InitApplication CWinApp $$$$$$$$ 基类指针指向子类对象，调用的是继承的虚函数 \n";
		 return TRUE;
	  }
};

class CDocument : public CCmdTrarget
{
	public:
	  CDocument::CDocument(){cout<<"Construct CDocument\n";}
	  CDocument::~CDocument(){cout<<"Destructor CDocument\n";}
};

class CWnd : public CCmdTrarget
{
	public :
	  CWnd::CWnd(){cout<<"Construct CWnd\n";}
	  CWnd::~CWnd(){cout<<"Destructor CWnd\n";}
	  
	  virtual BOOL Create();
	  BOOL CreateEx();
	  virtual BOOL PreCreateWindow();
};

class CFrameWnd: public CWnd
{
	public:
	  CFrameWnd::CFrameWnd(){cout<<"CFrameWnd Constructor\n";}
	  CFrameWnd::~CFrameWnd(){cout<<"CFrameWnd Destructor\n";}
	  BOOL Create();
	  virtual BOOL PreCreateWindow();
};

class CView : public CWnd
{
	public :
	  CView::CView(){cout<<"Construct CView\n";}
	  CView::~CView(){cout<<"Destructor CView\n";}
};

CWinApp* AfxGetApp();

