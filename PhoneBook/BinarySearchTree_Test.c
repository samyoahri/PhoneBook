#include "BinarySearchTree.h"
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
void testBinarySearchTree(int nNum) {
	TreeNode* root = NULL;

	printf("===================insert===================\n");
	for (int i = 0; i < nNum; ++i) {
		char sName[MAX_LENGTH];
		char sPhone[MAX_LENGTH];

		sprintf(sName, "samyoahri: %d", i);
		sprintf(sPhone, "010-xxxx-xxxx: %d", i);

		ColumInfo data;
		strcpy(data.name, sName);
		strcpy(data.phone, sPhone);

		root = insertBinarySearchTreeNode(root, data);
		inorder(root);
		printf("\n");
	}
	printf("======================================\n");
	inorder(root);
	printf("======================================\n");
	printf("\n");
	printf("===================delete===================\n");
	for (int i = 0; i < nNum; ++i) {
		char sName[MAX_LENGTH];
		char sPhone[MAX_LENGTH];

		sprintf(sName, "samyoahri: %d", nNum - i);
		sprintf(sPhone, "010-xxxx-xxxx: %d", nNum - i);

		ColumInfo data;
		strcpy(data.name, sName);
		strcpy(data.phone, sPhone);

		root = deleteBinarySearchTreeNode(root, data);

		inorder(root);
		printf("--------------------------------------------\n");
	}
}
double testBinarySearchTree_insert(TreeNode** node, int nNum) {
	clock_t start = clock();
	for (int i = 0; i < nNum; ++i) {
		char sName[MAX_LENGTH];
		char sPhone[MAX_LENGTH];

		sprintf(sName, "samyoahri: %d", i);
		sprintf(sPhone, "010-xxxx-xxxx: %d", i);

		ColumInfo data;
		strcpy(data.name, sName);
		strcpy(data.phone, sPhone);

		*node = insertBinarySearchTreeNode(*node, data);
	}
	clock_t end = clock();
	return (double)(end - start) / CLOCKS_PER_SEC;
}
double testBinarySearchTree_delete(TreeNode** root, int nNum) {
	clock_t start = clock();
	for (int i = 0; i < nNum; ++i) {
		char sName[MAX_LENGTH];
		char sPhone[MAX_LENGTH];

		sprintf(sName, "samyoahri: %d", i);
		sprintf(sPhone, "010-xxxx-xxxx: %d", i);

		ColumInfo data;
		strcpy(data.name, sName);
		strcpy(data.phone, sPhone);

		*root = insertBinarySearchTreeNode(*root, data);
	}
	clock_t end = clock();
	return (double)(end - start) / CLOCKS_PER_SEC;
}
double testBinarySearchTree_search(TreeNode** root, int nNum) {
	clock_t start = clock();
	for (int i = 0; i < nNum; ++i) {
		

		//inorder(root);
		//printf("--------------------------------------------\n");
	}
	clock_t end = clock();
	return (double)(end - start) / CLOCKS_PER_SEC;
}