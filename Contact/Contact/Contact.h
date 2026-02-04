#pragma once

#define NAME_MAX 100
#define SEX_MAX 4
#define TEL_MAX 11
#define ADDR_MAX 100

//联系人结构体包含了姓名、性别、年龄、电话、地址
typedef struct PersonInfo {
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}peoInfo;//改名字方便使用

typedef struct SeqList contact;


//初始化通讯录

void InitContact(contact* con);

//添加通讯录数据

void AddContact(contact* con);

//删除通讯录数据

void DelContact(contact* con);

//展示通讯录数据

void ShowContact(contact* con);

//查找通讯录数据

void FindContact(contact* con);

//修改通讯录数据

void ModifyContact(contact* con);

//销毁通讯录数据

void DestroyContact(contact* con);