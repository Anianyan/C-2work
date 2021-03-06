// QuickSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<ctime>
#include <iostream>
#include <algorithm>
#define size_ 10

void quicksort(int*, int, int);
void print(int*);


int main()
{
	int arr[size_] = { 0 };
	int i = 0;
	srand((unsigned)time(0) - 50 );
	for (i = 0; i < size_; i++)
	{
		arr[i] = (rand() % 100 - 50);
	}
		
	std::cout << "Before Quick Sort :" << std::endl;
	print(arr);

	quicksort(arr, 0, size_ - 1);

	std::cout << "After Quick Sort :" << std::endl;
	print(arr);

    return 0;
}

void print(int* arr)
{
	for (int i = 0; i < size_; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}



void quicksort(int* ar, int low, int high)
{
	int i = low;
	int j = high;
	int pivot = ar[(i + j) / 2];

	while (i <= j)
	{
		while (ar[i] < pivot)	i++;
		while (ar[j] > pivot)	j--;

		if (i <= j)
		{
			std::swap(ar[i], ar[j]);
			i++;
			j--;
		}
	}
	print(ar);
	if (j > low)		quicksort(ar, low, j);
	if (i < high)		quicksort(ar, i, high);
}

