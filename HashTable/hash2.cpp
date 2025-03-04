//-----------------------------------------------------------
//  Purpose:    Implementation of HashTable class.
//  Author:     John Gauch & Vincent Hassman
//-----------------------------------------------------------
#include "hash2.h"
#include <stdlib.h>

//-----------------------------------------------------------
// Constructor
//-----------------------------------------------------------
HashTable::HashTable(int size)
{
   Size = size;
   Value = new int[Size];
   Key = new string[Size];
   numCollisions = 0; 

   for (int index = 0; index < Size; index++)
   {
      Value[index] = NONE;
      Key[index] = EMPTY;
   }
}

//-----------------------------------------------------------
// Copy constructor
//-----------------------------------------------------------
HashTable::HashTable(const HashTable & ht)
{
   Size = ht.Size;
   Value = new int[Size];
   Key = new string[Size];
   numCollisions = 0; 

   for (int index = 0; index < Size; index++)
   {
      Value[index] = ht.Value[index];
      Key[index] = ht.Key[index];
   }
}

//-----------------------------------------------------------
// Destructor
//-----------------------------------------------------------
HashTable::~HashTable()
{
   if (Value != NULL)
      delete[]Value;
   if (Key != NULL)
      delete[]Key;
   Value = NULL;
   Key = NULL;
   Size = 0;
}

//-----------------------------------------------------------
// Insert method
//-----------------------------------------------------------
bool HashTable::Insert(string key, int value)
{
   // Find desired key
   int index = Hash(key);
   while ((Key[index] != key) && (Key[index] != EMPTY))
      index = Hash2(index);

   // Insert value into hash table
   Value[index] = value;
   Key[index] = key;
   return true;
}

//-----------------------------------------------------------
// Search method
//-----------------------------------------------------------
bool HashTable::Search(string key, int &value)
{
   // Find desired key
   int index = Hash(key);
   while ((Key[index] != key) && (Key[index] != EMPTY))
      index = Hash2(index);

   // Return value from hash table
   if (Key[index] == key)
      value = Value[index];
   return (Key[index] == key);
}

//-----------------------------------------------------------
// Delete method
//-----------------------------------------------------------
bool HashTable::Delete(string key)
{
   // Find desired key
   int index = Hash(key);
   while ((Key[index] != key) && (Key[index] != EMPTY))
      index = Hash2(index);

   // Delete value from hash table
   if (Key[index] == key)
   {
      Value[index] = NONE;
      Key[index] = DELETED;
      return true;
   }
   return false;
}

int HashTable::getNumCollisions()
{
    return numCollisions; 
}

//-----------------------------------------------------------
// Primary hash function
//-----------------------------------------------------------
int HashTable::Hash(string key)
{
    //Original hash function 
    /*int num = 42;
    for (int i = 0; i < int(key.length()); i++)
        num = (num * 17 + key[i]) % Size;*/
    
    //New hash function #1 (~2625 collisions)
    /*int num = 143;
    for (int i = 0; i < int(key.length()); i++)
        num = (num * 317 + key[i]) % Size;*/
        
    //New hash function #2 (~2330 collisions)
    /*int num = 101;
    for (int i = 0; i < int(key.length()); i++)
        num = (num * 193 + key[i]) % Size;*/
    
    //New hash function #3 (~2045 collisions)
    int num = 21;
    for (int i = 0; i < int(key.length()); i++)
        num = (num%Size * 523 + key[i]) % Size;
    return num;
}

//-----------------------------------------------------------
// Secondary hash function
//-----------------------------------------------------------
int HashTable::Hash2(int index)
{
    //cout << "A collision was detected."<<endl;
    numCollisions++; 
    
    /*return (index + 1) % Size; //Original secondary hash function */
    
    return (index*(2+(random()%10)) % Size); 
    //New secondary hash formula 
    //When used with hash function #3, results in 1466 collisions 
}

//-----------------------------------------------------------
// Print function for debugging
//-----------------------------------------------------------
void HashTable::Print()
{
    for (int index = 0; index < Size; index++)
    {
        if (Value[index] > 0)
            cout << Value[index] << "\t" << Key[index] << "\n";
    }
}
