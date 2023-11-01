#include "LinkedListTest.h"
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

void testLinkedList(int nNum) {
	if (nNum > 10 && nNum < 0) {
		printf("nNum은 0이상 10이하여야 합니다.\n");
		return 0;
	}
	ListNode* head = NULL;
	for (int i = 0; i < nNum; ++i) {
		char name[MAX_LENGTH] = "samyoahri";
		char phone[MAX_LENGTH] = "010-xxxx-xxxx";

		sprintf(name, "samyoahri: %d", i);
		sprintf(phone, "010-xxxx-xxxx: %d", i);

		ColumInfo data;
		strcpy(data.name, name);
		strcpy(data.phone, phone);

		head = insertFirstNode(head, data);
		printList(head);
		printf("\n");
	}
	printf("===========================================================================================================================================================\n");
	for (int i = 0; i < nNum; ++i) {
		head = deleteFirstNode(head);
		printList(head);
		printf("\n");
	}
	return 0;
}


double testLinkedList_insertFirst(ListNode** node, int nNum) {
	clock_t start = clock();

	for (int i = 0; i < nNum; ++i) {
		char name[MAX_LENGTH] = "samyoahri";
		char phone[MAX_LENGTH] = "010-xxxx-xxxx";

		sprintf(name, "samyoahri: %d", i);
		sprintf(phone, "010-xxxx-xxxx: %d", i);

		ColumInfo data;
		strcpy(data.name, name);
		strcpy(data.phone, phone);

		*node = insertFirstNode(*node, data);
		//printList(node);
		//printf("==============\n");
	}
	clock_t end = clock();
	return (double)(end - start) / CLOCKS_PER_SEC;
}
double testLinkedList_deleteFirst(ListNode** node, int nNum) {
	clock_t start = clock();

	for (int i = 0; i < nNum; ++i) {
		*node = deleteFirstNode(*node);
		//printList(node);
		//printf("==============\n");
	}
	clock_t end = clock();
	return (double)(end - start) / CLOCKS_PER_SEC;
}
double testLinkedList_search(ListNode** node, int nNum) {
	int cnt = 0;
	clock_t start = clock();
	for (int i = 0; i < nNum; ++i) {
		char name[MAX_LENGTH] = "samyoahri";
		char phone[MAX_LENGTH] = "010-xxxx-xxxx";

		sprintf(name, "samyoahri: %d", i);
		sprintf(phone, "010-xxxx-xxxx: %d", i);
		ListNode* tmp = *node;
		while (strcmp(name, tmp->columinfo.name) != 0
			&& strcmp(phone, tmp->columinfo.phone) != 0) {
			if (tmp->pNext == NULL)	break;
			tmp = tmp->pNext;
		}
		if (strcmp(name, tmp->columinfo.name) == 0) ++cnt;
	}
	clock_t end = clock();
	printf("testLinkedList_search 찾은갯수: %d\n", cnt);
	return (double)(end - start) / CLOCKS_PER_SEC;
}