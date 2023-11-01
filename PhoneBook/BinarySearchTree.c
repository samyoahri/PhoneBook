#define _CRT_SECURE_NO_WARNINGS
#define MAX_LENGTH 100
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <limits.h>
#include "BinarySearchTree.h";

void inorder(TreeNode* root) {
	if (root!=NULL) {
		inorder(root->pLeft);
		printf("[naem:%s][phone:%s]", root->columinfo.name, root->columinfo.phone);
		inorder(root->pRight);
	}
}
//void printBianrySearchTreeNode(TreeNode** node) {
//	if (node != NULL) {
//		inorder(node->pLeft);
//		printf("[naem:%s][phone:%s]", node->columinfo.name, node->columinfo.phone);
//		inorder(node->pRight);
//	}
//	
//}
TreeNode* new_node(ColumInfo value) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));

	strcpy(temp->columinfo.name, value.name);
	strcpy(temp->columinfo.phone, value.phone);

	temp->pLeft = NULL;
	temp->pRight = NULL;

	return temp;
}
TreeNode* insertBinarySearchTreeNode(TreeNode* node, ColumInfo value) {

	if (node == NULL)	return new_node(value);

	if (strcmp(value.name, node->columinfo.name) < 0) {
		node->pLeft = insertBinarySearchTreeNode(node->pLeft, value);
	}
	else if (strcmp(value.name, node->columinfo.name) > 0) {
		node->pRight = insertBinarySearchTreeNode(node->pRight, value);
	}
	return node;
}
TreeNode* min_value_node(TreeNode* node) {
	TreeNode* curr = node;

	while (curr->pLeft != NULL)
		curr = curr->pLeft;

	return curr;
}
TreeNode* deleteBinarySearchTreeNode(TreeNode* root, ColumInfo value) {

	if (root == NULL)	return NULL;

	if (strcmp(value.name, root->columinfo.name) < 0)
		root->pLeft = deleteBinarySearchTreeNode(root->pLeft, value);
	else if (strcmp(value.name, root->columinfo.name) > 0)
		root->pRight = deleteBinarySearchTreeNode(root->pRight, value);
	else {
		if (root->pLeft == NULL) {
			TreeNode* temp = root->pRight;
			free(root);
			return temp;
		}
		else if (root->pRight == NULL) {
			TreeNode* temp = root->pLeft;
			free(root);
			return temp;
		}
		TreeNode* temp = min_value_node(root->pRight);

		strcpy(root->columinfo.name, temp->columinfo.name);
		strcpy(root->columinfo.phone, temp->columinfo.phone);

		root->pRight = deleteBinarySearchTreeNode(root->pRight, temp->columinfo);
	}
	return root;
}
int compare(ColumInfo col1, ColumInfo col2) {
	return (strcmp(col1.name, col2.name));
}
TreeNode* searchBinarySearchTreeNode(TreeNode* root, ColumInfo value) {
	TreeNode* tmp = root;
	while (tmp != NULL) {
		if (compare(value, tmp->columinfo)==0) {
			return tmp;
		}
		else if(compare(value, tmp->columinfo) < 0){
			tmp = tmp->pLeft;
		}
		else if (compare(value, tmp->columinfo) > 0) {
			tmp = tmp->pRight;
		}
	}
	return NULL;
}