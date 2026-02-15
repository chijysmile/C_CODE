<<<<<<< HEAD
#define _CRT_SECURE_NO_WARNINGS

#include "Sort.h"

void TestHeapSort()
{
	int a[11] = { 71,82,103,55,23,43,1,2,3,4,29 };
	// 1 2 3 4 23 29 
	heapsort(a, 11);
}

void TestInsertSort()
{
	int a[11] = { 71,82,103,55,23,43,1,2,3,4,29 };
	InsertSort(a, sizeof(a) / sizeof(int));
}

//void TestSelectSort()
//{
//	int a[11] = { 71,82,103,55,23,43,1,2,3,4,29 };
//	SelectSort(a, sizeof(a) / sizeof(int));
//}


void TestSelectSort()
{
	int a[11] = { 71,82,103,55,23,43,1,2,3,4,29 };
	SelectSort(a, sizeof(a) / sizeof(int));
}


int main()
{
	//TestInsertSort();
	TestSelectSort();

=======
#define _CRT_SECURE_NO_WARNINGS

#include "Sort.h"
int main()
{
	int a[11] = { 71,82,103,55,23,43,1,2,3,4,29 };
	// 1 2 3 4 23 29 
	heapsort(a, 11);

>>>>>>> ad4636bd51d494812374df0c50e873aa42772778
}