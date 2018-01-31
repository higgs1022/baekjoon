#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class my
{
public:
	my()
	{
		val = 0;
		isClost = 0;
	}

	int val;
	bool isClost;
};
my stack[1000];

char input[1000];
int top;

#define H 1
#define O 16
#define C 12

int main()
{
	//freopen("Text.txt", "r", stdin);
	scanf("%s", input);
	char* pt = input;

	while (*pt != 0)
	{
		my m;
		switch (*pt)
		{

		case 'H':
			m.val = H;
			stack[++top] = m;
			break;
		case 'O':
			m.val = O;
			stack[++top] = m;
			break;
		case 'C':
			m.val = C;
			stack[++top] = m;
			break;
		case '(':
			m.isClost = true;
			stack[++top] = m;
			break;
		case ')':
		{
			int sum = 0;
			while (stack[top].isClost == false)
			{
				sum += stack[top--].val;
			}
			stack[top].val = sum;
			stack[top].isClost = false;
		}
		break;
		default:
			stack[top].val = stack[top].val * (*pt - '0');
			break;

			
		}
		pt++;
	}
	int result = 0;
	while (top != 0)
	{
		result += stack[top--].val;
	}
	printf("%d\n", result);
}