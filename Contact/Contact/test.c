#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"
void ContactTest01()
{
	contact con;
	InitContact(&con);
	AddContact(&con);
	DestroyContact(&con);
}

void menu()
{
	printf("********************通讯录********************\n");
	printf("**********************************************\n");
	printf("*********1.增加联系人   2.删除联系人**********\n");
	printf("*********3.修改联系人   4.查找联系人**********\n");
	printf("*********5.展示联系人   0.   退出   **********\n");

}

int main()
{
	int op = -1;
	contact con;
	InitContact(&con);
	do {
		menu();
		printf("请选择您的操作：\n");
		scanf("%d", &op);
		switch (op) 
		{
		case 1:
			AddContact(&con);
			break;
		case 2:
			DelContact(&con);
			break;
		case 3:
			ModifyContact(&con);
			break;
		case 4:
			FindContact(&con);
			break;
		case 5:
			ShowContact(&con);
			break;
		default:
			break;
		}

	} while (op != 0);
	
	return 0;
}