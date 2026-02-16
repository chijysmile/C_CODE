#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType val;

}BTNode;




BTNode* BuyNode(BTDataType x);

void PrevOrder(BTNode* root);

void InOrder(BTNode* root);

int BTHight(BTNode* root);

int BTSize(BTNode* root);

int BTLeafSize(BTNode* root);

int BTLevelKSize(BTNode* root, int k);


