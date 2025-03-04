//-----------------------------------------------------------
//  Purpose:    Implementation of HashTable class.
//  Author:     John Gauch
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
    //New hash function #3 (~2045 collisions)
    int num = 21;
    for (int i = 0; i < int(key.length()); i++)
        num = (num * 523 + key[i]) % Size;
    return num;
}

//-----------------------------------------------------------
// Secondary hash function
//-----------------------------------------------------------
int HashTable::Hash2(int index)
{
    numCollisions++; 
    return (index*(2+(random()%10)) % Size); 
}

//-----------------------------------------------------------
// Print function for debugging
//-----------------------------------------------------------
void HashTable::Print()
{
    for (int index = 0; index < Size; index++)
    {
        if (Value[index] > 0)
            cout << Value[index] << "\t'" << Key[index] << "'\n";
    }
}
