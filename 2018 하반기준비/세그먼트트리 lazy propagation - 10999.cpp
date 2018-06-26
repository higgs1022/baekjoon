#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

#define MAX 1000001
typedef long long ll;
ll seg[MAX * 4];
ll lazy[MAX * 4];

int N, M, K;


void propa(int left, int right, int node)
{
	seg[node] += (right - left + 1) * lazy[node];
	if (left != right)
	{
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}

void update(ll val, int pos, int node, int left, int right)
{
	if (pos < left || right < pos)
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
	update(val, pos, node * 2+1, mid + 1, right);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
	return;
}


ll query(int lo, int hi, int node, int left, int right)
{
	if (lazy[node] != 0)
	{
		propa(left, right, node);
	}
	if (hi < left || right < lo)
		return 0;
	if (lo <= left && right <= hi)
	{
		return seg[node];
	}
	int mid = (left + right) >> 1;
	ll tmp1 = query(lo, hi, node * 2, left, mid);
	ll tmp2 = query(lo, hi, node * 2 + 1, mid + 1, right);
	return tmp1 + tmp2;
}

void add(int lo, int hi, ll val, int node, int left, int right)
{
	if (lazy[node] != 0)
	{
		propa(left, right, node);
	}
	if (hi < left || right < lo)
		return;
	if (lo <= left && right <= hi)
	{
		seg[node] += (right - left + 1) * val;
		if (right != left)
		{
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return;
	}
	int mid = (left + right) >> 1;
	add(lo, hi, val, node*2, left, mid);
	add(lo, hi, val, node * 2+1, mid + 1, right);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

int main()
{
	//freopen("Text.txt", "r", stdin);
	
	scanf("%d%d%d", &N, &M, &K);
	int val;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &val);
		update(val, i, 1, 0, N - 1);
	}
	for (int i = 0; i < M + K; i++)
	{
		int tmp[4];
		scanf("%d%d%d", tmp, tmp + 1, tmp + 2);
		if (tmp[0] == 1)
		{
			scanf("%d", tmp+3);
			add(tmp[1] - 1, tmp[2] - 1, tmp[3], 1, 0, N - 1);
		}
		else
		{
			printf("%lld\n", query(tmp[1] - 1, tmp[2] - 1, 1, 0, N - 1));
		}
	}
}