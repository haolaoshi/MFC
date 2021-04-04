#include <iostream>
#include "mfc.h"

using namespace std;


class CMyWinApp : public CWinApp
{
	public:
	  CMyWinApp::CMyWinApp(){cout<<"CMyWinApp Constructor\n";}
	  CMyWinApp::~CMyWinApp(){cout<<"CMyWinApp Destructor\n";}
	  virtual BOOL InitInstance();
};

class CMFrameWnd : public CFrameWnd
{
	public :
	  CMFrameWnd::CMFrameWnd();
	  CMFrameWnd::~CMFrameWnd(){cout<<"CMFrameWnd Destructor\n";}
};
