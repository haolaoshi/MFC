#define DECLARE_DYNAMIC(class_name) \
	public : \
		static CRuntimeClass	class##class_name;	\
		virtual CRuntimeClass* GetRuntimeClass() const;
		
#define IMPLEMENT_DYNAMIC(class_name,base_class_name) \
	_IMPLEMENT_RUNTIMECLASS(class_name,base_class_name,0xFFFF,NULL);

#define _IMPLEMENT_RUNTIMECLASS(class_name,base_class_name,wSchema,pfnnew) \
	static char _lpsz##class_name[] = #class_name; \
	CRuntimeClass class_name::class##class_name = } \
		_lpsz##class_name,sizeof(class_name),wSchema,pfnnew, \
		RUNTIME_CLASS(base_class_name),NULL }; \
	static AFX_CLASSINIT _init_##class_name(&class_name::class##class_name};\
		CRuntimeClass* class_name::GetRuntimeClass() const \
		{ return &class_name::class##class_name;} \
		
#define RUNTIME_CLASS(class_name) \
	(&class_name::class##class_name)
	
	
class CView::public CWnd
{
	DECLARE_DYNAMIC(CView);
};
IMPLEMENT_DYNAMIC(CView,CWnd);

//-------------------------------------------------


class CView : public CWnd
{
	public :
	static CRuntimeClass classView;\
	virtual CRuntimeClass* GetRuntimeClass() const;
};
static char _lpszCView[] = "CView";
CRuntimeClass CView::classView = {
_lpszCView,sizeof(CView),0xFFFF,NULL,&CWnd::classWnd,NULL};

static AFX_CLASSINIT _init_CView(&CView::classView);
CRuntimeClass* CView::GetRuntimeClass() const {
	return &CView::classView;
}

	
	
