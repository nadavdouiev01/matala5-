#include<stdio.h>
#include"BST.h"
#include"TreePrintLibrary.h"

#define TEST(op) do{if (op == NULL){printf("the malloc not sacecess");exit(1);}}while(0) //������� ����� ������ ��� ������ ������ 

void initBST(BST* bst)
{
	bst->root = NULL;
}

TreeNode* NewNode(int value)  
{
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode)); //������� ������ ����� 
	TEST(&newNode);
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->element = value;
	return newNode;
}


void insertBST(BST* bst, int value) {  //  ������� ������� �� ������� ��� �������
	TreeNode* newNode = NewNode(value);
	if (bst->root == NULL) //�� ��� ���  ���� �� ��� ��� 
		bst->root = newNode;
	else
		InsTreeNode(bst->root, newNode); //�� ���� �� ��� ����� ������ ��� ����� ����� �����

}
void InsTreeNode(TreeNode* root, TreeNode* newNode) { //�� ���� �� ��� ����� ������ ��� ����� ����� �����
	    if (newNode->element <= root->element)
		if (root->left == NULL)
			root->left = newNode;
		else
			InsTreeNode(root->left, newNode);
	    if (newNode->element > root->element) {
		if (root->right == NULL)
			root->right = newNode;
		else
			InsTreeNode(root->right, newNode);
	  }
   }


void printTreeInorder(BST* bst) //������� ����� ��� 
{ 
	if (bst->root != NULL)
	{
		printTNode(bst->root);
		print_ascii_tree(bst->root); //����� ��������  ������ TREEPRINTLIBRARY
	}
	else
	{
		printf("**********EMPTY TREE*********\n"); 
	}
}

void printTNode(TreeNode* root) {  //   ������� ����� ������ ���� ����� (��������� 
	if (root != NULL)
	{
		printTNode(root->left);
		printTNode(root->right);
		
	}
}


int findIndexNFromLast(BST* bst, int N) {   //������� ������� �� ���� ����� ���� �N
	int index = findINDEXFROMROOT(bst->root, N);
	return index;
}

int findINDEXFROMROOT(TreeNode* root, int N) {
	if (root == NULL) {
		return ;
	}
	int X = 1+findINDEXFROMROOT(root->right, N);
	if (X == N) {
		return root->element;
	}
	int search = 1 + findINDEXFROMROOT(root->left, N);
}



int sameHeightLeaves(BST* bst) { //�������  ������ ��� �� ����� ��� ����� ��� 
	int num = SameHEIGHT(bst->root);
	return num;
}

int SameHEIGHT(TreeNode* root) {
	if (root == NULL)
		return 0;
	int theleftside = 1+SameHEIGHT(root->left);
	int therightside =1+SameHEIGHT(root->right);
	if (theleftside == therightside) {
		return 1;
	}
	else

		return NULL;
}


void freeTree(TreeNode* node)//����� ����� 
{
	if (node != NULL)
	{
		freeTree(node->right);
		freeTree(node->left);
		free(node);
	}
}

void destroyBST(BST* bst) //������� ����� ���
{
	if (bst->root == NULL)
		return;
	else
		freeTree(bst->root);
}
