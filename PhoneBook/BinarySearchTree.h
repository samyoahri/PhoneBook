#ifndef __BINARYSEARCHTREE_H__
#define __BINARYSEARCHTREE_H__
#define MAX_LENGTH 100
#pragma pack(push, 1)
#include "LinkedList.h"
//typedef struct ColumInfo {
//	char name[MAX_LENGTH];
//	char phone[MAX_LENGTH];
//}ColumInfo;
//#pragma pack(pop)

#pragma pack(push, 1)
typedef struct TreeNode {
	struct ColumInfo columinfo;
	struct TreeNode* pLeft, *pRight;
}TreeNode;
#pragma pack(pop)


void inorder(TreeNode* root);
void printBianrySearchTreeNode(TreeNode** node);
TreeNode* new_node(ColumInfo value);
TreeNode* insertBinarySearchTreeNode(TreeNode* node, ColumInfo value);
TreeNode* min_value_node(TreeNode* node);
TreeNode* deleteBinarySearchTreeNode(TreeNode* root, ColumInfo value);
TreeNode* searchBinarySearchTreeNode(TreeNode* root, ColumInfo value);
#endif