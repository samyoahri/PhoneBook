#ifndef __AVLTREE_TEST_H__
#define __AVLTREE_TEST_H__
#include "AVLTree.h"

void testAVLTree(int nNum);

double testAVLTree_insert(AVLNode** node, int nNum);
double testAVLTree_delete(AVLNode** node, int nNum);
double testAVLTree_search(AVLNode** node, int nNum);
#endif