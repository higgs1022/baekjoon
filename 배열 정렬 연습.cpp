#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Myclass
{
public:

	int a, b;
};

bool myoperator(const Myclass& a, const Myclass& b)
{
	return a.b < b.b;
}

Myclass arr[30];

int main()
{
	for (int i = 0; i < 30; i++)
	{
		Myclass temp;
		temp.a = rand() % 100;
		temp.b = rand() % 100;
		arr[i] = temp;
	}

	cout << "정렬 전" << endl;
	for (int i = 0; i < 30; i++)
	{
		cout << "i:" << i << " value: " << arr[i].b << endl;
	}
	
	sort(arr, arr+30, myoperator);

	cout << "정렬 후" << endl;
	for (int i = 0; i < 30; i++)
	{
		cout << "i:" << i << " value: " << arr[i].b << endl;
	}

	Myclass temp1;
	temp1.b = 99;
	Myclass temp2;
	temp2.b = 0;
	
}