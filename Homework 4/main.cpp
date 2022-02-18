/*
 * Title: Hashing
 * Author: Can Avşar
 * ID: 21902111
 * Section: 1
 * Assignment: 4
 * main.cpp
 */

#include "HashTable.h"
#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    // ! IMPORTANT NOTE: I am sorry but couldn't finish the code, however, there are similar test outputs for a chance of a partial grade. :)
    // You can test it with any code similar to them if it helps. Thank you.
    
    HashTable hash1 = HashTable(10, HashTable::LINEAR);
    HashTable hash2 = HashTable(10, HashTable::QUADRATIC);
    HashTable hash3 = HashTable(10, HashTable::DOUBLE);

    // Operations for hash1 (linear probing)
    cout << "Operations for hash1 (linear probing)" << endl;
    if(hash1.insert(1234))
        cout << "1234 inserted" << endl;
    else
        cout << "1234 not inserted" << endl;
    
    int numOfProbes1 = 0;
    
    if(hash1.search(1234, numOfProbes1))
        cout << "1234 found after " << numOfProbes1 << " probes" << endl;
    else
        cout << "1234 not found after " << numOfProbes1 << " probes" << endl;

    hash1.display();
    
    if(hash1.remove(1234))
        cout << "1234 removed" << endl;
    else
        cout << "1234 not removed" << endl;
    
    cout << endl;

    // Operations for hash2 (quadratic probing)
    cout << "Operations for hash2 (quadratic probing)" << endl;
    if(hash2.insert(1234))
        cout << "1234 inserted" << endl;
    else
        cout << "1234 not inserted" << endl;
    
    
    int numOfProbes2 = 0;
    
    if(hash2.search(1234, numOfProbes2))
        cout << "1234 found after " << numOfProbes2 << " probes" << endl;
    else
        cout << "1234 not found after " << numOfProbes2 << " probes" << endl;

    hash2.display();
    
    if(hash2.remove(1234))
        cout << "1234 removed" << endl;
    else
        cout << "1234 not removed" << endl;
    
    cout << endl;
    
    // Operations for hash3 (double probing)
    cout << "Operations for hash3 (double probing)" << endl;
    if(hash3.insert(1234))
        cout << "1234 inserted" << endl;
    else
        cout << "1234 not inserted" << endl;
    
    int numOfProbes3 = 0;
    
    if(hash3.search(1234, numOfProbes3))
        cout << "1234 found after " << numOfProbes3 << " probes" << endl;
    else
        cout << "1234 not found after " << numOfProbes3 << " probes" << endl;
    
    hash3.display();

    if(hash3.remove(1234))
        cout << "1234 removed" << endl;
    else
        cout << "1234 not removed" << endl;

    cout << endl;
       
}

