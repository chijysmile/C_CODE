#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


typedef int HPDataType;
//定义堆的结构体(实际上使用顺序表实现)
//因为顺序表的底层是数组，数组是存储堆的数据的良好结构
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;


void HPInit(HP* php);

void HPDestory(HP* php);

void Swap(HPDataType* p1, HPDataType* p2);

void HPPush(HP* php, HPDataType x);

void AdjustUp(HPDataType* a, int child);

void AdjustDown(HPDataType* a, int n, int parent);

void HPPop(HP* php);

HPDataType HPTop(HP* php);

bool HPEmpty(HP* php);