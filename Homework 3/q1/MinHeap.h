/*
 * Title: Heaps and AVL Trees
 * Author: Can Avşar
 * ID: 21902111
 * Section: 1
 * Assignment: 3
 * Description: MinHeap.h
 */

#ifndef MinHeap_h
#define MinHeap_h

const int MIN_HEAP_SIZE = 100;

class MinHeap
{
public:
    MinHeap(); // Constructor
    void insert(int value); // Inserts integer into heap
    int peek(); // Returns the value of the max element
    int extractMin(); // Retrieves and removes the max element
    int size(); // Returns the number of elements in the heap
    void deleteItem(int value); // Deletes the item from the heap
    
protected:
   void heapRebuild(int root);
    
private:
    int items[MIN_HEAP_SIZE];
    int heapSize;
};

#endif /* MinHeap_h */
