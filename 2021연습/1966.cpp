#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int C;
int N, M;
int COUNT;

struct My
{
	int value;
	bool mark;
	My(int _value, bool _mark)
	{
		value = _value;
		mark = _mark;
	}
};

queue<My> q;
priority_queue<int> pq;

void init()
{
	COUNT = 0;
	while (!pq.empty())
	{
		pq.pop();
	}
	while (!q.empty())
	{
		q.pop();
	}
}

void run()
{
	int pq_cur = pq.top();
	while (!q.empty())
	{
		My q_cur = q.front();
		q.pop();
		if (q_cur.value == pq_cur)
		{
			COUNT++;
			if (q_cur.mark)
			{
				printf("%d\n", COUNT);
				return;
			}
			else
			{
				pq.pop();
				pq_cur = pq.top();
			}
		}
		else
		{
			q.push(q_cur);
		}
	}
}

int main()
{
	freopen("Text.txt", "r", stdin);

	scanf("%d", &C);
	for (int c = 0; c < C; c++)
	{
		init();
		scanf("%d %d", &N, &M);
		for (int n = 0; n < N; n++)
		{
			int tmp;
			scanf("%d", &tmp);
			My cur = My(tmp, false);
			if (n == M)
				cur = My(tmp, true);
			q.push(cur);
			pq.push(tmp);
		}
		run();
	}
}