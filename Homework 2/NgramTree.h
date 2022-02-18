/**
* Title: Trees
* Can Avşar 21902111
* Section: 1
* Assignment: 2
* NgramTree.h
*/

#ifndef NgramTree_h
#define NgramTree_h
#include "TreeNode.h"

class NgramTree
{
public:
    NgramTree();
    ~NgramTree();

    void addNgram( string ngram );
    void addNgramHelper(TreeNode*& treePtr, string word);

    int getTotalNgramCount();
    int getTotal(TreeNode* treeNode);

    bool isComplete();
    bool isCompleteHelper(TreeNode* treeNode, int number, int totalNgrams);

    bool isFull();
    bool isFullHelper(TreeNode* treeNode);

    void generateTree( string fileName, int n );
    
    void inorder(ostream& os, TreeNode *treePtr);


protected:
    TreeNode* root;

private:
    friend ostream& operator<<( ostream& out, NgramTree tree);
};

#endif
