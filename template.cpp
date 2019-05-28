#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

template <typename T>
void printVector(vector<T> arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "finished sort\n";
}


template <typename T>
class normalLessThan 
{
	public:
		bool operator() (T i, T j)
		{ 
			return ( i < j); 
		} 
};


template <typename T>
class absLessThan 
{
	public:
		bool operator() (T i, T j)
		{
			return (abs(i) < abs(j));
		}
};


int main()
{
	cout << "hello module 14\n";
	
	//exercise 1
	vector<int> arrInt = {9, 16, -15};
	vector<float> arrFloat = { 3.3, 1.1, -2.2 };
	///
	///absolute value sort
	//
	sort(arrInt.begin(), arrInt.end(), absLessThan<int>());
	printVector<int>(arrInt, 3);
	//
	sort(arrFloat.begin(), arrFloat.end(), absLessThan<int>());
	printVector<float>(arrFloat, arrFloat.size());
	///
	///normal sort
	//
	sort(arrInt.begin(), arrInt.end(), normalLessThan<int>());
	printVector<int>(arrInt, arrInt.size());
	//
	sort(arrFloat.begin(), arrFloat.end(), normalLessThan<int>());
	printVector<float>(arrFloat, arrFloat.size());
	///
	///test the compare class as a functor object
	normalLessThan<int> n;
	if (n(3, 5) && !n(5, 3))
	{
		cout << "testing normal compare class as an object - pass\n";
	}
	absLessThan<int> j;
	if ( !j(3, -2) && j(3, -5))
	{
		cout << "testing absolute compare class as an object- pass\n";
	}

	//exercise 2
	std::vector<int>::iterator low = lower_bound(arrInt.begin(), arrInt.end(), 16);
	cout << "lower bound = " << *low << "\n";

	if (binary_search(arrInt.begin(), arrInt.end(), 16))
	{
		cout << "16 is found\n";
	}
	
	//exercise 3
	cout << "enter a string plz:\n";
	string s;
	cin >> s;
	cout << "length of your entered string is: " << s.length() << "\n";
	for (int i = 0; i < s.length(); ++i)
	{
		cout << " index " << i << " : " << s.at(i) << "\n";
		s.at(i) = toupper(s.at(i));	
	}
	///print in reverse order
	for (string::reverse_iterator it = s.rbegin(); it != s.rend(); ++it) {
		cout << " index " << " : " << *it << "\n";
	}
	///shrink to fit
	string r(100, 'a');
	cout << "string s's capacity is: " << r.capacity() << "\n";
	r.resize(10);
	r.shrink_to_fit();
	cout << "capacity after shrink is: " << r.capacity() << "\n";


	cin.ignore();
}