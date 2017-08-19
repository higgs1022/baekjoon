#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Student
{
public:
	string name;
	int age;
	int num;
};

bool cmp(const Student &a, const Student &b)
{
	if (a.age == b.age)
	{
		return a.num < b.num;
	}
	else
	{
		return a.age < b.age;
	}
	
}

int N;
Student Input[100005];

int main()
{
	//freopen("input.txt", "r", stdin);
	cin.sync_with_stdio(false);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> Input[i].age >> Input[i].name;
		Input[i].num = i;
	}

	sort(Input, Input + N, cmp);

	for (int i = 0; i < N; i++)
	{
		cout << Input[i].age << ' ' << Input[i].name << '\n';
	}
}