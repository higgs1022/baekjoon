#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> s;

	s.insert(5);
	s.insert(3);
	s.insert(10);
	s.insert(1);

	for (auto i = s.begin(); i != s.end(); i++)
	{
		printf("%d\n", *i);
	}
}