/*
 * Title: Heaps and AVL Trees
 * Author: Can Avşar
 * ID: 21902111
 * Section: 1
 * Assignment: 3
 * Description: MaxHeap.h
 */

#ifndef MaxHeap_h
#define MaxHeap_h

const int MAX_HEAP_SIZE = 100;

class MaxHeap
{
public:
    MaxHeap(); // Constructor
    void insert(int value); // Inserts integer into heap
    int peek(); // Returns the value of the max element
    int extractMax(); // Retrieves and removes the max element
    int size(); // Returns the number of elements in the heap
    void deleteItem(int value); // Deletes the item from the heap
    
protected:
   void heapRebuild(int root);
    
private:
    int items[MAX_HEAP_SIZE];
    int heapSize;
};

#endif /* MaxHeap_h */
