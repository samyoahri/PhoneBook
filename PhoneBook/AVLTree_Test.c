#include "AVLTree_test.h"
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
void testAVLTree(int nNum) {
	AVLNode* root = NULL;
	for (int i = 0; i < nNum; ++i) {
		char sName[MAX_LENGTH];
		char sPhone[MAX_LENGTH];

		sprintf(sName, "samyoahri: %d", i);
		sprintf(sPhone, "010-xxxx-xxxx: %d", i);

		ColumInfo data;
		strcpy(data.name, sName);
		strcpy(data.phone, sPhone);

		root = insertAVLNode(root, data);

		preorderAVLTree(root);
		printf("\n");
		printf("---------------------------------\n");
	}
	printf("====================================\n");
	printf("====================================\n");
	printf("====================================\n");
	for (int i = 0; i < nNum; ++i) {
		char sName[MAX_LENGTH];
		char sPhone[MAX_LENGTH];

		sprintf(sName, "samyoahri: %d", i);
		sprintf(sPhone, "010-xxxx-xxxx: %d", i);

		ColumInfo data;
		strcpy(data.name, sName);
		strcpy(data.phone, sPhone);

		root = deleteAVLNode(root, data);

		preorderAVLTree(root);
		printf("\n");
		printf("---------------------------------\n");
	}
}
double testAVLTree_insert(AVLNode** node, int nNum) {
	clock_t start = clock();
	for (int i = 0; i < nNum; ++i) {
		char sName[MAX_LENGTH];
		char sPhone[MAX_LENGTH];

		sprintf(sName, "samyoahri: %d", i);
		sprintf(sPhone, "010-xxxx-xxxx: %d", i);

		ColumInfo data;
		strcpy(data.name, sName);
		strcpy(data.phone, sPhone);

		*node = insertAVLNode(*node, data);
	}
	clock_t end = clock();
	return (double)(end - start) / CLOCKS_PER_SEC;
}
double testAVLTree_delete(AVLNode** root, int nNum) {
	clock_t start = clock();
	for (int i = 0; i < nNum; ++i) {
		char sName[MAX_LENGTH];
		char sPhone[MAX_LENGTH];

		sprintf(sName, "samyoahri: %d", i);
		sprintf(sPhone, "010-xxxx-xxxx: %d", i);

		ColumInfo data;
		strcpy(data.name, sName);
		strcpy(data.phone, sPhone);

		*root = deleteAVLNode(*root, data);
	}
	clock_t end = clock();
	return (double)(end - start) / CLOCKS_PER_SEC;
}

double testAVLTree_search(AVLNode** root, int nNum) {
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
		AVLNode* tmp = searchAVLNode(*root, data);
		if (strcmp(tmp->columinfo.name, szName) == 0) {
			++cnt;
		}
	}
	clock_t end = clock();
	printf("testAVLTree_search Ã£Àº°¹¼ö: %d\n", cnt);
	return (double)(end - start) / CLOCKS_PER_SEC;
}