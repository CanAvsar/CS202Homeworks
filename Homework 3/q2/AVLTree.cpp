/*
 * Title: Heaps and AVL Trees
 * Author: Can Avşar
 * ID: 21902111
 * Section: 1
 * Assignment: 3
 * Description: AVLTree.cpp
 */

#include <stdio.h>
#include "AVLTree.h"

AVLTree::AVLTree(): root(NULL), rotationCount(0)
{
}

void AVLTree::insert(int value)
{
    root = insertNode(root, value);
}

AVLTreeNode* AVLTree::insertNode(AVLTreeNode* treeNode, int value)
{
    // Make insertion
    
    if (treeNode == NULL)
    {
        return(createNewNode(value));
    }
    
    if (value < treeNode->item)
    {
        treeNode->leftChild = insertNode(treeNode->leftChild, value);
    }
    
    else if (value > treeNode->item)
    {
        treeNode->rightChild = insertNode(treeNode->rightChild, value);
    }
    
    else
    {
        return treeNode;
    }
    
    // Make rotations after insertion
    
    treeNode->height = maximum(getNodeHeight(treeNode->leftChild), getNodeHeight(treeNode->rightChild)) + 1;
    int nodeBalance = getNodeBalance(treeNode);
    
    if(nodeBalance < -1)
    {
        // Single Left Rotation
        if (value > treeNode->rightChild->item)
        {
            rotationCount = rotationCount + 1;
            return rotateLeft(treeNode);
        }
        
        // Right-Left Rotation
        if (value < treeNode->rightChild->item)
        {
            rotationCount = rotationCount + 2;
            treeNode->rightChild = rotateRight(treeNode->rightChild);
            return rotateLeft(treeNode);
        }
    }
    
    if(nodeBalance > 1)
    {
        // Single Right Rotation
        if (value < treeNode->leftChild->item)
        {
            rotationCount = rotationCount + 1;
            return rotateRight(treeNode);
        }
        
        // Left-Right Rotation
        if (value > treeNode->leftChild->item)
        {
            rotationCount = rotationCount + 2;
            treeNode->leftChild = rotateLeft(treeNode->leftChild);
            return rotateRight(treeNode);
        }
    }
    
    return treeNode;
}

AVLTreeNode* AVLTree::createNewNode(int value)
{
    // Create new node
    AVLTreeNode* newNode = new AVLTreeNode();
    
    // Initialize properties
    newNode->item = value;
    newNode->height = 1;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    
    // Return new node
    return newNode;
}


int AVLTree::numberOfRotations()
{
    return rotationCount;
}

int AVLTree::maximum(int first, int second)
{
    if(first > second)
    {
        return first;
    }
    else
    {
        return second;
    }
}

int AVLTree::getNodeHeight(AVLTreeNode* treeNode)
{
    if(treeNode == NULL)
    {
        return 0;
    }
    return treeNode->height;
}

int AVLTree::getNumberOfRotations()
{
    return rotationCount;
}

int AVLTree::getNodeBalance(AVLTreeNode* treeNode)
{
    if (treeNode == NULL)
    {
        return 0;
    }
    return getNodeHeight(treeNode->leftChild) - getNodeHeight(treeNode->rightChild);
}

AVLTreeNode* AVLTree::rotateRight(AVLTreeNode* treeNode)
{
    AVLTreeNode* leftNode = treeNode->leftChild;
    AVLTreeNode* tempNode = leftNode->rightChild;
    
    leftNode->rightChild = treeNode;
    treeNode->leftChild = tempNode;
    
    treeNode->height = maximum(getNodeHeight(treeNode->leftChild), getNodeHeight(treeNode->rightChild)) + 1;
    leftNode->height = maximum(getNodeHeight(leftNode->leftChild), getNodeHeight(leftNode->rightChild)) + 1;
    
    return leftNode;
}

AVLTreeNode* AVLTree::rotateLeft(AVLTreeNode* treeNode)
{
    AVLTreeNode* rightNode = treeNode->rightChild;
    AVLTreeNode* tempNode = rightNode->leftChild;

    rightNode->leftChild = treeNode;
    treeNode->rightChild = tempNode;
    
    treeNode->height = maximum(getNodeHeight(treeNode->leftChild), getNodeHeight(treeNode->rightChild)) + 1;
    rightNode->height = maximum(getNodeHeight(rightNode->leftChild), getNodeHeight(rightNode->rightChild)) + 1;
    
    return rightNode;
}

void AVLTree::resetRotations()
{
    rotationCount = 0;
}



