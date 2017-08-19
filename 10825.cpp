#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Student
{
public:
	string name;
	int kor;
	int eng;
	int math;
};

bool cmp(const Student &a, const Student &b)
{
	if (a.kor == b.kor)
	{
		if (a.eng == b.eng)
		{
			if (a.math == b.math)
			{
				return a.name < b.name;
			}
			else
			{
				return a.math > b.math;
			}
		}
		else
		{
			return a.eng < b.eng;
		}
	}
	else
	{
		return a.kor > b.kor;
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
		cin >> Input[i].name >> Input[i].kor >> Input[i].eng >> Input[i].math;
	}

	sort(Input, Input + N, cmp);

	for (int i = 0; i < N; i++)
	{
		cout << Input[i].name << '\n';
	}
}