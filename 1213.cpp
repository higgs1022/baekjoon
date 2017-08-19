#include <iostream>
#include <algorithm>
using namespace std;
int Count[26];

void print_char_many(int charNum, int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("%c", charNum);
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	char temp;
	while (  -1 !=scanf("%c", &temp) )
	{
		Count[temp-'A']++;
	}
	
	int odd_Count = 0;
	for (int i = 0; i < 26; i++)
	{
		if (Count[i] != 0 && (Count[i] % 2) == 1)
		{
			odd_Count++;
		}
	}

	if (odd_Count > 1)
	{
		cout << "I'm Sorry Hansoo" << '\n';
	}
	else
	{
		for (int i = 0; i < 26; i++)
		{
			if (Count[i] != 0 && (Count[i] % 2) != 1)
			{
				print_char_many(i + 'A', Count[i] / 2);
			}
			if (Count[i] != 0 && (Count[i] % 2) == 1)
			{
				print_char_many(i + 'A', (Count[i]-1) / 2);
			}
		}

		for (int i = 0; i < 26; i++)
		{
			if (Count[i] != 0 && (Count[i] % 2) == 1)
			{
				print_char_many(i + 'A', 1);
			}
		}

		for (int i = 25; i >= 0; i--)
		{
			if (Count[i] != 0 && (Count[i] % 2) != 1)
			{
				print_char_many(i + 'A', Count[i] / 2);
			}
			if (Count[i] != 0 && (Count[i] % 2) == 1)
			{
				print_char_many(i + 'A', (Count[i] - 1) / 2);
			}
		}
		cout << '\n';
	}

}