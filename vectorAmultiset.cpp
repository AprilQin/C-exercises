#include <iostream>
#include <vector>
#include <memory> 
#include <set>
#include <map>
#include <algorithm> //std::set_union
#include <iterator>

using namespace std;

class Base 
{
public:
	~Base() 
	{
		cout << "kill Base class\n";
	}
	int data;
	virtual void whoAreYou()
	{
		cout << "This class is 'base' \n";
	}
};

class Sub : public Base
{
public:
	~Sub()
	{
		cout << "kill Sub class\n";
	}
	virtual void whoAreYou()
	{
		cout << "This class is 'Sub' \n";
	}
};

int main() {
	// exercise 1 & 2
	//
	{
		auto_ptr< vector<Base*> > v(new vector<Base*>);
		Base b1, b2;
		Sub s1, s2;
		v->push_back(&b1);
		v->push_back(&b2);
		v->push_back(&s1);
		v->push_back(&s2);
		//
		//Accessing vector elements:
		//method 1:
		for (int i = 0; i < v->size(); ++i)
		{
			//dereference first, we get a vector of base class pointers
			//access each pointer, then call functions of the objects
			//stored at the address pointed by the pointers with -> operator
			(*v)[i]->whoAreYou();
		}
		//method 2:
		for (vector<Base*>::iterator it = (*v).begin(); it != (*v).end(); ++it)
		{
			(*it)->whoAreYou();
		}

	}

	//exercise 3
	//
	multiset<float> set1;
	set1.insert(0.1);
	set1.insert(0.2);
	set1.insert(0.3);
	set1.insert(0.2);
	set1.insert(0.1);
	map<float, int> mymap;
	for (multiset<float>::iterator itr = set1.begin(); itr != set1.end(); ++itr)
	{
		mymap[ *itr ] = 0;
	}
	for (multiset<float>::iterator itr = set1.begin(); itr != set1.end(); ++itr)
	{
		mymap[*itr] ++;
	}

	//exercise 4
	//
	set<int> odd = {3,1,7,5,9};
	set<int> even = { 2,4,6,8,10};
	set<int> resultSet;
	set_union(odd.begin(), odd.end(), even.begin(), even.end(), inserter(resultSet, resultSet.begin()));
	for (set<int>::iterator it = resultSet.begin(); it != resultSet.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << "\n";

	cin.ignore();
}