/**
 * Title: Trees
 * Can Avşar 21902111
 * Section: 1
 * Assignment: 2
 * NgramTree.cpp
 */

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include "NgramTree.h"

using namespace std;

NgramTree::NgramTree(): root(NULL)
{
    
}

NgramTree::~NgramTree()
{
    
}

void NgramTree::addNgram(string ngram )
{
    addNgramHelper(root, ngram);
}

void NgramTree::addNgramHelper(TreeNode*& treePtr, string word)
{
    if (treePtr == NULL)
    {
        treePtr = new TreeNode(word, 0, NULL, NULL);
        treePtr->count++;
        
        if (treePtr == NULL)
        {
            return;
        }
    }
    
    else if (word < treePtr->item)
    {
        addNgramHelper(treePtr->leftChildPtr, word);
    }
    else if (word > treePtr->item)
    {
        addNgramHelper(treePtr->rightChildPtr, word);
    }
    else
    {
        treePtr->count++;
        return;
    }
    
    return;
    
}

bool NgramTree::isComplete()
{
    int totalNgrams = getTotalNgramCount();
    return isCompleteHelper(root, 0, totalNgrams);
}

bool NgramTree::isCompleteHelper(TreeNode* treeNode, int number, int totalNgrams)
{
    if (treeNode == NULL)
    {
        return true;
    }
    
    if (number >= totalNgrams)
    {
        return false;
    }
    
    if(isCompleteHelper(treeNode->rightChildPtr, 2 * number + 2, totalNgrams) && isCompleteHelper(treeNode->leftChildPtr, 2 * number + 1, totalNgrams))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool NgramTree::isFull()
{
    return false;
}

bool NgramTree::isFullHelper(TreeNode* treeNode)
{
    if (treeNode == NULL)
    {
        return true;
    }
    
    if (treeNode->leftChildPtr == NULL && treeNode->rightChildPtr == NULL)
    {
        return true;
    }
    
    if ((treeNode->leftChildPtr) && (treeNode->rightChildPtr))
    {
        return (isFullHelper(treeNode->rightChildPtr) && isFullHelper(treeNode->leftChildPtr));
    }
    
    return false;
}

void NgramTree::generateTree( string fileName, int n )
{
    
    ifstream readFile;
    readFile.open(fileName.c_str());
    
    string line;
    string word;
    string ngram;
    
    while (getline (readFile, line))
    {
        word = "";
        
        for(int i = 0; i < line.length(); i++)
        {
            if(line[i] != ' ')
            {
                word += line[i];
                if(i == (line.length())-1)
                {
                    if(word.length() < n)
                    {
                        word = "";
                    }
                    else
                    {
                        for(int j = 0; j <= word.length()-n; j++)
                        {
                            ngram = word.substr(j, n);
                            addNgram(ngram);
                            ngram = "";
                        }
                        
                    }
                }
            }
            else
            {
                if(word.length() < n)
                {
                    word = "";
                }
                else
                {
                    for(int j = 0; j <= word.length()-n; j++)
                    {
                        ngram = word.substr(j, n);
                        addNgram(ngram);
                        ngram = "";
                    }
                    
                }
                word = "";
            }
        }
    }
}

int NgramTree::getTotalNgramCount()
{
    return getTotal(root);
}

int NgramTree::getTotal(TreeNode* treeNode)
{
    if (treeNode == NULL)
        return 0;
    else
        return(getTotal(treeNode->leftChildPtr) + 1 + getTotal(treeNode->rightChildPtr));
}

ostream& operator<<(ostream& out, NgramTree tree)
{
    tree.inorder(out, tree.root);
    return out;
    
}

void NgramTree::inorder(ostream& os, TreeNode *treePtr)
{
    if (treePtr != NULL)
    {
        inorder(os, treePtr->leftChildPtr);
        os << "\"" << (treePtr->item) << "\" appears " << treePtr->count <<" time(s)" << endl;
        inorder(os, treePtr->rightChildPtr);
    }
}

