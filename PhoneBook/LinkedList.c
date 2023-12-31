#define _CRT_SECURE_NO_WARNINGS
#define MAX_LENGTH 100
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <limits.h>

#include"LinkedList.h"

void printList(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->pNext) {
		printf("|| %s | %s || -> ", p->columinfo.name, p->columinfo.phone);
	}
	printf("NULL\n");
}
ListNode* insertFirstNode(ListNode* head, ColumInfo value) {
	ListNode* added = (ListNode*)malloc(sizeof(ListNode));

	strcpy(added->columinfo.name, value.name);
	strcpy(added->columinfo.phone, value.phone);
	added->pNext = head;

	head = added;

	return added;
}
ListNode* deleteFirstNode(ListNode* head) {
	if (head == NULL)	return NULL;
	ListNode* removed = (ListNode*)malloc(sizeof(ListNode));

	removed = head;
	head = head->pNext;
	free(removed);

	return head;
}
ListNode* searchNode(ListNode* head, ColumInfo value) {
	ListNode* searched = head;
	
	while (strcmp(searched->columinfo.name, value.name) != 0
		&& strcmp(searched->columinfo.phone, value.phone) != 0) {
		if (searched->pNext == NULL) return NULL;
		searched = searched->pNext;
	}
	return searched;
}
