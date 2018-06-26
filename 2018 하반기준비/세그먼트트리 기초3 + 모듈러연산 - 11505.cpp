#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

typedef long long ll;

#define MAX_SIZE 1000001

ll seg[MAX_SIZE * 4];

void update(int val, int pos, int node, int left, int right)
{
	if (left > pos || right < pos)
	{
		return;
	}
	if (left == right)
	{
		seg[node] = val;
		return;
	}
	int mid = (left + right) >> 1;
	update(val, pos, node * 2, left, mid);
	update(val, pos, node * 2 + 1, mid + 1, right);
	seg[node] = (seg[node * 2] * seg[node * 2 + 1]) % 1000000007;
}

ll query(int lo, int hi, int node, int left, int right)
{
	if (hi<left || lo > right)
	{
		return 1;
	}
	if (lo <= left && right <= hi)
	{
		return seg[node];
	}
	int mid = (left + right) >> 1;
	ll tmp1 = query(lo, hi, node * 2, left, mid);
	ll tmp2 = query(lo, hi, node * 2 + 1, mid + 1, right);
	return (tmp1 * tmp2) % 1000000007;
}

int N, M, K;

int main()
{
	//freopen("Text.txt", "r", stdin);

	scanf("%d%d%d", &N, &M, &K);

	int input[3];

	for (int i = 0; i < N; i++)
	{
		scanf("%d", input);

		update(input[0], i, 1, 0, N - 1);
	}

	for (int i = 0; i < M + K; i++)
	{
		scanf("%d%d%d", input, input + 1, input + 2);
		if (input[0] == 1)
		{
			update(input[2], input[1] - 1, 1, 0, N - 1);
		}
		else
		{
			printf("%lld\n", query(input[1] - 1, input[2] - 1, 1, 0, N - 1) % 1000000007);
		}
	}
}