#include <iostream>
#include <queue>

using namespace std;

int garden[100005][2];
priority_queue < pair<int, pair<int, int>>> q;

void init()
{
	for (int i = 0; i < 100005; i++)
	{
		garden[i][0] = i;
	}
}

int find_set(int x)
{
	if (x == garden[x][0])
		return x;
	else
	{
		garden[x][0] = find_set(garden[x][0]);
		return garden[x][0];
	}
}

void union_set(int a, int b)
{
	garden[find_set(b)][0] = find_set(a);
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

	while (v_count < n-2)
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