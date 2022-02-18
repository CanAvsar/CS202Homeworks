/*
 * Title: Heaps and AVL Trees
 * Author: Can Avşar
 * ID: 21902111
 * Section: 1
 * Assignment: 3
 * Description: AVLTree.h
 */

#ifndef AVLTree_h
#define AVLTree_h

#include "AVLTreeNode.h"

class AVLTree
{
public:
    AVLTree();

    void insert(int value);
    int numberOfRotations();
    
    AVLTreeNode* insertNode(AVLTreeNode* treeNode, int value);
    AVLTreeNode* createNewNode(int value);
    int getNumberOfRotations();
    int maximum(int first, int second);
    int getNodeHeight(AVLTreeNode* node);
    int getNodeBalance(AVLTreeNode* node);
    AVLTreeNode* rotateRight(AVLTreeNode* node);
    AVLTreeNode* rotateLeft(AVLTreeNode* node);
    void resetRotations();

    
    
private:
    AVLTreeNode* root;
    int rotationCount;
    
};

#endif /* AVLTree_h */
