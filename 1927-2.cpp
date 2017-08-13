#include <iostream>
#include <queue>
using namespace std;

struct cmp
{
	bool operator()(int t, int u) {
		return t > u;
	}
};

priority_queue<int, vector<int>, cmp> q;
int n;
int main()
{
	//freopen("input.txt", "r", stdin);

	cin >> n;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;

		if (temp == 0)
		{
			if (q.empty())
			{
				cout << 0 << endl;
			}
			else
			{
				cout << q.top() << endl;
				q.pop();
			}
		}
		else
			q.push(temp);
	}
}