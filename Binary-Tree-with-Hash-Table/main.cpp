#include <iostream>
#include <fstream>
#include <cctype>
#include "hash2.h"
#include "tree3.h"
using namespace std;

void testTree(); 
void testHash(); 
string menu()
{
    cout<<"MENU"<<endl;
    cout<<"Enter the filename of the book you would like to analyze: ";
    string filename;
    cin>>filename;
    cout<<endl; 
    return filename;
}

int main()
{
    //return a filename from a menu input 
    string filename = menu(); 
    
    //Open the 10,000 words text file 
    ifstream fin;
    fin.open("google10000.txt");
    
    //Create a hash table 
    const int MAXSIZE = 40009;
    HashTable hash(MAXSIZE);
    
    //Read top 10,000 words into hash table 
    int position = 0; 
    string word; 
    while (!fin.eof())
    {
        fin>>word;
        hash.Insert(word, position);
        position++;
    }
    fin.close(); //close top 10000 file 
    //hash.Print(); 
    
    //Create a new binary tree to store unique words 
    BinaryTree btree; 
    BinaryTree btreeCapital;
    
    //open a .WORDS file
    string file = filename; 
    fin.open(file);

    //read the .WORDS file, look for words not in top 10,000 
    bool in10K; //bool to check if word is in top 10000 
    string bookWord; //a string to be read in from the book 
    int index=0; 
    while (!fin.eof())
    {
        fin>>bookWord; //read a word
        //when only the first character is capital 
        //if decapitalized word is not in  hash table, must be proper noun 
        if ((isupper(bookWord[0])!=0) && (isupper(bookWord[bookWord.length()-1])==0))
        {
            //convert the first char to  lowercase by adding 32 to ASCII char 
            bookWord[0]=bookWord[0]+32; 
            
            //if the lowercase string is not in the hash table 
            if (!hash.Search(bookWord, index))
            {
                bookWord[0]=bookWord[0]-32; 
                btreeCapital.Insert(bookWord);
            }
        }
        
        //when string is capitals at start and end (all capitals)
        //store in capitals 
        else if ((isupper(bookWord[0])!=0) && (isupper(bookWord[bookWord.length()-1])!=0))
        {
            //convert the first char to  lowercase by adding 32 to ASCII char 
            for (int i = 0; i<bookWord.length(); i++)
                bookWord[i]=bookWord[i]+32; 
            //if the lowercase string is not in the hash table 
            if (!hash.Search(bookWord, index))
            {
                for (int i = 0; i<bookWord.length(); i++)
                    bookWord[i]=bookWord[i]-32; 
                btree.Insert(bookWord);
            }
        }
        
        //store string word in binary tree if not in top 10,000 
        else if (!hash.Search(bookWord, index))
        {
            //capital letter if between ASCII 65 and 90 
            if (bookWord[0]>=65 && bookWord[0]<=90)
                btreeCapital.Insert(bookWord);
            //otherwise not capital first letter 
            else
                btree.Insert(bookWord);
        }
    }
    
    //print the two binary trees to separate files 
    //print capital letter tree
    ofstream fout;
    fout.open("proper_nouns.txt");
    bool file1generated;
    bool file2generated; 
    if (!fout.fail())
    {
        cout<<"Generating text file of proper nouns..."<<endl;
        file1generated = true;     
    }
    fout<<"This document contains plausible proper nouns"<<endl;
    btreeCapital.Print(fout);
    fout.close();
    //print lowercase tree 
    fout.open("other_rare_words.txt");
    if (!fout.fail())
    {
        cout<<"Generating text file for rare words/spelling errors..."<<endl; 
        file2generated = true;    
    }
    fout<<"This document contains uncommon words and possible typing mistakes"<<endl; 
    btree.Print(fout);
    fout.close(); 
    
    cout<<endl; 
    if (file1generated && file2generated)
        cout<<"File generation complete!"<<endl; 
    
    return 0;
}

void testHash()
{
    //Open the 10,000 words text file 
    string filename = "google10000.txt";
    ifstream fin;
    fin.open(filename);
    if (fin.fail()) 
    cout << "can not open file" << endl;
    
    //Create a hash table 
    const int MAXSIZE = 40000;
    HashTable hash(MAXSIZE);
    
    //Read top 10,000 into hash table 
    int position = 0; 
    string word = "";
    while (!fin.eof())
    {
        getline(fin, word);
        hash.Insert(word, position);
        cout << "'" << word << "'\n";
        position++;
    }
    fin.close(); 
    //hash.Print(); 
    
    //Search for words that are in/not in the file 
    cout<<"Searching for words in Google top 10,000 words..."<<endl; 
    int num = 0;
    string String = "legs";
    bool findWord = hash.Search(String, num);
    if (findWord)
        cout<<"The word "<<String<<" was found at location "<<num<<endl;
    else
        cout<<"The word "<<String<<" was not found"<<endl;
    String = "perpetuity";
    findWord = hash.Search(String, num);
    if (findWord)
        cout<<"The word "<<String<<" was found at index "<<num<<endl;
    else
        cout<<"The word perpetuity was not found"<<endl;
    String = "this";
    findWord = hash.Search(String, num);
    if (findWord)
        cout<<"The word "<<String<<" was found at index "<<num<<endl;
    else
        cout<<"The word perpetuity was not found"<<endl;
}

void testTree()
{
    // Create tree
    BinaryTree Tree;

    // Test binary tree insertion
    const int MAX = 10;
    string Word[MAX] = {
        "hello", "mom", "please", "send", "money", 
        "i", "am", "out", "of", "beer"
    };
    for (int Count = 0; Count < MAX*5; Count++)
    {
        int index = rand() % MAX;
        if (Tree.Insert(Word[index]))
        cout << "Insert '" << Word[index] << "' ok\n";
        else
        cout << "Insert '" << Word[index] << "' failed\n";
        Tree.Print();
    }

    // Test binary tree search
    for (int Count = 0; Count < MAX; Count++)
    {
        int index = rand() % MAX;
        if (Tree.Search(Word[index]))
            cout << "Search '" << Word[index] << "' found\n";
        else
            cout << "Search '" << Word[index] << "' not found\n";
    }

    // Test binary tree deletion
    for (int Count = 0; Count < MAX; Count++)
    {
        int index = rand() % MAX;
        if (Tree.Delete(Word[index]))
            cout << "Delete '" << Word[index] << "' ok\n";
        else
            cout << "Delete '" << Word[index] << "' failed\n";
        Tree.Print();
    }
}
