#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class MyString
{
private:
	char* pStr;
	int length;

public:
	MyString();

	MyString(const char* str);

	MyString(const MyString& other);

	MyString(MyString&& other);

	~MyString();

	const MyString& operator=(const MyString& other);

	const MyString& operator=(MyString&& other);

	MyString operator+(const MyString& other) const;

	bool operator==(const MyString& other) const;

	bool operator!=(const MyString& other) const;

	char& operator[](const int index);

	const char& operator[](const int index) const;

	int size() const;

	friend std::ostream& operator<<(std::ostream& out, const MyString& str);
};

std::ostream& operator<<(std::ostream& out, const MyString& str);

#endif 
