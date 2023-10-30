#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__
#define _CRT_SECURE_NO_WARNINGS
#define MAX_LENGTH 100

#pragma pack(push, 1)
typedef struct ColumInfo {
	char name[MAX_LENGTH];
	char phone[MAX_LENGTH];
}ColumInfo;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct ListNode {
	struct ColumInfo columinfo;
	struct ListNode* pNext;
}ListNode;
#pragma pack(pop)

void printList(ListNode* head);
ListNode* insertFirstNode(ListNode* head, ColumInfo value);
ListNode* deleteFirstNode(ListNode* head);
ListNode* searchNode(ListNode* head, ColumInfo value);

#endif