#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class MyClass
{
public:
	int x, y, z, n;
	MyClass()
	{

	}
	MyClass(int a, int b, int c,int m)
	{
		x = a;
		y = b;
		z = c;
		n = m;
	}
};

class myQueue
{
public:
	int weight, n, m;
};
bool operator<(const myQueue& e1, const myQueue& e2)
{
	return e1.weight > e2.weight;
}

bool compx(const MyClass& a, const MyClass& b)
{
	return a.x > b.x;
}

bool compy(const MyClass& a, const MyClass& b)
{
	return a.y > b.y;
}

bool compz(const MyClass& a, const MyClass& b)
{
	return a.z > b.z;
}

int N;
vector<myQueue> myVec;
int mySet[100005];
MyClass tempArr[100005];

int find_set(int x)
{
	if (mySet[x] == x)
		return x;
	else
	{
		mySet[x] = find_set(mySet[x]);
		return mySet[x];
	}
}

void union_set(int a, int b)
{
	mySet[find_set(a)] = mySet[find_set(b)];
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		mySet[i] = i;
	}

	int x, y, z;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y >> z;
		tempArr[i]=MyClass(x, y, z, i);
	}

	sort(tempArr, tempArr + N, compx);
	for (int i = 0; i < N - 1; i++)
	{
		int temp = tempArr[i].x - tempArr[i + 1].x;
		if (temp < 0)
			temp = -temp;

		myQueue tempQ;
		tempQ.weight = temp;
		tempQ.m = tempArr[i].n;
		tempQ.n = tempArr[i + 1].n;
		myVec.push_back(tempQ);
	}

	sort(tempArr, tempArr + N, compy);
	for (int i = 0; i < N - 1; i++)
	{
		int temp = tempArr[i].y - tempArr[i + 1].y;
		if (temp < 0)
			temp = -temp;

		myQueue tempQ;
		tempQ.weight = temp;
		tempQ.m = tempArr[i].n;
		tempQ.n = tempArr[i + 1].n;
		myVec.push_back(tempQ);
	}

	sort(tempArr, tempArr + N, compz);
	for (int i = 0; i < N - 1; i++)
	{
		int temp = tempArr[i].z - tempArr[i + 1].z;
		if (temp < 0)
			temp = -temp;

		myQueue tempQ;
		tempQ.weight = temp;
		tempQ.m = tempArr[i].n;
		tempQ.n = tempArr[i + 1].n;
		myVec.push_back(tempQ);
	}
	sort(myVec.begin(), myVec.end());

	int count = 0;
	int result = 0;
	while (count != N - 1)
	{
		myQueue q = myVec.back();
		myVec.pop_back();

		if (find_set(q.m) != find_set(q.n))
		{
			union_set(q.m, q.n);
			count++;
			result = result + q.weight;
		}
	}

	cout << result << endl;
}