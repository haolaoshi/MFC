#include <typeinfo.h>
#include <iostream>
#include <string.h>

using namespace std;

class graphicImage
{
	protected:
	char name[10];
	
	public:
	graphicImage()
	{
		strcpy(name,"graphicImage");
	}
	
	virtual void display()
	{
		cout <<"Display a generic image."<<endl;
	}
	
	char* getName()
	{
		return name;
	}
};

class GIFimage : public graphicImage
{
	public :
	GIFimage()
	{
		strcpy(name,"GIFimage");
	}
	
	void display()
	{
		cout<<"Display a GIF file."<<endl;
	}
};

class CTimage : public graphicImage
{
	public :
	CTimage()
	{
		strcpy(name,"CTimage");
	}
	void display()
	{
		cout<< "Display a CT fILE"<<endl;
	}
};
void processFile(graphicImage *type)
{
	if(typeid(GIFimage) == typeid(*type))
	{
		((GIFimage*)type)->display();
	}
	else if(typeid(CTimage) == typeid(*type))
	{
		((CTimage*)type)->display();
	}
	else
		cout<<"Unknown type !"<<(typeid(*type)).name() <<endl;
}

void main()
{
	graphicImage *gImage = new GIFimage();
	graphicImage *cImage = new CTimage();
	
	processFile(gImage);
	processFile(cImage);
}
