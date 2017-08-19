#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> Input[100005];
int N;

int main()
{
	//freopen("input.txt", "r", stdin);
	
	cin.sync_with_stdio(false);
	cin >> N;
	int x, y;
	for (int i = 0; i < N; i++)
	{
		cin  >> Input[i].second >> Input[i].first;
	}

	sort(Input, Input + N);

	for (int i = 0; i < N; i++)
	{
		cout << Input[i].second << ' ' << Input[i].first << '\n';
	}
}