/*
 * Title: Hashing
 * Author: Can Avşar
 * ID: 21902111
 * Section: 1
 * Assignment: 4
 * HashTable.h
 */

#ifndef HashTable_h
#define HashTable_h

class HashTable
{
public:
    
    enum CollisionStrategy {LINEAR, QUADRATIC, DOUBLE};
    enum LocationTypes {EMPTY, DELETED, OCCUPIED};

    HashTable(const int tableSize, const CollisionStrategy option);
    ~HashTable();
    
    bool insert(const int item);
    bool remove(const int item);
    bool search(const int item, int& numProbes);
    void display();
    void analyze(int& numOfSuccProbes, int& numOfUnsuccProbes);
    int hashFunction(const int item);
    int probeFunction(const int item, const int i);
    int reverse(int item);

    int* hashTable;
    LocationTypes* locationStatus;
    int hashTableSize;
    CollisionStrategy strategy;
    
};
#endif /* HashTable_h */
