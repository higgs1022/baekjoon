#include <iostream>
using namespace std;

int INPUT[5];

void printResult()
{
	cout << INPUT[0] << ' ' << INPUT[1] << ' ' << INPUT[2] << ' ' << INPUT[3] << ' ' << INPUT[4] << endl;
}

void bSort()
{
	int temp;
	for (int i = 0; i < 4; i++)
	{
		if (INPUT[i] > INPUT[i + 1])
		{
			temp = INPUT[i];
			INPUT[i] = INPUT[i + 1];
			INPUT[i + 1] = temp;
			printResult();
		}
		
	}
}


int main()
{
	//freopen("input.txt", "r", stdin);
	for (int i = 0; i < 5; i++)
	{
		cin >> INPUT[i];
	}

	while (!(INPUT[0] == 1 && INPUT[1] == 2 && INPUT[2] == 3 && INPUT[3] == 4 && INPUT[4] == 5))
	{
		bSort();
	}
}