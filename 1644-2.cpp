#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<int> primeVector;
bool primeArray[4000001];

int main()
{
	int input;
	cin >> input;

	for (int i = 2; i <= input; i++)
	{
		primeArray[i] = true;
	}

	for (int i = 4; i <= input; i += 2)
	{
		primeArray[i] = false;
	}

	primeVector.push_back(2);

	for (int i = 3; i <= input; i++)
	{
		if (primeArray[i] == true)
			primeVector.push_back(i);

		for (long long j = (long long)i*i; j <= input; j += i * 2)
		{
			primeArray[j] = false;
		}
	}

	int s, e, sum;
	s = 0;
	e = 0;
	sum = 0;
	int result = 0;
	while (1)
	{

		if (sum >= input) //투포인트 순서중요
		{
			sum = sum - primeVector[s++];
		}
		else if (e == primeVector.size())//순서중요
			break;
		else if (sum < input)//순서중요
		{
			sum = sum + primeVector[e++];
		}

		if (sum == input)	//조건만족 부분합
		{
			result++;
		}
	}

	cout << result << '\n';
}