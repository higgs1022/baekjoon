#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
using namespace std;

multiset<int> s;
int N;

int main()
{
	freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++)
	{
		int value;
		scanf("%d", &value);
		if (value == 0)
		{
			if (s.begin() == s.end())
			{
				printf("0\n");
			}
			else
			{
				printf("%d\n", *--s.end());
				s.erase(--s.end());
			}
		}
		else
		{
			s.insert(value);
		}
	}
}