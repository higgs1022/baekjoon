#include <iostream>
#include <string>
#include <queue>
using namespace std;

int map[105][105];
int check[105][105];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

queue<pair<int, int>> q;

int main()
{
	int n, m;
	cin >> n >> m;
	string line;
	for (int i = 0; i < n; i++)
	{
		cin >> line;
		for (int j = 0; j < m; j++)
		{
			map[i][j] = line.at(j)-'0';
		}
	}
	check[0][0] = 1;
	q.push(make_pair(0, 0));
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		int nx, ny;

		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m)
			{
				if (check[nx][ny] == 0 &&map[nx][ny]==1)
				{
					check[nx][ny] = check[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	cout << check[n - 1][m - 1] << '\n';
}