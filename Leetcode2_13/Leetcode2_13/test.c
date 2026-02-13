#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


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

void InOrder(TNode* root)
{
    if (root == NULL)
        return;

    InOrder(root->left);
    printf("%c ", root->val);
    InOrder(root->right);


}




int main() {
    char a[100];
    scanf("%s",a);
    int end = 0;
    TNode* root = TreeCreate(a, &end);
    
    InOrder(root);

    return 0;
}

