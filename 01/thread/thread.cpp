#include <windows.h>
#include <process.h>
#include <stdio.h>
unsigned __stdcall myfunc(void* p);

void main()
{
	unsigned long thd;
	unsigned tid;
	
	thd = _beginthreadex(NULL,
		0,
		myfunc,
		0,
		0,
		&tid);
	if(thd != NULL)
	{
		printf("Create Failed\n");
		CloseHandle(reinterpret_cast<HANDLE*>(thd));
	}
	if(tid != NULL)
	{
		printf("thread id =%d\n",tid);
	}
}

unsigned __stdcall myfunc(void* p)
{
	printf("Hello World!\n");
	return 0;
}