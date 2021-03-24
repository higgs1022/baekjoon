#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
using namespace std;

int main()
{
	multiset<int> s;

	s.insert(5);
	s.insert(5);
	
	//5 하나만 날림
	s.erase(s.begin());
	
	//5전부 날림
	//s.erase(5);

	printf("%d \n", s.begin() == s.end());
}