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

	cout << "\nTesting MyStcpy():\n";
	MyString src("CopiedText");
	MyString dest;
	dest.MyStrcpy(src);
	cout << "Source: ";
	src.Output();
	cout << "\nDestination after MyStrcpy: ";
	dest.Output();

	cout << "\nTesting operator= :\n";
	MyString x("AssignMe");
	MyString y;
	y = x;
	cout << "y after assignment: ";
	y.Output();

	cout << "\nTesting operator():\n";
	MyString p;
	cout << "Enter new value for p: ";
	p();
	cout << "You entered: ";
	p.Output();
	
	cout << "\nTesting obj + 'A'\n";
	MyString s1("Test");
	MyString s2 = s1 + 'A';
	cout << "Test + 'A' = ";
	s2.Output();

	cout << "\nTesting 'A' + obj:\n";
	MyString s3 = 'A' + s1;
	cout << "'A' + Test = ";
	s3.Output();

	cout << "\nTesting obj + 10:\n";
	MyString s4 = s1 + 10;
	cout << "Test + 10 = ";
	s4.Output();

	cout << "\nTesting 10 + obj\n";
	MyString s5 = 10 + s1;
	cout << "10 + Test = ";
	s5.Output();

	cout << "\nTesting postfix obj++ append\n";
	MyString s6("Plus");
	s6++;
	cout << "After s6++: ";
	s6.Output();

	cout << "\nTesting prefix ++obj append\n";
	++s6;
	cout << "After ++s6: ";
	s6.Output();

	cout << "\nTesting operator << :\n";
	MyString t1("StreamTest");
	cout << t1 << endl;

	cout << "\nTesting operator >> :\n";
	MyString t2;
	cout << "Enter string: ";
	cin >> t2;
	cout << "You entered: " << t2 << endl;

	return 0;
}