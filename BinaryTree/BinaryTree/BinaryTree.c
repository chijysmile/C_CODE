#define _CRT_SECURE_NO_WARNINGS

#include "BinaryTree.h"



//创造结点
BTNode* BuyNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	node->val = x;
	node->left = NULL;
	node->right = NULL;
	return node;

}


//前序遍历
void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N");
		return;
	}

	printf("%d ", root->val);
	PrevOrder(root->left);
	PrevOrder(root->right);
}



//中序遍历
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N");
		return;
	}

	PrevOrder(root->left);
	printf("%d ", root->val);
	PrevOrder(root->right);
}




//二叉树高度
int BTHight(BTNode* root) {
	if (root == NULL)
		return 0;

	int tmp1 = BTHight(root->left);
	int tmp2 = BTHight(root->right);
	if (tmp1 > tmp2)
		return tmp1 + 1;
	else
		return tmp2 + 1;
}



//二叉树结点个数
int BTSize(BTNode* root)
{
	/*if (root == NULL)
		return 0;

	return BTSize(root->left) + BTSize(root->right) + 1;*/
	//代码优化：
	return root == NULL ? 0: BTSize(root->left) + BTSize(root->right) + 1;

}


//二叉树叶子结点个数
int BTLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;

	return BTLeafSize(root->left) + BTLeafSize(root->right);

}

//第K层结点个数
int BTLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k != 1)
		return BTLevelKSize(root->left, k - 1) + BTLevelKSize(root->right, k - 1);
	if (k == 1)
		return 1;
}


//寻找值为x的结点
BTNode* BTFind(BTNode* root, int x)
{
	if (root == NULL)
		return NULL;
	if (root->val == x)
		return root;
	BTNode* Node1 = BTFind(root->left, x);
	if (Node1)
		return Node1;
	BTNode* Node2 = BTFind(root->right, x);
	if (Node2)
		return Node2;

	return NULL;
}


//二叉树的创建代码
//ABD##E#H##CF##G##
typedef struct TreeNode TNode;

struct TreeNode {
	char val;
	TNode* left;
	TNode* right;

};

TNode* TreeCreate(char* a, int* n)
{
	if (a[*n] == '#')
	{
		(*n)++;
		return NULL;
	}


	TNode* root = (TNode*)malloc(sizeof(TNode));

	root->val = a[(*n)++];
	root->left = TreeCreate(a, n);
	root->right = TreeCreate(a, n);

	return root;
}

void CharInOrder(TNode* root)
{
	if (root == NULL)
		return;

	CharInOrder(root->left);
	printf("%c ", root->val);
	CharInOrder(root->right);


}

//二叉树的销毁
void BTDestroy(BTNode* root)
{
	if (root == NULL)
		return;
	BTDestroy(root->left);
	BTDestroy(root->right);
	free(root);

}