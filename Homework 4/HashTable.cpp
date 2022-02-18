/*
 * Title: Hashing
 * Author: Can Avşar
 * ID: 21902111
 * Section: 1
 * Assignment: 4
 * HashTable.cpp
 */

#include <iostream>
#include <stdio.h>
#include "HashTable.h"

using namespace std;

HashTable::HashTable(const int tableSize, const CollisionStrategy option)
{
    hashTableSize = tableSize;
    hashTable = new int[hashTableSize];
    locationStatus = new LocationTypes[hashTableSize];
    
    for(int i = 0; i < hashTableSize; i++)
    {
        hashTable[i] = 0;
        locationStatus[i] = EMPTY;
    }
    
    strategy = option;
}

HashTable::~HashTable()
{
    
}

bool HashTable::insert(const int item)
{
    bool inserted = false;
    int index = 0;
    
    index = hashFunction(item);
    if(locationStatus[index] != OCCUPIED)
    {
        hashTable[index] = item;
        locationStatus[index] = OCCUPIED;
        inserted = true;
    }
    else
    {
        for(int i = 1; i < hashTableSize; i++)
        {
            index = (hashFunction(item) + (probeFunction(item, i))) % hashTableSize;
            if(locationStatus[index] != OCCUPIED)
            {
                hashTable[index] = item;
                locationStatus[index] = OCCUPIED;
                inserted = true;
                break;
            }
        }
    }
    return inserted;
}

bool HashTable::remove(const int item)
{
    bool removed = false;
    int index = 0;
    
    index = hashFunction(item);
    if(locationStatus[index] != DELETED)
    {
        hashTable[index] = 0;
        locationStatus[index] = DELETED;
        removed = true;
    }
    else
    {
        for(int i = 1; i < hashTableSize; i++)
        {
            index = (hashFunction(item) + (probeFunction(item, i))) % hashTableSize;
            if(locationStatus[index] != DELETED)
            {
                hashTable[index] = 0;
                locationStatus[index] = DELETED;
                removed = true;
                break;
            }
        }
    }
    return removed;
}

bool HashTable::search(const int item, int& numProbes)
{
    bool found = false;
    int index = 0;
    
    index = hashFunction(item);
    if(locationStatus[index] == OCCUPIED && hashTable[index] == item)
    {
        numProbes++;
        found = true;
    }
    else
    {
        for(int i = 1; i < hashTableSize; i++)
        {
            index = (hashFunction(item) + (probeFunction(item, i))) % hashTableSize;
            if(locationStatus[index] == OCCUPIED && hashTable[index] == item)
            {
                numProbes++;
                found = true;
                break;
            }
        }
    }
    return found;
}


void HashTable::display()
{
    for(int i = 0; i < hashTableSize; i++)
    {
        cout << i << ": " << hashTable[i];
        cout << endl;
    }
    
}

void HashTable::analyze(int& numOfSuccProbes, int& numOfUnsuccProbes)
{
    
}

int HashTable::hashFunction(const int item)
{
    return item % hashTableSize;
}

int HashTable::probeFunction(const int item, const int i)
{
    if(strategy == LINEAR)
    {
        return i;
    }
    else if(strategy == QUADRATIC)
    {
        return i*i;
    }
    else
    {
        return i*reverse(item);
    }
}

int HashTable::reverse(const int item)
{
    int number = item;
    int remainder = 0;
    int reverse = 0;
    
    while(number != 0)
    {
        remainder = number % 10;
        reverse = reverse * 10 + remainder;
        number = number / 10;
    }
    
    return reverse;
}
