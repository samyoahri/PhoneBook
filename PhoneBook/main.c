#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "LinkedList.h"
#include "LinkedListTest.h"



int printui() {
	int num = 0;
	system("cls");
	printf("[1] add\t  [2] search\t  [3] print all\t  [4] remove\t  [0]exit\n");

	scanf_s("%d", &num);

	return num;
}
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void main() {
	//int a = 10, b = 20;
	//swap(&a, &b);
	//printf("a:%d, b:%d", a, b);
	//testLinkedList(3);
	int nNum = 3;
	ListNode* linkedList1 = NULL;
	//ListNode* linkedList1 = (ListNode*)malloc(sizeof(ListNode));
	//linkedList1 = NULL;
	//ListNode* linkedList1 = (ListNode*)malloc(sizeof(ListNode));
	//memset(linkedList1, NULL, sizeof(ListNode));
	ListNode* linkedList2 = NULL;
	printf("testLinkedList_insertFirst: %.3f\n", testLinkedList_insertFirst(linkedList1, nNum));
	printf("testLinkedList_deleteFirst: %.3f", testLinkedList_deleteFirst(linkedList2, nNum));
	//ListNode* linkedList = NULL;
	//printf("testLinkedList_insertFirst: %.3f\n", testLinkedList_insertFirst(linkedList, nNum));
	//
	//ListNode* node = linkedList;
	//for (int i = 0; i < nNum; ++i) {
	//	char name[MAX_LENGTH] = "samyoahri";
	//	char phone[MAX_LENGTH] = "010-xxxx-xxxx";

	//	sprintf(name, "samyoahri: %d", i);
	//	sprintf(phone, "010-xxxx-xxxx: %d", i);

	//	ColumInfo data;
	//	strcpy(data.name, name);
	//	strcpy(data.phone, phone);

	//	ListNode* tmp = node;
	//	//while (1) {
	//	//	if (strcmp(tmp->columinfo.name, data.name)==1)	break;
	//	//}
	//	while((strcmp(data.name, tmp->columinfo.name) != 1) || (strcmp(data.phone, tmp->columinfo.phone) != 1)) {
	//		if (tmp->pNext == NULL) {
	//			printf("search failed\n");
	//		}
	//		tmp = tmp->pNext;
	//	}
	//	printf("data.name: %s, tmp->columinfo.name: %s\n", data.name, tmp->columinfo.name);
	//	printf("data.phone: %s, tmp->columinfo.phone: %s\n", data.phone, tmp->columinfo.phone);
		//printList(node);
		//printf("==============\n");
	//}
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	//int commandnum = 0;
	////loadlist(data_file_name);

	//while ((commandnum = printui()) != 0) {
	//	switch (commandnum) {
	//	case 1:
	//		//add();
	//		printf("add();\n");
	//		break;
	//	case 2:
	//		//search();
	//		printf("search();\n");
	//		break;
	//	case 3:
	//		//printall();
	//		printf("printall();\n");
	//		break;
	//	case 4:
	//		//remove();
	//		printf("remove();\n");
	//		break;
	//	}

	//}

}
