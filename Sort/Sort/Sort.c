<<<<<<< HEAD
#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
void AdjustUp(int* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}

}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;

	while (child < n)
	{
		if (child + 1 < n && a[child] > a[child + 1])
		{
			child++;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}


	}
}

void heapsort(int* a, int n)
{
	//先向下调整建堆


	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	//排序
	// O(N*logN)
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}

	

	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}


void InsertSort(int* a, int n)
{

	for (int i=0;i<n-1;i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end>=0)
		{
			if (a[end] > tmp) {
				a[end + 1] = a[end];
				end--;
			}
			else {
				break;
			}
		}
		a[end + 1] = tmp;
	}

	PrintArr(a, n);
	
}

void PrintArr(int *a,int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

//void SelectSort(int* a, int n) 
//{
//
//	for (int i = 0; i < n - 1; i++) 
//	{
//
//		int end = i+1;
//		int keyi = i;
//		while (end < n)
//		{
//			if (a[end] < a[keyi])
//			{
//				keyi = end;
//			}
//			end++;
//		}
//		Swap(&a[i], &a[keyi]);
//	}
//	
//	PrintArr(a, n);
//}

void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;

	while (begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin + 1; i <= end; ++i)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}

			if (a[i] < a[mini])
			{
				mini = i;
			}
		}

		Swap(&a[begin], &a[mini]);
		if (begin == maxi)
			maxi = mini;

		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
	

	PrintArr(a, n);

}
	






=======
#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
void AdjustUp(int* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}

}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;

	while (child < n)
	{
		if (child + 1 < n && a[child] > a[child + 1])
		{
			child++;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}


	}
}

void heapsort(int* a, int n)
{
	//先向下调整建堆


	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	//排序
	// O(N*logN)
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}

	

	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}
>>>>>>> ad4636bd51d494812374df0c50e873aa42772778
