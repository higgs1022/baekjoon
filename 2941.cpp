#include <iostream>
#include <cstring>
using namespace std;

char *finds[] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
char input[105];

int result;
char * curr_pointer;

void compareProblem(char * src)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < strlen(finds[i]); j++)
		{
			if (*(src + j) == finds[i][j])
			{
				if (j == strlen(finds[i]) - 1)
				{
					curr_pointer = src + j + 1;
					result++;
					return;
				}
			}
			else
				break;
		}
	}
	result++;
	curr_pointer++;
	return;
}

int main()
{
	cin >> input;

	curr_pointer = input;

	while (*curr_pointer != 0)
	{
		compareProblem(curr_pointer);
	}

	cout << result << '\n';

}