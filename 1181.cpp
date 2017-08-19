#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
pair<int, string> Input[20005];

int main()
{
	//freopen("input.txt", "r", stdin);
	cin.sync_with_stdio(false);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> Input[i].second;
		Input[i].first = Input[i].second.length();
	}

	sort(Input, Input + N);

	string before;
	for (int i = 0; i < N; i++)
	{
		if (before == Input[i].second)
			continue;
		before = Input[i].second;
		cout << Input[i].second << '\n';
	}
}