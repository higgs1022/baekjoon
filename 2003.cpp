#include <iostream>
using namespace std;

int s, e;
int Input[10005];
int N, M;
int count_result;

int main()
{
	//freopen("input.txt", "r", stdin);

	cin.sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> Input[i];
	}

	int sum = 0;

	while (1)
	{
		if (e == N)
			break;

		if (sum < M)
		{
			sum = sum + Input[e++];
		}
		else if (sum >= M)
		{
			sum = sum - Input[s++];
		}

		if (sum == M)
			count_result++;
	}

	cout << count_result << '\n';
}