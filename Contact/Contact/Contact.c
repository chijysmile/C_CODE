#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"
#include "Contact.h"
//实现通讯录方法


//通讯录的初始化实际上就是顺序表的初始化
//直接调用顺序表初始化方法
void InitContact(contact* con)
{
	SLInit(con);
}


//通讯录的销毁
void DestroyContact(contact* con)
{
	SLDestory(con);
}


//通讯录的添加
void AddContact(contact* con) {
	peoInfo info;
	printf("请输入要添加的联系人姓名：\n");
	scanf("%s", info.name);
	printf("请输入要添加的联系人性别：\n");
	scanf("%s", info.sex);
	printf("请输入要添加的联系人年龄：\n");
	scanf("%d", &info.age);
	printf("请输入要添加的联系人电话：\n");
	scanf("%s", info.tel);
	printf("请输入要添加的联系人地址：\n");
	scanf("%s", info.addr);
	//以上代码实现创建一个联系人变量并通过输入初始化好
	//为后面的pushback到通讯录顺序表做准备
	SLPushBack(con, info);
}

//按照名字查找方法，查出数据所对应的下标，返回下标
//如果数据不存在就返回一个小于0的值，-1
int FindByName(contact* con, char name[])
{
	for (int i = 0; i < con->size; i++)
	{
		if (0 == strcmp(con->arr[i].name, name))
		{
			return i;
		}
	}
	return -1;
}


//通讯录的删除
void DelContact(contact* con)
{
	//删除联系人
	//删除指定的联系人
	//先要找到联系人位置
	//通过联系人下标删除
	//如何联系人不存在就返回一个-1,代表联系人不存在
	char name[NAME_MAX];
	printf("请输入要删除的联系人姓名:\n");
	scanf("%s", name);
	int find = FindByName(con, name);
	if (find == -1)
	{
		printf("要删除的联系人数据不存在!\n");
		return;
	}
	SLErase(con,find);
	printf("删除成功！\n");
}

//通讯录的查找
void FindContact(contact* con)
{
	char name[NAME_MAX];
	printf("请输入要查找的联系人姓名:\n");
	scanf("%s", name);
	int find=FindByName(con, name);
	if (find < 0)
	{
		printf("要查找的联系人数据不存在！\n");
		return;
	}
	printf("%s %s %s %s %s\n", "姓名.", "性别", "年龄", "电话", "地址");
	printf("%3s %3s %3d %3s %3s\n",//手动调整一下格式
		con->arr[find].name,
		con->arr[find].sex,
		con->arr[find].age,
		con->arr[find].tel,
		con->arr[find].addr);

}

//通讯录的修改
void ModifyContact(contact* con)
{
	char name[NAME_MAX];
	printf("请输入你要修改的联系人的姓名!\n");
	scanf("%s", name);
	int find = FindByName(con, name);
	if (find < 0)
	{
		printf("要修改的联系人数据不存在！\n");
	}
	//直接修改
	printf("请输入新的姓名：\n");
	scanf("%s", con->arr[find].name);
	printf("请输入新的性别：\n");
	scanf("%s", con->arr[find].sex);
	printf("请输入新的年龄：\n");
	scanf("%d", &con->arr[find].age);
	printf("请输入新的电话：\n");
	scanf("%s", con->arr[find].tel);
	printf("请输入新的地址：\n");
	scanf("%s", con->arr[find].addr);
	printf("修改成功!\n");

}


//通讯录的展示
void ShowContact(contact* con)
{
	//先打印表头
	printf("%s %s %s %s %s\n", "姓名.", "性别", "年龄", "电话", "地址");
	for (int i = 0; i < con->size; i++)
	{
		printf("%3s %3s %3d %3s %3s\n",//手动调整一下格式
			con->arr[i].name,
			con->arr[i].sex,
			con->arr[i].age,
			con->arr[i].tel,
			con->arr[i].addr);
	}

}

