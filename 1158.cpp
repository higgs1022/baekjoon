#include <iostream>
using namespace std;

struct List_
{
	struct List_* next;
	int value;
} typedef List;

List all[10000];
int all_size;

int main()
{
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		all[i].value = i + 1;
		all[i].next = &all[i + 1];
	}

	all[n - 1].next = &all[0];

	List* start = &all[n - 1];


	cout << "<";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m-1; j++)
		{
			start = start->next;
		}
		cout << start->next->value;
		if (i != n - 1)
			cout << ", ";
		start->next = start->next->next;
	}
	cout << ">" << endl;
}