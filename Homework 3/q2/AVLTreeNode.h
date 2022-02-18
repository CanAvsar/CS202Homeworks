/*
 * Title: Heaps and AVL Trees
 * Author: Can Avşar
 * ID: 21902111
 * Section: 1
 * Assignment: 3
 * Description: AVLTreeNode.h
 */

#ifndef AVLTreeNode_h
#define AVLTreeNode_h

#include <iostream>
using namespace std;


class AVLTreeNode
{
private:
    
    AVLTreeNode()
    {
    }
    
    AVLTreeNode(int& item, int height, AVLTreeNode* leftChild = NULL, AVLTreeNode* rightChild = NULL): item(item),
    height(height), leftChild(leftChild), rightChild(rightChild)
    {
    }
    
    int item; // Data of the node
    int height; // Height of the tree
    AVLTreeNode* leftChild; // Pointer to the left child
    AVLTreeNode* rightChild; // Pointer to the right child
    
    friend class AVLTree;
        
};

#endif /* AVLTreeNode_h */
