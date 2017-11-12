#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Myclass
{
public:

	int a, b;
};

bool operator<(const Myclass& a, const Myclass& b)
{
	return a.b < b.b;
}

vector<Myclass> myVec;

int main()
{
	for (int i = 0; i < 30; i++)
	{
		Myclass temp;
		temp.a = rand() % 100;
		temp.b = rand() % 100;
		myVec.push_back(temp);
	}

	cout << "정렬 전" << endl;
	for (int i = 0; i < 30; i++)
	{
		cout << "i:" << i << " value: " << myVec[i].b << endl;
	}
	
	sort(myVec.begin(), myVec.end());

	cout << "정렬 후" << endl;
	for (int i = 0; i < 30; i++)
	{
		cout << "i:" << i << " value: " << myVec[i].b << endl;
	}

	Myclass temp1;
	temp1.b = 99;
	Myclass temp2;
	temp2.b = 0;

	if (temp1 < temp2)
	{
		cout << "temp2가 더크다" << endl;
	}
	else
		cout << "temp1가 더크다" << endl;
	
}