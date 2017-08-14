#include <iostream>
#include <set>
using namespace std;

int n, m;
multiset<int> ms;

int main()
{
	//freopen("input.txt", "r", stdin);

	cin >> n;

	char input1[2];
	int input2;
	for (int i = 0; i < n; i++)
	{
		ms.clear();
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			scanf("%s %d", input1, &input2);
			if (input1[0] == 'I')
			{
				ms.insert(input2);
			}
			else
			{
				if (input2 == 1 && !ms.empty())
				{
					//cout << *ms.rbegin << endl;
					ms.erase(--ms.end());
				}
				else if(input2 == -1 && !ms.empty())
				{
					//cout << *ms.begin << endl;
					ms.erase(ms.begin());
				}
			}
		}
		
		if (ms.empty())
			cout << "EMPTY" << endl;
		else
		{
			cout << *ms.rbegin() << " " << *ms.begin() << endl;
		}
	}
}
