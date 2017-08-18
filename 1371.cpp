#include <iostream>
#include <cstdio>
using namespace std;

char INPUT[5005];
int COUNT[200];
int main()
{
	//freopen("input.txt", "r", stdin);
	char temp;

	while (-1 != scanf("%c", &temp))
	{
		if (temp >= 'a' && temp <= 'z')
		{
			COUNT[temp]++;
		}
	}

	int max = -1;
	for (int i = 0; i < 200; i++)
	{
		if (max < COUNT[i])
			max = COUNT[i];
	}

	for (int i = 0; i < 200; i++)
	{
		if (COUNT[i] == max)
		{
			printf("%c", i);
		}

	}
	cout << endl;
}