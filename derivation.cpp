#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Base 
{
public:
	int x = 0;

protected:
	int y = 2;

private:
	int z = 4;
};


class DerviedPublic : public Base {

public:
	//x is public

	//y is protected, need a getter
	int getY() { return y; }

	//z inaccessible
};

class DerivedProtected:protected Base {
	
public:
	//x is protected
	int getX() { return x; }

	//y is protected
	int getY() { return y; }

	//z inaccessible
};

class DerivedPrivate : private Base {
public:
	// x is private
	int getX()
	{
		return x;
	}
	
	// y is private
	int getY()
	{
		return y;
	}

	// z inaccessible
};

class Bottom : public DerivedPrivate {
	//x, y, z are all inaccessible because
	//they are private members of its parent class
};


class LoggingMixin 
{ 
protected:
	void logMyself()
	{
		time_t now = time(0);
		cout << WhatIsMyName() <<  now <<"\n";
	}
	virtual string WhatIsMyName() = 0; 
};

class Sub1 : public LoggingMixin
{
public:
	Sub1()
	{
		logMyself();
	}

	string WhatIsMyName()
	{
		return "My name is Sub1 - time:" ;
	}
};

class Sub2 : public LoggingMixin
{
public:
	Sub2()
	{
		logMyself();
	}
	string WhatIsMyName()
	{
		return "My name is Sub2 - time:";
	}
};

int main() {
	cout << "hello\n";
	
	Base base;
	DerviedPublic derivedpublic;
	DerivedProtected derivedprotected;
	DerivedProtected derivedPrivate;
	Bottom bottom;

	cout << "client code can access public inheritance public data. Public data ="<<derivedpublic.x<< "\n";
	
	cout << "protected inheritance makes public become protected members" <<
		"of the derived class, so client code can't access: derivedprotected.x;\n";

	cout << derivedprotected.getX();
	cout << derivedprotected.getY();
	cout << derivedPrivate.getX();
	cout << derivedPrivate.getY();

	Sub1 s1;
	Sub2 s2;
	
	cin.ignore();
	return 0;
}