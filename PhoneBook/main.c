#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include<time.h>
#include "LinkedList.h"
#include "LinkedListTest.h"
#include "BinarySearchTree.h"
#include "BinarySearchTree_Test.h"
//typedef struct ColumInfo {
//	char name[MAX_LENGTH];
//	char phone[MAX_LENGTH];
//}ColumInfo;


int printui() {
	int num = 0;
	//system("cls");
	printf("[1] add\t  [2] search\t  [3] print all\t  [4] remove\t  [0]exit\n");

	scanf_s("%d", &num);

	return num;
}
void inorder1(TreeNode* root) {
	if (root != NULL) {
		inorder1(root->pLeft);
		printf("[naem:%s][phone:%s]", root->columinfo.name, root->columinfo.phone);
		inorder1(root->pRight);
	}
}
void main() {
	//testLinkedList(3);
	
	int nNum = 10;
	
	//ListNode* linkedList = NULL;
	//printf("testLinkedList_insertFirst: %.3f\n", testLinkedList_insertFirst(&linkedList, nNum));
	//printf("testLinkedList_deleteFirst: %.3f\n", testLinkedList_deleteFirst(&linkedList, nNum));
	//testLinkedList_insertFirst(&linkedList, nNum);
	//printf("testLinkedList_search: %.3f\n", testLinkedList_search(&linkedList, nNum));
	
	//printf("================================================\n");
	
	//testBinarySearchTree(nNum);

	//TreeNode* bst = NULL;
	//printf("testBinarySearchTree_insert: %.3f\n", testBinarySearchTree_insert(&bst, nNum));
	//printf("testLinkedList_deleteFirst: %.3f\n", testBinarySearchTree_delete(&bst, nNum));
	//testBinarySearchTree_insert(&bst, nNum);
	//printf("testLinkedList_search: %.3f\n", testBinarySearchTree_search(&bst, nNum));

	//////////////////////////////////////////////////////////////////////////////////////////////////////
	int commandnum = 0;
	////loadlist(data_file_name);
	TreeNode* bst = NULL;
	////testBinarySearchTree_insert(&bst, nNum);
	while ((commandnum = printui()) != 0) {
		char szName[MAX_LENGTH] = { 0 };
		char szPhone[MAX_LENGTH] = { 0 };
		ColumInfo data;
		switch (commandnum) {
		case 1:
			//add();
			printf("add();\n");

			printf("입력할 이름을 적어주세요:");
			scanf("%s", szName);
			printf("입력할 번호를 적어주세요:");
			scanf("%s", szPhone);

			strcpy(data.name, szName);
			strcpy(data.phone, szPhone);

			bst = insertBinarySearchTreeNode(bst, data);
			printf("이름:%s, 번호:%s를 추가하였습니다.\n", szName, szPhone);
			break;
		case 2:
			//search();
			printf("search();\n");

			printf("검색할 이름을 적어주세요:");
			scanf("%s", szName);

			strcpy(data.name, szName);
			szPhone[0] = 0;
			//strcpy(data.phone, szPhone);

			TreeNode* tmp = NULL;
			tmp = searchBinarySearchTreeNode(bst, data);
			if (tmp == NULL) {
				printf("검색한 이름이 존재하지 않습니다.");
			}
			else {
				printf("이름:%s, 번호:%s를 검색하였습니다.\n", tmp->columinfo.name, tmp->columinfo.phone);
			}
			
			break;
		case 3:
			//printall();
			printf("printall();\n");
			//printBianrySearchTreeNode(&bst);
			inorder1(bst);
			printf("\n");
			break;
		case 4:
			//remove();
			printf("remove();\n");

			printf("삭제할 이름을 적어주세요:");
			scanf("%s", szName);

			
			strcpy(data.name, szName);
			strcpy(data.phone, szPhone);

			bst = deleteBinarySearchTreeNode(bst, data);

			break;
		}

	}

}
