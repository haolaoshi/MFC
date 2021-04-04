#include <stdio.h>

class CSquare
{
private:
	int m_color;
public:
   CSquare(){printf("Create a Square\n");}
   ~CSquare(){printf("DEstroy a Square\n");}
   
	void display(){printf("display\n");}
};

int main()
{
	CSquare* c = new CSquare();
	c->display();
	delete(c);
	return 0;
}