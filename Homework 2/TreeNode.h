/**
* Title: Trees
* Can Avşar 21902111
* Section: 1
* Assignment: 2
* TreeNode.h
*/

#ifndef TreeNode_h
#define TreeNode_h

#include <iostream>
#include <string>
#include "NgramTree.h"
#include "TreeNode.h"

using namespace std;

class TreeNode
{

private:
    
    TreeNode()
    {
    }
    
    TreeNode(const string& nodeItem, int count, TreeNode *left = NULL, TreeNode *right = NULL): item(nodeItem),
    count(count), leftChildPtr(left), rightChildPtr(right)
    {
    }
    
    string item; // data portion
    int count;
    TreeNode *leftChildPtr; // pointer to left child
    TreeNode *rightChildPtr; // pointer to right child
    
    friend class NgramTree;
    
    
};


#endif /* TreeNode_h */


