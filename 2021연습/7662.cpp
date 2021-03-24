#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
using namespace std;

int N, M;
multiset<int> s;

void init()
{
	s = multiset<int>();
}

int main()
{
	freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int n = 0; n < N; n++)
	{
		init();
		scanf("%d", &M);
		for (int m = 0; m < M; m++)
		{
			char c[5];
			int value;
			scanf("%s %d", c, &value);
			switch (c[0])
			{
			case 'I':
				s.insert(value);
				break;
			case 'D':
				if (s.begin() == s.end())
					break;
				
				if (value > 0)
					s.erase(--s.end());
				else
					s.erase(s.begin());
			}
		}
		if (s.begin() == s.end())
			printf("EMPTY\n");
		else
		{
			printf("%d ", *s.rbegin());
			printf("%d\n", *s.begin());
		}
	}
}