/*
 * Title: Heaps and AVL Trees
 * Author: Can Avşar
 * ID: 21902111
 * Section: 1
 * Assignment: 3
 * Description: analysis.h
 */

#ifndef analysis_h
#define analysis_h

#include "AVLTree.h"

class analysis
{
public:
    
    void rotationAnalysis();
    void createRandomArray(int*& arr, const int size);
    void createAscendingArray(int*& arr, const int size);
    void createDescendingArray(int*& arr, const int size);
    
private:
};


#endif /* analysis_h */
