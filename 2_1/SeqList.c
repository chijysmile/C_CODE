#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"
#include <assert.h>
//顺序表初始化方法
void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

//顺序表销毁方法
void SLDestory(SL* ps)
{
	assert(ps);
	if (ps->arr)//ps->arr！=NULL
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

//空间检查方法(不够时会申请空间）
void SLCapacityCheck(SL* ps)
{
	
	if (ps->size == ps->capacity)
	{
		//申请空间用malloc realloc还是calloc
		//realloc用来增容
		//三目表达式↓
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;//空间为空申请四个，不够就加倍
		DataType* tmp = (DataType*)realloc(ps->arr, newcapacity * sizeof(DataType));
		if (tmp == NULL)//用一个临时的tmp变量，解决realloc失败，原空间变NULL的问题
		{
			perror(tmp);
			exit(1);
		}
		ps->arr = tmp;
		ps->capacity = newcapacity;
	}
}

//尾插方法
void SLPushBack(SL* ps,DataType X)
{
	//一种温柔的解决方式，判断是否是空指针
	//if (ps == NULL)
	//{
	//	return;
	//}
	assert(ps);//暴力的解决方式
	//插入前检查空间
	SLCapacityCheck(ps);
	ps->arr[ps->size++] = X;

}

//头插方法
void SLPushFront(SL* ps, DataType X)
{
	assert(ps);
	SLCapacityCheck(ps);//头插也要检查空间
	//头插需要先让顺序表中的已有的数据整体往后挪动一位
	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = X;
	ps->size++;//SLPrint打印方法依赖于size，size要改变
}

void SLPrint(SL a)
{
	for (int i = 0; i < a.size; i++)
	{
		printf("%d ", a.arr[i]);
	}
	printf("\n");
}

void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size);
	--ps->size;//不影响增删查改，所以直接让size-1
}

void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size);
	for (int i = 0; i < ps->size-1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	--ps->size;

}

void SLInsert(SL* ps, int pos, DataType X) {
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);//pos大于等于且要小于等于有效数据个数
	//先检查空间够不够，不够就申请空间
	SLCapacityCheck(ps);
	//pos及以后的数据整体往后移动一位
	for (int i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[pos] = X;
	ps->size++;
}


void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);//和SLInsert不同，因为size位置上无数据不可删除
	//pos以后的数据整体向前移动一位
	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];//最后一步是arr[size-2]=arr[size-1];
	}
	ps->size--;
}


int SLFind(SL* ps, DataType X) {
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == X)
		{
			//找到了
			return i;
		}
	}
	//没找到
	return -1;
}