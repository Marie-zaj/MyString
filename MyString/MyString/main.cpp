#include "MyString.h"
#include <iostream>
using namespace std;

int main()
{
	MyString a;
	a.Input();
	cout << "String a: ";
	a.Output();

	MyString b(20);
	b.Input();
	cout << "String b: ";
	b.Output();

	MyString c("Hello");
	cout << "String c: ";
	c.Output();

	MyString d = c;
	cout << "Copied string d: ";
	d.Output();

	cout << "Concatenate c += b\n";
	c += b;
	c.Output();

	MyString e = a + d;
	cout << "String e = a + d: ";
	e.Output();

	cout << "Searching for \"lo\" inside d: ";
	cout << (d.MyStrStr("lo") ? "FOUND\n" : "NOT FOUND\n");

	cout << "Searching for 'e' in c: index = " << c.MyChr('e') << endl;

	cout << "Deleting 'l' from d...\n";
	d.MyDelChr('l');
	d.Output();

	cout << "Comparing a and b: result = " << a.MyStrCmp(b) << endl;

	cout << "c[0] before: " << c[0] << endl;
	c[0] = 'X';
	cout << "c[0] after: " << c[0] << endl;

	cout << "\n\nTesting MyStrcpy():\n";
	MyString src("CopiedText");
	MyString dest;
	dest.MyStrcpy(src);
	cout << "Source: ";
	src.Output();
	cout << "\nDestination after MyStrcpy: ";
	dest.Output();
	cout << endl;

	cout << "\nTesting operator= :\n";
	MyString x("AssignMe");
	MyString y;
	y = x;  // operator= is called here
	cout << "y after assignment: ";
	y.Output();
	cout << endl;

	cout << "\nTotal created objects: "
		<< MyString::GetCount()
		<< endl;

	return 0;
}