#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"


void SLTest01()
{
	SL s1;
	SLInit(&s1);
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPushBack(&s1, 4);
	SLPrint(s1);//1 2 3 4
	//SLPushFront(&s1, 5);
	//SLPushFront(&s1, 6);
	//SLPushBack(&s1, 4);
	//测试头删
	SLPopBack(&s1);
	SLPrint(s1);
	SLPopBack(&s1);
	SLPrint(s1);
	SLPopBack(&s1);
	SLPrint(s1);
	SLPopBack(&s1);
	SLPrint(s1);


	//...........
	SLDestory(&s1);

}

void SLTest02()
{
	SL s1;
	SLInit(&s1);
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPushBack(&s1, 4);
	SLPrint(s1);
	SLInsert(&s1, 0, 99);
	SLInsert(&s1, s1.size, 88);
	SLPrint(s1);

	int find = SLFind(&s1, 4);
	if (find < 0)
	{
		printf("没有找到!\n");

	}else {
		printf("找到了，下标是%d\n", find);
	}

	SLDestory(&s1);

}

int main()
{
	//SLTest01();
	SLTest02();
	return 0;
}