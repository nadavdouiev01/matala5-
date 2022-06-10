#define CRT_SECURE_NO_WARNINGS
#define SIZE 10
#include "BST.h"
#include "TreePrintLibrary.h"


void main() 
{
	printf("BINAR TREE ===> \n");
	BST maintree;
	BST *pointertotree = &maintree;
	int k = 6;
	int y;
	initBST(&maintree);
	insertBST(&maintree, 15);
	insertBST(&maintree, 12);
	insertBST(&maintree, 23);
	insertBST(&maintree, 7);
	insertBST(&maintree, 22);
	insertBST(&maintree, 13);
	insertBST(&maintree, 1);
	insertBST(&maintree, 4);
	insertBST(&maintree, 17);
	insertBST(&maintree, 8);
	insertBST(&maintree, 24);

	//for (int i = 0; i < SIZE; i++) {
	//	scanf("%d",&y);
	//	insertBST(&maintree,y);
	//}
	//

	printTreeInorder(&maintree);
	int A = findIndexNFromLast(&maintree,k);

	printf("the NUM is=> %d \n", A);

	int num = sameHeightLeaves(&maintree);

	if (num == 1) {

		printf("*****is THE SAME****\n");

	}

	else printf("****is NOT  the same****\n");

	printf("\n");
	
	/*print_ascii_tree(pointeroftree);*/

	destroyBST(pointertotree);
	
}