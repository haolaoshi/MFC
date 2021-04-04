#include <iostream>
#include "mfc.h"
 

class CMyWinApp : public CWinApp
{
public:
	CMyWinApp::CMyWinApp() { cout << " [05] CMyWinApp Constructor. " << endl; }
	CMyWinApp::~CMyWinApp() { cout << "[5->4] CMyWinApp Destroctor. " << endl; }
	
	
};

class CMyFrameWnd : public CFrameWnd
{
public:
		CMyFrameWnd::CMyFrameWnd() { cout << " CMyFrameWnd construct." << endl;}
		CMyFrameWnd::~CMyFrameWnd() { cout << " CMyFrameWnd Destroctor , " << endl; }
	
};