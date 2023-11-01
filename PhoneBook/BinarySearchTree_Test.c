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

		*root = deleteBinarySearchTreeNode(*root, data);
	}
	clock_t end = clock();
	return (double)(end - start) / CLOCKS_PER_SEC;
}

double testBinarySearchTree_search(TreeNode** root, int nNum) {
	int cnt = 0;
	clock_t start = clock();
	for (int i = 0; i < nNum; ++i) {
		//search();
		//printf("search();\n");
		char szName[MAX_LENGTH];
		char szPhone[MAX_LENGTH];
		ColumInfo data;

		sprintf(szName, "samyoahri: %d", i);
		sprintf(szPhone, "010-xxxx-xxxx: %d", i);

		strcpy(data.name, szName);
		strcpy(data.phone, szPhone);

		//*root = searchBinarySearchTreeNode(*root, data);

		//TreeNode* tmp = *root;
		TreeNode* tmp = searchBinarySearchTreeNode(*root, data);
		if (strcmp(tmp->columinfo.name, szName) == 0) {
			++cnt;
		}
	}
	clock_t end = clock();
	printf("testBST_search Ã£Àº°¹¼ö: %d\n", cnt);
	return (double)(end - start) / CLOCKS_PER_SEC;
}