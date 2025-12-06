#include "MyString.h"
using namespace std;

int MyString::countObjects = 0;

MyString::MyString()
{
	length = 80;
	str = new char[length + 1];
	str[0] = '\0';
	countObjects++;
}

MyString::MyString(int size)
{
	if (size < 1) size = 1;

	length = size;
	str = new char[length + 1];
	str[0] = '\0';
	countObjects++;
}

MyString::MyString(const char* s)
{
	if (!s)
	{
		length = 1;
		str = new char[2];
		str[0] = '\0';
		countObjects++;
		return;
	}
	int i = 0;
	while (s[i] != '\0') i++;
	length = i;
	str = new char[length + 1];

	for (int j = 0; j <= length; j++)
		str[j] = s[j];

	countObjects++;
}

MyString::MyString(const MyString& other)
{
	length = other.length;
	str = new char[length + 1];

	for (int i = 0; i <= length; i++)
		str[i] = other.str[i];

	countObjects++;
}

MyString& MyString::operator=(const MyString& other)
{
	if (this == &other) return *this;

	delete[] str;

	length = other.length;
	str = new char[length + 1];

	for (int i = 0; i <= length; i++)
		str[i] = other.str[i];
	return *this;
}

MyString::~MyString()
{
	delete[] str;
}

void MyString::Input()
{
	char buffer[1024];
	cin.getline(buffer, 1024);

	int i = 0;
	while (buffer[i] != '\0') i++;

	delete str;

	length = i;
	str = new char[length + 1];

	for(int j=0;j<=length;j++)
		str[j] = buffer[j];
}

void MyString::Output() const
{
	cout << str<<endl;
}

void MyString::MyStrcpy(const MyString& obj)
{
	delete[] str;

	length = obj.length;
	str = new char[length + 1];
	for (int i = 0; i <= length; i++)
		str[i] = obj.str[i];
}

bool MyString::MyStrStr(const char* sub) const
{
	if (!sub) return false;

	int i = 0;
	while (sub[i] != '\0') i++;
	int subLength = i;

	for (int i = 0; i <= length - subLength; i++)
	{
		bool match = true;
		for (int j = 0; j < subLength; j++)
		{
			if (str[i + j] != sub[j])
			{
				match = false;
				break;
			}
		}
		if (match) return true;
	}
	return false;
}

int MyString::MyChr(char c) const
{
	for (int i = 0; i < length; i++)
		if (str[i] == c)
			return i;

	return -1;
}

int MyString::MyStrLen() const
{
	return length;
}

void MyString::MyStrCat(const MyString& b)
{
	int newLen = length + b.length;
	char* newStr = new char[newLen + 1];

	for (int i = 0; i < length; i++)
		newStr[i] = str[i];

	for (int i = 0;i<=b.length;i++)
		newStr[length+i] = b.str[i];

	delete[] str;
	str = newStr;
	length = newLen;
}

void MyString::MyDelChr(char c)
{
	int newLen = 0;

	for (int i = 0; i < length; i++)
		if (str[i] != c)
			newLen++;

	char* newStr = new char[newLen + 1];
	int pos = 0;

	for (int i = 0; i < length; i++)
		if (str[i] != c)
			newStr[pos++] = str[i];

	newStr[pos] = '\0';

	delete[] str;
	str = newStr;
	length = newLen;
}

int MyString::MyStrCmp(const MyString& b) const
{
	if (length < b.length) return -1;
	if (length > b.length) return 1;
	return 0;
}

MyString MyString::operator+(const MyString& b) const
{
	MyString result(length + b.length);

	for (int i = 0; i < length; i++)
		result.str[i] = str[i];

	for (int i = 0; i <= b.length; i++)
		result.str[length+i] = b.str[i];

	return result;
}

MyString& MyString::operator+=(const MyString& b)
{
	MyStrCat(b);
	return *this;
}

char& MyString::operator[](int index)
{
	return str[index];
}

const char& MyString::operator[](int index) const
{
	return str[index];
}

int MyString::GetCount()
{
	return countObjects;
}
