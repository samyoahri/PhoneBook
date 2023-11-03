#ifndef __AVL_TREE_H__
#define __AVL_TREE_H__
#include "LinkedList.h"
typedef struct AVLNode {
	//struct ColumInfo;
	struct ColumInfo columinfo;
	struct AVLNode* pRight;
	struct AVLNode* pLeft;
}AVLNode;

AVLNode* rotateRight(AVLNode* parent);
AVLNode* rotateLeft(AVLNode* parent);
int getHeight(AVLNode* node);
int getBalance(AVLNode* node);
AVLNode* new_AVLNode(ColumInfo value);
AVLNode* insertAVLNode(AVLNode* node, ColumInfo value);
AVLNode* findMinNode(AVLNode* node);
AVLNode* deleteAVLNode(AVLNode* node, ColumInfo value);
void preorderAVLTree(AVLNode* node);
AVLNode* searchAVLNode(AVLNode* root, ColumInfo value);
#endif
