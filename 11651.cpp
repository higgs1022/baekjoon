#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> Input[100005];
int N;

void swap(pair<int, int>* a, pair<int, int>* b)
{
	pair<int, int> temp = *a;
	*a = *b;
	*b = temp;
}

void my_q_sort(int left, int right) // stable_sort, q_sort 라잇브러리써서 풀어볼것 
{
	int leftIndex, rightIndex, pivot, pivot2;

	leftIndex = left;
	rightIndex = right;
	pivot = Input[right].first;
	pivot2 = Input[right].second;
	while (leftIndex <= rightIndex)
	{
		while (Input[leftIndex].first < pivot || (Input[leftIndex].first == pivot && Input[leftIndex].second < pivot2))
			leftIndex++;
		while (Input[rightIndex].first > pivot || (Input[rightIndex].first == pivot && Input[rightIndex].second > pivot2))
			rightIndex--;
		if (leftIndex <= rightIndex)
		{
			swap(&Input[leftIndex], &Input[rightIndex]);
			leftIndex++;
			rightIndex--;
		}
	}

	if (left < rightIndex)
		my_q_sort(left, rightIndex);
	if (leftIndex < right)
		my_q_sort(leftIndex, right);
}

/*
void q_sort(int left,int right)
{
	int leftIndex, rightIndex, pivot;

	leftIndex = left;
	rightIndex = right;
	pivot = Input[right].first;
	while (leftIndex <= rightIndex)
	{
		while (Input[leftIndex].first < pivot)
			leftIndex++;
		while (Input[rightIndex].first > pivot)
			rightIndex--;
		if (leftIndex <= rightIndex)
		{
			pair<int, int> temp = Input[leftIndex];
			Input[leftIndex] = Input[rightIndex];
			Input[rightIndex] = temp;
			leftIndex++;
			rightIndex--;
		}
	}
	
	
	if (left < rightIndex)
		q_sort(left, rightIndex);
	if ( leftIndex < right )
		q_sort(leftIndex, right);

}
*/

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

	my_q_sort(0, N-1);

	for (int i = 0; i < N; i++)
	{
		cout << Input[i].second << ' ' << Input[i].first << '\n';
	}
}