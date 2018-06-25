#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

#define MAX_SIZE 100001
int seg[MAX_SIZE * 4][2];

__inline int MIN(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

__inline int MAX(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

void update(int val,int pos, int node, int left, int right)
{
	if (pos < left || right < pos)
		return;
	if (left == right)
	{
		seg[node][0] = val;
		seg[node][1] = val;
		return;
	}
	int mid = (left + right) >> 1;
	update(val, pos, node * 2, left, mid);
	update(val, pos, node * 2 + 1, mid + 1, right);
	seg[node][0] = MIN(seg[node * 2][0], seg[node * 2 + 1][0]);
	seg[node][1] = MAX(seg[node * 2][1], seg[node * 2 + 1][1]);
}

int query(int lo, int hi, int node, int left, int right)
{
	if (right < lo || hi < left)
		return 2123456789;
	if (lo <= left && right <= hi)
	{
		return seg[node][0];
	}

	int mid = (left + right) >> 1;

	int tmp1 = query(lo, hi, node * 2, left, mid);
	int tmp2 = query(lo, hi, node * 2 + 1, mid + 1, right);
	return MIN(tmp1, tmp2);
}

int query2(int lo, int hi, int node, int left, int right)
{
	if (right < lo || hi < left)
		return -1;
	if (lo <= left && right <= hi)
	{
		return seg[node][1];
	}

	int mid = (left + right) >> 1;

	int tmp1 = query2(lo, hi, node * 2, left, mid);
	int tmp2 = query2(lo, hi, node * 2 + 1, mid + 1, right);
	return MAX(tmp1, tmp2);
}

int N, M;
int main()
{
	//freopen("Text.txt", "r", stdin);

	scanf("%d%d", &N, &M);

	int input;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &input);
		update(input, i, 1, 0, N - 1);
	}
	int input2;
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d", &input, &input2);
		int tmp_min = query(input - 1, input2 - 1, 1, 0, N - 1);
		int tmp_max = query2(input - 1, input2 - 1, 1, 0, N - 1);
		printf("%d %d\n", tmp_min, tmp_max);
	}
}