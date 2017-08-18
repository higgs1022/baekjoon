#include <iostream>
using namespace std;

int N;
int COUNT[10005];

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		COUNT[temp]++;
	}
	
	for (int i = 0; i < 10001; i++)
	{
		if (COUNT[i] != 0)
		{
			for (int j = 0; j < COUNT[i]; j++)
			{
				printf("%d\n", i);
			}
		}
		
	}

}