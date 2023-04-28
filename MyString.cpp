#include "MyString.h"

MyString::MyString() : pStr(nullptr), length(0)
{
}

MyString::MyString(const char* str) : pStr(new char[std::strlen(str) + 1]), length(std::strlen(str))
{
	for (int i = 0; i < length; ++i)
		pStr[i] = str[i];

	pStr[length] = '\0';
}

MyString::MyString(const MyString& other) : pStr(new char[std::strlen(other.pStr) + 1]), length(std::strlen(other.pStr))
{
	for (int i = 0; i < length; ++i)
		pStr[i] = other.pStr[i];

	pStr[length] = '\0';
}

MyString::MyString(MyString&& other) : pStr(other.pStr), length(other.length)
{
	other.pStr = nullptr;
}

MyString::~MyString()
{
	delete[] pStr;
}

const MyString& MyString::operator=(const MyString& other)
{
	if (this == &other)
		return *this;

	delete[] pStr;

	length = std::strlen(other.pStr);
	
	pStr = new char[length + 1];

	for (int i = 0; i < length; ++i)
		pStr[i] = other.pStr[i];

	pStr[length] = '\0';

	return *this;
}

const MyString& MyString::operator=(MyString&& other)
{
	if (this == &other)
		return *this;

	delete[] pStr;

	pStr = other.pStr;
	length = other.length;

	other.pStr = nullptr;
}

MyString MyString::operator+(const MyString& other) const
{
	MyString newStr;

	newStr.length = std::strlen(pStr) + std::strlen(other.pStr);

	newStr.pStr = new char[std::strlen(pStr) + std::strlen(other.pStr) + 1];

	int i = 0;

	for (; i < std::strlen(pStr); ++i)
		newStr.pStr[i] = pStr[i];

	for (int j = 0; j < std::strlen(other.pStr); ++j, ++i)
		newStr.pStr[i] = other.pStr[j];

	newStr.pStr[std::strlen(pStr) + std::strlen(other.pStr)] = '\0';

	return newStr;
}

bool MyString::operator==(const MyString& other) const
{
	if (length != other.length)
		return false;

	for (int i = 0; i < length; ++i)
		if (pStr[i] != other.pStr[i])
			return false;

	return true;
}

bool MyString::operator!=(const MyString& other) const
{
	return !(operator==(other));
}

char& MyString::operator[](const int index)
{
	return pStr[index];
}

const char& MyString::operator[](const int index) const
{
	return pStr[index];
}

int MyString::size() const
{
	return length;
}

std::ostream& operator<<(std::ostream& out, const MyString& str)
{
	out << str.pStr;

	return out;
}

