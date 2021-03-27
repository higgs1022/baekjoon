#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int N;
int arr[100005];
int cnt;

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void reorder_up(int index)
{
	int cur = index;
	int parent = cur / 2;
	while (1) {
		if (parent < 1)
		{
			return;
		}
		if (arr[parent] < arr[cur])
		{
			swap(&arr[parent], &arr[cur]);
		}
		else
		{
			return;
		}

		cur = cur / 2;
		parent = cur / 2;
	}
}

void insert_heap(int value)
{
	arr[cnt++] = value;
	reorder_up(cnt - 1);
}

void reorder_down()
{
	int cur = 1;
	while (1)
	{
		int leftIndex = cur * 2;
		int rightIndex = cur * 2 + 1;

		if (rightIndex < cnt)
		{
			int left = arr[leftIndex];
			int right = arr[rightIndex];

			if (left < right)
			{
				if (right > arr[cur])
				{
					swap(&arr[rightIndex], &arr[cur]);
					cur = rightIndex;
					continue;
				}
			}
		}

		if (leftIndex < cnt)
		{
			int left = arr[leftIndex];
			if (left > arr[cur])
			{
				swap(&arr[leftIndex], &arr[cur]);
				cur = cur * 2;
				continue;
			}
		}

		return;
	}
}

void pop()
{
	if (cnt <= 1)
		return;
	arr[1] = arr[cnt-1];
	arr[cnt - 1] = 0;
	cnt--;
	reorder_down();
}

void init()
{
	cnt = 1;
}

int main()
{
	//freopen("Text.txt", "r", stdin);
	//freopen("2.txt", "w", stdout);
	init();
	scanf("%d", &N);
	for (int n = 0; n < N; n++)
	{
		int value;
		scanf("%d", &value);
		if (value == 0)
		{
			if (cnt <= 1)
			{
				printf("0\n");
			}
			else
			{
				printf("%d\n", arr[1]);
				pop();
			}
		}
		else
		{
			insert_heap(value);
		}
	}
}