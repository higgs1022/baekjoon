#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

#define MAX 1000001
typedef long long ll;
ll seg[MAX * 4];

void update(ll value, int pos, int node, int left, int right)
{
	if (pos < left || right < pos)
		return;
	if (left == right)
	{
		seg[node] = value;
		return;
	}
	int mid = (left + right) >> 1;
	update(value, pos, node * 2, left, mid);
	update(value, pos, node * 2 + 1, mid + 1, right);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

ll query(int lo, int hi, int node, int left, int right)
{
	if (lo > right || left > hi)
	{
		return 0;
	}
	if (lo <= left && right <= hi)
	{
		return seg[node];
	}
	int mid = (left + right) >> 1;
	ll tmp1 = query(lo, hi, node * 2, left, mid);
	ll tmp2 = query(lo, hi, node * 2 + 1, mid + 1, right);
	return tmp1 + tmp2;
}

int main()
{
	//freopen("Text.txt", "r", stdin);
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);
	int val;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &val);
		update(val,i, 1, 0, N - 1);
	}
	for (int i = 0; i < M + K; i++)
	{
		int tmp[3];
		scanf("%d%d%d", tmp, tmp + 1, tmp + 2);
		if (tmp[0] == 1)
		{
			update(tmp[2], tmp[1]-1, 1, 0, N - 1);
		}
		else
		{
			cout << query(tmp[1]-1, tmp[2]-1, 1, 0, N - 1) << endl;
		}
	}
}