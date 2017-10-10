#include <iostream>
#include <queue>

using namespace std;

int computer[1005][2];
priority_queue < pair<int, pair<int, int>>> q;

void init()
{
	for (int i = 0; i < 1005; i++)
	{
		computer[i][0] = i;
	}
}

int find_set(int x)
{
	if (x == computer[x][0])
		return x;
	else
		return find_set(computer[x][0]);
}

void union_set(int a,int b)
{
	computer[find_set(b)][0] = find_set(a);
}

int main()
{
	init();

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, x;
		cin >> a >> b >> x;
		q.push(make_pair(-x, make_pair(a, b)));
	}

	int v_count = 0;
	int result = 0;
	while (v_count < n-1)
	{
		int a = q.top().second.first;
		int b = q.top().second.second;
		int x = -q.top().first;
		q.pop();
		if (find_set(a) != find_set(b))
		{
			union_set(a, b);
			v_count++;
			result += x;
		}
	}

	cout << result << endl;
}