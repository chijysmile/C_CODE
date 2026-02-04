#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Contact.h"
#include <string.h>
//定义顺序表的结构

//静态顺序表
//封装了一个定长数组
typedef peoInfo DataType;//方便后续类型替换
//#define N 100
//struct SeqList
//{
//	DataType arr[N];
//
//};

//动态顺序表



typedef struct SeqList
{
	DataType* arr;
	int size;
	int capacity;
}SL;



//顺序表的初始化方法
void SLInit(SL* ps);
//传址调用，才能通过这个地址解引用访问顺序表结构体

//顺序表的销毁方法
void SLDestory(SL* ps);

//检查空间大小方法
void SLCapacityCheck(SL* ps);





//顺序表增删查改操作
//-------增加操作--------
//尾插
void SLPushBack(SL* ps, DataType X);

//头插
void SLPushFront(SL* ps, DataType X);

//顺序表打印方法
//void SLPrint(SL a);

//头删
void SLPopFront(SL* ps);
//尾删
void SLPopBack(SL* ps);

//指定位置之前插入数据
void SLInsert(SL* ps, int pos, DataType X);

//删除指定位置的数据
void SLErase(SL* ps, int pos);

//查找指定数据
//int SLFind(SL* ps, DataType X);