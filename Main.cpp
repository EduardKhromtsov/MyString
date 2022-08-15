#include <iostream>
using namespace std;

class MyString
{
public:
	MyString()
	{
		pStr = nullptr;
	}

	MyString(const char *pStr)
	{
		int iLength = strlen(pStr); // —читываем длину строки.
		this->pStr = new char[iLength + 1]; // ¬ыдел€ем динамическую пам€ть дл€ указател€ pStr с размером iLength + 1 (дл€ добавлени€ в конец строки нуль-терминатора).

		for (int i = 0; i < iLength; ++i)
		{
			this->pStr[i] = pStr[i]; //  аждый элемент полученного массива char'ов копируетс€ в строку pStr, объ€вленную в классе.
		}

		this->pStr[iLength] = '\0'; // ¬ конец строки добавл€ем нуль-терминатор.
	}

	~MyString()
	{

	}
private:
	char *pStr; // —оздаем указатель на char дл€ прин€ти€ строки с произвольной длиной.
};


int main()
{
	MyString a("test");

	return 0;
}