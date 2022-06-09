#ifndef _BST_ADT_H
#define _BST_ADT_H

typedef struct TreeNode TreeNode;

struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int element;
};

typedef struct BST
{
	TreeNode* root;
}BST;

#endif // !_BST_ADT_H
void initBST(BST* bst);
void insertBST(BST* bst, int value);
void InsTreeNode(TreeNode* root, TreeNode* newNode);
void printTNode(TreeNode* root);
void printTreeInorder(BST* bst);
void destroyBST(BST* bst);
int findIndexNFromLast(BST* bst, int N);
int sameHeightLeaves(BST* bst);
TreeNode* NewNode(int value);
void freeTree(TreeNode* node);