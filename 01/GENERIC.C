/**
1，程序初始化过程中调用CreateWindow
窗口产生后送出WM_CREATE 给窗口函数，作初始化操作
2，程序循环使用GetMessage从消息队列 中抓取消息
如果收到WM_QUIT，GetMessage返回0线束循环；
3，DispatchMessage 利用USER模块协助把消息分发给窗口函数
4，程序在2-3循环
5，当用户按下Close指令时，系统送出WM_CLOSE
通常窗口函数不拦截，由DefWindowProc处理
6，DefWindowProc收到后调用DestroyWindow把窗口清除
此时送出WM_DESTROY
7，程序对WM_DESTROY的反应是调用PostQuitMessage
8，PostQuitMessage只送出WM_QUIT消息，被GetMessage获得
程序结束；




**/
#include <windows.h>
#include "resource.h"    //各个IDs
#include "generic.h"  	  	

HINSTANCE _hInst;
HWND 	_hWnd;

char _szAppName[] = "Generic";
char _szTitle[] = "Generic Sample Application";

/**程序入口**/
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance,
	LPSTR lpCmdLine, int nCmdShow)
	{
		MSG msg;
		UNREFERENCED_PARAMETER(lpCmdLine);
		
		if(!hPreInstance)
			if(!InitApplication(hInstance)) /*1 注册窗口类 RegisterClass*/
				return (FALSE);
		if(!InitInstance(hInstance,nCmdShow))/*2 产生窗口 CreateWindow*/
			return (FALSE);
		
		while(GetMessage(&msg,NULL,0,0)){
			TranslateMessage(&msg);//翻译消息
			DispatchMessage(&msg);//分发消息
		}
		return (msg.wParam);//传回PostQuitMessage的参数
	}
	
	
/**1 注册窗口类 RegisterClass**/
BOOL InitApplication(HINSTANCE hInstance)
{
	WNDCLASS wc;
	
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WndProc;//3 窗口函数
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(hInstance,"jjhicon");
	wc.hCursor = LoadCursor(NULL,IDC_ARROW);
	wc.hbrBackground = GetStockObject(WHITE_BRUSH);//窗口后台颜色
	wc.lpszMenuName = "GenericMenu";
	wc.lpszClassName = _szAppName;
	
	return (RegisterClass(&wc));
	
}
/**2 产生窗口 CreateWindow**/
BOOL InitInstance(HINSTANCE hInstance,int nCmdShow)
{
	_hInst = hInstance;
	_hWnd = CreateWindow(
		_szAppName,
		_szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL
		);
	if(!_hWnd)
		return (FALSE);
	
	ShowWindow(_hWnd,nCmdShow);//显示 窗口
	UpdateWindow(_hWnd); // 发送WM_PAINT
	return (TRUE);
	
}
/**3 窗口函数 **/
LRESULT CALLBACK WndProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	int wmId,wmEvent;
	switch(message){
		case WM_COMMAND:
			wmId = LOWORD(wParam);
			wmEvent = HIWORD(wParam);
			switch(wmId){
				case IDM_ABOUT:
					DialogBox(_hInst,
							"AboutBox", //对话框资源名
							hWnd,	//父窗口
							(DLGPROC)About  //对话框函数
							);
					break;
				case IDM_EXIT://想结束 函数 与WM_CLOSE相同
					DestroyWindow(hWnd);
					break;
				default:
					return (DefWindowProc(hWnd,message,wParam,lParam));
			}
			break;
		case WM_DESTROY://窗口已经被销毁，程序即将结束 
			//PostQuitMessage(0);
			break;
		default://Window默认的消息处理函数 
			return (DefWindowProc(hWnd,message,wParam,lParam));
	}
	return (0);
}
/**对话框函数**/
LRESULT CALLBACK About(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch(message){
		case WM_INITDIALOG:
			return (TRUE);
		case WM_COMMAND:
			if(LOWORD(wParam) == IDOK
				|| LOWORD(wParam) == IDCANCEL) {
				EndDialog(hDlg,TRUE);
				return (TRUE);//表示 已经处理过这个消息
			}
			break;
	}
	return (FALSE); //表示 我没有处理这个消息
}