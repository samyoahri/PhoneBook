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

		head = insertFirst(head, data);
		printList(head);
		printf("\n");
	}
	printf("===========================================================================================================================================================\n");
	for (int i = 0; i < nNum; ++i) {
		head = deleteFirst(head);
		printList(head);
		printf("\n");
	}
	return 0;
}


double testLinkedList_insertFirst(ListNode* node, int nNum) {
	clock_t start = clock();

	for (int i = 0; i < nNum; ++i) {
		char name[MAX_LENGTH] = "samyoahri";
		char phone[MAX_LENGTH] = "010-xxxx-xxxx";

		sprintf(name, "samyoahri: %d", i);
		sprintf(phone, "010-xxxx-xxxx: %d", i);

		ColumInfo data;
		strcpy(data.name, name);
		strcpy(data.phone, phone);

		node = insertFirst(node, data);
		//printList(node);
		//printf("==============\n");
	}
	clock_t end = clock();
	return (double)(end - start) / CLOCKS_PER_SEC;
}
double testLinkedList_deleteFirst(ListNode* node, int nNum) {
	for (int i = 0; i < nNum; ++i) {
		char name[MAX_LENGTH] = "samyoahri";
		char phone[MAX_LENGTH] = "010-xxxx-xxxx";

		sprintf(name, "samyoahri: %d", i);
		sprintf(phone, "010-xxxx-xxxx: %d", i);

		ColumInfo data;
		strcpy(data.name, name);
		strcpy(data.phone, phone);

		node = insertFirst(node, data);
		//printList(node);
		//printf("==============\n");
	}
	clock_t start = clock();

	for (int i = 0; i < nNum; ++i) {
		node = deleteFirst(node);
		//printList(node);
		//printf("==============\n");
	}
	clock_t end = clock();
	return (double)(end - start) / CLOCKS_PER_SEC;
}