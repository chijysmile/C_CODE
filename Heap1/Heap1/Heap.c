#define _CRT_SECURE_NO_WARNINGS
#include "Heap.h"
void HeapInit(HP* php) 
{
	php->a = NULL;
	php->capacity = php->size = 0;
}

void HPDestroy(HP* php) 
{
	assert(php);
	if (php->a!=NULL)
	{
		free(php->a);
	}
	php->a = NULL;
	php->size = php->capacity = 0;
}

void Swap(HPDataType* p1, HPDataType* p2) {
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}

void AdjustDown(HPDataType* a,int n, int parent)
{
	int child = 2 * parent + 1;
	
	while (child < n)
	{
		if (a[child] < a[child + 1])
			child++;
		if (a[child] < a[parent])
		{
			swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else {
			break;
		}
	}
}

void HPPush(HP* php, HPDataType x) {
	assert(php);
	if (php->size == php->capacity)
	{
		int newcpacity = php->capacity == 0 ? 4 : 2 * php->capacity;
		HPDataType* tmp = (HPDataType*)realloc(php->a,newcpacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			preeor("realloc fail");
			return;
		}
		php->a = tmp;
		php->capacity = newcpacity;
	}

	php->a[php->size] = x;
	php->size++;

}

void HPPop(HP* php) {
	assert(php);
	assert(php->size > 0);
	swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	AdjustDown(php->a, php->size, 0);

}

HPDataType HPTop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	return php->a[0];
}

bool HPEmpty(HP* php)
{
	assert(php);

	return php->size == 0;
}


//½µÐò
void heapsort(HPDataType* a, int n)
{
	assert(a);
	
}