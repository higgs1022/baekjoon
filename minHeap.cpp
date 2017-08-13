#include <iostream>
using namespace std;

int minHeap[1000];
int minHeapSize = 0;

int isEmpty()
{
	if (minHeapSize == 0)
		return 1;
	else
		return 0;
}

int getParent(int index)
{
	return (index - 1) / 2;
}

int getLeftChild(int index)
{
	return index * 2 + 1;
}

void push(int n)
{
	minHeap[minHeapSize] = n;
	int currunt = minHeapSize;
	minHeapSize++;

	while (1)
	{
		
		int parent = getParent(currunt);
		

		if (currunt > 0 && minHeap[currunt] < minHeap[parent])
		{
			int temp = minHeap[currunt];
			minHeap[currunt] = minHeap[parent];
			minHeap[parent] = temp;
			currunt = parent;
		}
		else
			break;
	}
}

int top()
{
	return minHeap[0];
}

void pop()
{
	if (minHeapSize == 0)
		return;

	minHeapSize--;
	int temp = minHeap[0];
	minHeap[0] = minHeap[minHeapSize];
	minHeap[minHeapSize] = temp;

	int currunt = 0;
	int parent = 0;
	int leftChild = 0;
	int rightChild = 0;
	while (1)
	{
		leftChild = getLeftChild(parent);
		rightChild = leftChild + 1;

		if (leftChild >= minHeapSize)
			break;
		else if (rightChild >= minHeapSize)
		{
			currunt = leftChild;
		}
		else
		{
			if (minHeap[leftChild] > minHeap[rightChild])
				currunt = rightChild;
			else
				currunt = leftChild;
		}

		//swap

		temp = minHeap[parent];
		minHeap[parent] = minHeap[currunt];
		minHeap[currunt] = temp;

		parent = currunt;
	}
}



int main()
{
}