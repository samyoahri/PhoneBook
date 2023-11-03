#include "AVLTree.h"
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

AVLNode* rotateRight(AVLNode* parent) {
	AVLNode* child = parent->pLeft;
	parent->pLeft = child->pRight;
	child->pRight = parent;
	return child;
}
AVLNode* rotateLeft(AVLNode* parent) {
	AVLNode* child = parent->pRight;
	parent->pRight = child->pLeft;
	child->pLeft = parent;
	return child;
}
int getHeight(AVLNode* node) {
	int height = 0;
	if (node != NULL)
		height = 1 + max(getHeight(node->pLeft), getHeight(node->pRight));
	return height;
}
int getBalance(AVLNode* node) {
	if (node == NULL)	return 0;
	return getHeight(node->pLeft) - getHeight(node->pRight);
}
AVLNode* new_AVLNode(ColumInfo value) {
	AVLNode* temp = (AVLNode*)malloc(sizeof(AVLNode));

	strcpy(temp->columinfo.name, value.name);
	strcpy(temp->columinfo.phone, value.phone);

	temp->pLeft = NULL;
	temp->pRight = NULL;

	return temp;
}
AVLNode* insertAVLNode(AVLNode* node, ColumInfo value) {
	if (node == NULL)	return new_AVLNode(value);

	if (strcmp(value.name, node->columinfo.name) < 0)
		node->pLeft = insertAVLNode(node->pLeft, value);
	else if (strcmp(value.name, node->columinfo.name) > 0)
		node->pRight = insertAVLNode(node->pRight, value);
	else
		return node;

	int balanceFactor = getBalance(node);

	//LL타입
	if (balanceFactor > 1 && strcmp(value.name, node->pLeft->columinfo.name) < 0)
		return rotateRight(node);
	//RR타입
	else if (balanceFactor < -1 && strcmp(value.name, node->pRight->columinfo.name) > 0)
		return rotateLeft(node);
	//LR타입
	else if (balanceFactor > 1 && strcmp(value.name, node->pLeft->columinfo.name) < 0) {
		node->pLeft = rotateLeft(node);
		return rotateRight(node);
	}
	//RL타입
	else if (balanceFactor < -1 && strcmp(value.name, node->pRight->columinfo.name) > 0) {
		node->pRight = rotateRight(node);
		return rotateLeft(node);
	}
	return node;

}
// 가장 작은 노드(가장 왼쪽 노드)를 찾는 함수
AVLNode* findMinNode(AVLNode* node) {
	while (node->pLeft != NULL) {
		node = node->pLeft;
	}
	return node;
}
AVLNode* deleteAVLNode(AVLNode* node, ColumInfo value) {
	if (node == NULL)	return node;

	if (strcmp(value.name, node->columinfo.name) < 0)
		node->pLeft = deleteAVLNode(node->pLeft, value);
	else if (strcmp(value.name, node->columinfo.name) > 0)
		node->pRight = deleteAVLNode(node->pRight, value);
	else {
		if (node->pLeft == NULL || node->pRight == NULL) {
			AVLNode* temp = (node->pLeft) ? node->pLeft : node->pRight;

			if (temp == NULL) {
				temp = node;
				node = NULL;
			}
			else {
				*node = *temp;
			}

			free(temp);
		}
		else {
			// 두 개의 자식 노드가 있는 경우
			AVLNode* temp = findMinNode(node->pRight);

			node->columinfo = temp->columinfo;
			node->pRight = deleteAVLNode(node->pRight, temp->columinfo);
		}
	}

	if (node == NULL) {
		return node;
	}

	int balanceFactor = getBalance(node);
	//LL타입
	if (balanceFactor > 1 && strcmp(value.name, node->pLeft->columinfo.name) < 0)
		return rotateRight(node);
	//RR타입
	else if (balanceFactor < -1 && strcmp(value.name, node->pRight->columinfo.name) > 0)
		return rotateLeft(node);
	//LR타입
	else if (balanceFactor > 1 && strcmp(value.name, node->pLeft->columinfo.name) < 0) {
		node->pLeft = rotateLeft(node);
		return rotateRight(node);
	}
	//RL타입
	else if (balanceFactor < -1 && strcmp(value.name, node->pRight->columinfo.name) > 0) {
		node->pRight = rotateRight(node);
		return rotateLeft(node);
	}
	return node;
}
void preorderAVLTree(AVLNode* node) {
	if (node != NULL) {
		printf("[%s][%s] || ", node->columinfo.name, node->columinfo.phone);
		preorderAVLTree(node->pLeft);
		preorderAVLTree(node->pRight);
	}
}

AVLNode* searchAVLNode(AVLNode* root, ColumInfo value) {
	//if (root == NULL)
	//	return NULL; // not found

	//if (strcmp(value.name, root->columinfo.name) < 0)
	//	return search(root->pLeft, value);
	//else if (strcmp(value.name, root->columinfo.name) > 0)
	//	return search(root->pRight, value);
	//else
	//	return root;
	AVLNode* tmp = root;
	while (tmp != NULL) {
		if (compare(value, tmp->columinfo) == 0) {
			return tmp;
		}
		else if (compare(value, tmp->columinfo) < 0) {
			tmp = tmp->pLeft;
		}
		else if (compare(value, tmp->columinfo) > 0) {
			tmp = tmp->pRight;
		}
	}
	return NULL;
}