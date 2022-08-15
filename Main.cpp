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
		int iLength = strlen(pStr); // ��������� ����� ������.
		this->pStr = new char[iLength + 1]; // �������� ������������ ������ ��� ��������� pStr � �������� iLength + 1 (��� ���������� � ����� ������ ����-�����������).

		for (int i = 0; i < iLength; ++i)
		{
			this->pStr[i] = pStr[i]; // ������ ������� ����������� ������� char'�� ���������� � ������ pStr, ����������� � ������.
		}

		this->pStr[iLength] = '\0'; // � ����� ������ ��������� ����-����������.
	}

	MyString& operator = (const MyString &other)
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

	~MyString()
	{
		delete[] this->pStr; // ����� ������ �� ������� �������� �������, � ������� ��� ������ ������ ������, � ������� ����������� ������� ������������ ������, ���������� ��� ������ pStr.
	}
private:
	char *pStr; // ������� ��������� �� char ��� �������� ������ � ������������ ������.
};


int main()
{
	MyString str;

	

	return 0;
}