#include <iostream>
using namespace std;

class MyString
{
public:
	MyString() // Конструктор по умолчанию.
	{
		pStr = nullptr;
		iLength = 0;
	}

	MyString(const char *pStr) // Конструктор с параметрами, при создании объекта класса в него можно передать строку, которую он будет хранить.
	{
		iLength = strlen(pStr); // Считываем длину строки.
		this->pStr = new char[iLength + 1]; // Выделяем динамическую память для указателя pStr с размером iLength + 1 (для добавления в конец строки нуль-терминатора).

		for (int i = 0; i < iLength; ++i)
		{
			this->pStr[i] = pStr[i]; // Каждый элемент полученного массива char'ов копируется в строку pStr, объявленную в классе.
		}

		this->pStr[iLength] = '\0'; // В конец строки добавляем нуль-терминатор.
	}

	MyString(const MyString& other) // Конструктор копирования. Необходим для создания точной копии объекта класса, но в другой области памяти.
	{
		iLength = strlen(other.pStr);
		this->pStr = new char[iLength + 1];

		for (int i = 0; i < iLength; ++i)
		{
			this->pStr[i] = other.pStr[i];
		}

		this->pStr[iLength] = '\0';
	}

	MyString(MyString &&other) // Конструктор перемещения.
	{
		this->iLength = other.iLength;
		this->pStr = other.pStr;

		other.pStr = nullptr;
	}

	MyString& operator = (const MyString &other) // Перегрузили оператор присваивания.
	{
		if (this->pStr != nullptr)
		{
			delete[] this->pStr;
		}

		iLength = strlen(other.pStr); 
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

		NewStr.iLength = strlen(this->pStr) + strlen(other.pStr);

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

		return NewStr; // Возвращаем результат конкатенации строк.
	}

	bool operator == (const MyString &other) // Перегрузили оператор равенства.
	{
		if (this->iLength != other.iLength) // Если размеры строк не совпадают, то они не равны, тем самым возвращаем false.
			return false;

		for (int i = 0; i < this->iLength; ++i) // Проходимся поэлементо по строкам, если имеется несовпадение - возвращаем false.
		{
			if (this->pStr[i] != other.pStr[i])
				return false;
		}

		return true; // Если выше не сработал return false, значит, строки равны, тогда возвращаем true.

	}

	bool operator != (const MyString &other) // Перегрузили оператор неравенства.
	{
		return !(this->operator==(other));
	}

	char & operator [] (int iIndex) // Перегрузили оператор индексирования.
	{
		return this->pStr[iIndex];
	}

	friend std::ostream& operator << (std::ostream &out, const MyString &string); // Создаем дружественную функцию (перегрузку оператора вывода).

	friend std::istream& operator >> (std::istream &in, MyString &string); // Опять же через дружественную функцию реализуем перегрузку оператора ввода.

	~MyString()
	{
		delete[] this->pStr; // После выхода из области действия функции, в которой был создан объект класса, с помощью деструктора очищаем динамическую память, выделенную под массив pStr.
	}

	int Length() // Метод, возвращающий длину строки.
	{
		return iLength;
	}

private:
	char *pStr; // Создаем указатель на массив char, хранит символы, которые мы передаем в наш объект.
	int iLength;
};

std::ostream& operator << (std::ostream &out, const MyString &string) // Реализация дружественной функции (перегрузки оператора вывода).
{
	out << string.pStr;

	return out;
}

std::istream& operator >> (std::istream &in, MyString &string) // Реализация дружественной функции (перегрузки оператора ввода).
{
	in >> string.pStr;

	string.iLength = strlen(string.pStr);

	return in;
}

int main()
{
	MyString str = "Hello";
	MyString str2 = "World";

	cout << str << "\n";

	cin >> str;

	cout << str << "\n";

	MyString result;

	result = str + str2;

	cout << result << "\n";

	return 0;
}
