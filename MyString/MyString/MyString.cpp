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

MyString MyString::operator+(char c) const
{
	MyString result(length + 1);
	for (int i = 0; i < length; i++)
		result.str[i] = str[i];

	result.str[length] = c;
	result.str[length+1] = '\0';

	return result;
}

MyString MyString::operator+(int n) const
{
	if (n < 1) n = 1;

	MyString result(length +n);

	for (int i = 0; i < length; i++)
		result.str[i] = str[i];

	for (int i = 0; i < n; i++)
		result.str[length+i] = '?';

	result.str[length + n] = '\0';
	return result;
}

MyString& MyString::operator+=(const MyString& b)
{
	MyStrCat(b);
	return *this;
}

MyString& MyString::operator++()
{
	char add = '.';
	char* newStr = new char[length + 2];
	newStr[0] = add;

	for (int i = 0; i <= length; i++)
		newStr[i + 1] = str[i];

	delete[] str;
	str = newStr;
	length++;

	return *this;
}

MyString MyString::operator++(int)
{
	MyString temp(*this);
	char add = '.';
	char* newStr = new char[length + 2];

	for (int i = 0; i < length; i++)
		newStr[i] = str[i];

	newStr[length] = add;
	newStr[length+ 1] = '\0';

	delete[] str;
	str = newStr;
	length++;

	return temp;
}

char& MyString::operator[](int index)
{
	return str[index];
}

const char& MyString::operator[](int index) const
{
	return str[index];
}

void MyString::operator()()
{
	Input();
}

int MyString::GetLength() const
{
	return length;
}

const char* MyString::GetStr() const
{
	return str;
}

int MyString::GetCount()
{
	return countObjects;
}

MyString operator+(char c, const MyString& obj)
{
	int len = obj.GetLength();
	MyString result(len + 1);

	result[0] = c;

	for (int i = 0; i <= len; i++)
		result[i + 1] = obj.GetStr()[i];

	return result;
}

MyString operator+(int n, const MyString& obj)
{
	if (n < 1) n = 1;

	int len = obj.GetLength();
	MyString result(len + n);

	for (int i = 0; i < n; i++)
		result[i] = '.';
	for (int i = 0; i <= len; i++)
		result[n + i] = obj.GetStr()[i];

	return result;
}

ostream& operator<<(ostream& out, const MyString& obj)
{
	out << obj.GetStr();
	return out;
}

istream& operator>>(istream& in, MyString& obj)
{
	char buffer[1024];
	in.getline(buffer, 1024);

	obj = MyString(buffer);

	return in;
}
