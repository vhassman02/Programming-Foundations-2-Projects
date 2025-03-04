#ifndef TREE_H
#define TREE_H

//-----------------------------------------------------------
//  Purpose:    Header file for the BinaryTree class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

//-----------------------------------------------------------
// BinaryTree data node definition
//-----------------------------------------------------------
class Node
{
 public:
   int Count;
   string Word;
   Node *Left;
   Node *Right;
};

//-----------------------------------------------------------
// Define the BinaryTree class interface 
//-----------------------------------------------------------
class BinaryTree
{
 public:
    // Constructor functions
    BinaryTree();
    BinaryTree(char *Name);
    BinaryTree(const BinaryTree & tree);
    ~BinaryTree();

    // General binary tree operations
    bool Search(string Word);
    bool Insert(string Word);
    bool Delete(string Word);
    void Print();
    void Print(ofstream & dout);

 private:
    // Helper functions
    void CopyHelper(Node * Tree1, Node * &Tree2);
    void DestroyHelper(Node * Tree);
    bool SearchHelper(string Word, Node * Tree);
    bool InsertHelper(string Word, Node * &Tree);
    bool DeleteNode(Node * &Tree);
    bool DeleteHelper(string Word, Node * &Tree);
    void PrintHelper(Node * Tree);
    void PrintHelper(Node * Tree, ofstream & dout);

    // Tree pointer
    Node *Root;
};
#endif