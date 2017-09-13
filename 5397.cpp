#include <iostream>
#include <list>
#include <cstring>
using namespace std;

list<char> result;
char input[1000005];

void print_all()
{
	list<char>::iterator itor = result.begin();
	for (; itor != result.end(); itor++)
	{
		printf("%c",*itor);
	}
	printf("\n");
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		result.clear();
		scanf("%s", input);

		list<char>::iterator itor = result.begin();

		int input_len = strlen(input); //매우중요!!... 시간초과남 for안에서 하면

		for (int j = 0; j < input_len; j++)
		{
			char cur = input[j];

			if (cur == '<')
			{
				if (itor == result.begin())
					continue;
				else
					itor--;
			}

			else if (cur == '>')
			{
				if (itor == result.end())
					continue;
				else
					itor++;
			}

			else if (cur == '-')
			{
				if (itor == result.begin())
					continue;
				itor--;
				itor = result.erase(itor);
			}
			else
			{
				result.insert(itor, cur);
			}
		}

		print_all();
	}
}