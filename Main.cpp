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
		int iLength = strlen(pStr); // Считываем длину строки.
		this->pStr = new char[iLength + 1]; // Выделяем динамическую память для указателя pStr с размером iLength + 1 (для добавления в конец строки нуль-терминатора).

		for (int i = 0; i < iLength; ++i)
		{
			this->pStr[i] = pStr[i]; // Каждый элемент полученного массива char'ов копируется в строку pStr, объявленную в классе.
		}

		this->pStr[iLength] = '\0'; // В конец строки добавляем нуль-терминатор.
	}

	MyString& operator = (const MyString &other) // Перегрузили оператор присваивания.
	{
		if (this->pStr != nullptr)
		{
			delete[] this->pStr;
		}

		int iLength = strlen(other.pStr); 
		this->pStr = new char[iLength + 1]; 

		for (int i = 0; i < iLength; ++i)
		{
			this->pStr[i] = other.pStr[i]; 
		}

		this->pStr[iLength] = '\0'; 

		return *this;
	}

	MyString operator + (const MyString &other) // Реализовали перегрузку оператора сложения.
	{
		MyString NewStr;

		NewStr.pStr = new char[strlen(this->pStr) + strlen(other.pStr) + 1];

		int i = 0;

		for (; i < strlen(this->pStr); ++i)
		{
			NewStr.pStr[i] = this->pStr[i];
		}

		for (int j = 0; j < strlen(other.pStr); ++j, ++i)
		{
			NewStr.pStr[i] = other.pStr[j];
		}

		NewStr.pStr[strlen(this->pStr) + strlen(other.pStr)] = '\0';

		return NewStr;
	}

	~MyString()
	{
		delete[] this->pStr; // После выхода из области действия функции, в которой был создан объект класса, с помощью деструктора очищаем динамическую память, выделенную под массив pStr.
	}
private:
	char *pStr; // Создаем указатель на char для принятия строки с произвольной длиной.
};


int main()
{
	MyString str = "Hello";
	MyString str2 = "World";

	MyString result = str + str2;

	return 0;
}
