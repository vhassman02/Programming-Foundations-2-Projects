#include "hash2.h"
#include <stdlib.h>
#include <fstream> 

void test(); 
int main()
{
    //create hash table of 40,000 indexes to store 10,000 strings 
    const int MAXSIZE = 40000;
    HashTable hash(MAXSIZE);
    hash.Print(); 
    
    //open text file google10000.txt
    string filename = "google10000.txt";
    ifstream fin;
    fin.open(filename);
    
    int position = 0; 
    string word = "";
    
    //read text file and insert into hash table 
    while (!fin.eof())
    {
        getline(fin, word);
        hash.Insert(word, position);
        position++;
    }
    
    //hash.Print(); 
    cout<<hash.getNumCollisions()<<" collisions were detected"<<endl;
    return 0;
}

void test()
{
    int size = 10;
    string str[10] = {"this", "is", "a", "simple", "test", "of", "string", "based", "hash", "tables"};
    HashTable hash(2 * size);

    // Test insert method
    for (int count = 0; count < size; count++)
    {
        int num = random() % size;
        if (hash.Insert(str[count], num))
            cout << "Insert " << str[count] << "\n";
        else
            cout << "Insert " << str[count] << " failed\n";
    }
    cout << endl;
    hash.Print();

    // Test search method
    cout << endl;
    for (int count = 0; count < size; count++)
    {
        int num = random() % size;
        if (hash.Search(str[count], num))
            cout << "Search " << str[count] << " found\n";
        else
            cout << "Search " << str[count] << " not found\n";
    }

    // Test delete method
    cout << endl;
    for (int count = 0; count < size; count++)
    {
        if (hash.Delete(str[count]))
            cout << "Delete " << str[count] << "\n";
        else
            cout << "Delete " << str[count] << " failed\n";
    }
    cout << endl;
    hash.Print();
}
