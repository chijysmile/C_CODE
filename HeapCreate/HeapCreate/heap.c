#define _CRT_SECURE_NO_WARNINGS

#include "heap.h"


void HPInit(HP* php)
{
	php->a = NULL;
	php->size = php->capacity = 0;
}



void HPDestory(HP* php)
{
	assert(php);
	if (php->a!=NULL)
	{
		free(php->a);
	}
	php->a = NULL;
	php->size = php->capacity = 0;
}

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}



//向下调整算法（有大堆的和小堆的两种这里是大堆的）
void AdjustUp(HPDataType* a, int child)
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



//向下调整算法
void AdjustDown(HPDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;
	if (a[child] < a[child + 1])
	{
		child++;
	}
	while (child < n) 
	{
		if (a[child] < a[child + 1])
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

//插入是插到堆的最后一个元素的下一位
//待插入的位置下标是size，插入后size++
//Push后仍然需要保持堆的特性
//假设我们这里是小堆
void HPPush(HP* php, HPDataType x)
{
	assert(php);
	//检查堆的容量够不够
	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
		HPDataType* tmp = (HPDataType*)realloc(php->a, newcapacity);
		if(tmp==NULL)
		{
			perror("realloc fail");
				return;
		}
		php->a = tmp;
		php->capacity = newcapacity;
	}
	php->a[php->size] = x;
	AdjustUp(php, php->size);
	php->size++;
	
	
}


void HPPop(HP* php) {
	assert(php);
	assert(php->size > 0);
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	AdjustDown(php->a, php->size, 0);
}


HPDataType HPTop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	return php->a[0];
}

bool HPEmpty(HP* php) {
	assert(php);
	return php->size == 0;
}

