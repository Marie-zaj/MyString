#pragma once
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
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
	MyString operator+(char c) const; //obj + 'A'
	MyString operator+(int n) const;//obj + 10
	MyString& operator+=(const MyString& b);
	MyString& operator++(); //++ob
	MyString operator++(int); //ob++

	char& operator[](int index);
	const char& operator[](int index) const;
	void operator()();

	int GetLength() const;
	const char* GetStr() const;
	static int GetCount();
};
MyString operator+(char c, const MyString& obj);//'A' + obj
MyString operator+ (int n, const MyString& obj);//10 + obj

ostream& operator<<(ostream& out, const MyString& obj);
istream& operator>>(istream& in, MyString& obj);