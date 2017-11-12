#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;

vector<int> myVec[100005];
int myCheck[100005];
int n;
void dfs(int x)
{
	for (int i = 0; i < myVec[x].size(); i++)
	{
		if (myCheck[myVec[x][i]] != -1)
			continue;
		else
		{
			myCheck[myVec[x][i]] = x;
			dfs(myVec[x][i]);
		}
		
	}
	
}

int main()
{
	memset(myCheck, -1, sizeof(myCheck));

	
	cin >> n;

	int x, y;

	for (int i = 0; i < n - 1; i++)
	{
		cin >> x >> y;
		myVec[x-1].push_back(y-1);
		myVec[y-1].push_back(x-1);
	}

	myCheck[0] = 0;
	dfs(0);
	
	for (int i = 1; i < n; i++)
	{
		cout << myCheck[i]+1 << '\n';
	}
}