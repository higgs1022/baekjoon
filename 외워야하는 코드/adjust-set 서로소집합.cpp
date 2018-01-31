#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;

int set_arr[1005];

int find_root(int a)
{
	if (set_arr[a] == a)
		return a;
	else
	{
		int temp = find_root(set_arr[a]);
		set_arr[a] = temp; // compress
		return temp;
	}
}

void my_union(int a, int b)
{

	set_arr[find_root(b)] = find_root(a);

}


int main()
{

	for (register int i = 0; i <= N; i++)
	{
		set_arr[i] = i;
	}
}