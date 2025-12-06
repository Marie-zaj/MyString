#pragma once
#include <iostream>
#include <cstring>
#include <string>
class MyString
{
	char* str;
	int length;
	static int countObjects;

public:
	MyString();
	MyString(int size);
	MyString(const char* s);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	~MyString();

	void Input();
	void Output() const;

	void MyStrcpy(const MyString& obj);
	bool MyStrStr(const char* sub) const;
	int  MyChr(char c) const;
	int  MyStrLen() const;
	void MyStrCat(const MyString& b);
	void MyDelChr(char c);
	int  MyStrCmp(const MyString& b) const;

	MyString operator+(const MyString& b) const;
	MyString& operator+=(const MyString& b);
	char& operator[](int index);
	const char& operator[](int index) const;

	static int GetCount();
};

