//1966.c

#include <algorithm>
#include <iostream>
//#include <queue>
using namespace std;
#define TRUE 1
#define FALSE 0

#define qSize 10000

pair<int, int> q[qSize];
//priority_queue<int> q
int front;
int rear;

void init()
{
	front = 0;
	rear = 1;
}

pair<int, int> pop()
{
	pair<int, int> result = q[front + 1];
	front = (front + 1) % qSize;
	return result;
}

pair<int, int> peek()
{
	return q[front + 1];
}

void push(pair<int, int> n)
{
	q[rear] = n;
	rear = (rear + 1) % qSize;
}

int isEmpty()
{
	if ((rear - 1 % qSize) == (front % qSize))
		return TRUE;
	else
		return FALSE;
}

int isFull()
{
	if ((rear % qSize) == (front % qSize))
		return TRUE;
	else
		return FALSE;
}

int getMax()
{
	int result = -2123456789;
	for (int i = front; i != rear-1; i++)
	{
		if (result < q[i + 1].first)
		{
			result = q[i + 1].first;
		}
	}
	return result;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int testcase;
	cin >> testcase;
	int n, m;
	for (int i = 0; i < testcase; i++)
	{
		init();

		cin >> n >> m;

		for (int j = 0; j < n; j++)
		{
			int temp;
			cin >> temp;
			if (j == m)
			{
				push(make_pair(temp, 1));
			}
			else
			{
				push(make_pair(temp, 0));
			}

		}

		int result = 1;

		while (!isEmpty())
		{
			pair<int, int> t = peek();
			if (t.first == getMax())
			{
				if (t.second == 1)
				{
					cout << result << endl;
					
				}
				pop();
				result++;
			}
			else
			{
				pop();
				push(t);
			}
		}
		
	}
	return 0;
}