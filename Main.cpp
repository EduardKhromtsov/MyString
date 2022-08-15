#include <iostream>
using namespace std;

class MyString
{
public:
	MyString()
	{
		pStr = nullptr;
	}

	MyString(char *pStr)
	{
		int iLength = strlen(pStr);
		this->pStr = pStr;
	}

	~MyString()
	{

	}
private:
	char *pStr;
};


int main()
{


	return 0;
}