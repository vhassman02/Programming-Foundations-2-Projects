//-----------------------------------------------------------
//  Purpose:    Implementation of BinaryTree class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include "tree3.h"

//-----------------------------------------------------------
// Constructor function.
//-----------------------------------------------------------
BinaryTree::BinaryTree()
{
   Root = NULL;
}

//-----------------------------------------------------------
// Constructor function that reads tree from file.
//-----------------------------------------------------------
BinaryTree::BinaryTree(char *Name)
{
   Root = NULL;

   // Open input file
   ifstream din;
   din.open(Name);
   if (din.fail())
      cout << "Error: could not open input file\n";

   // Read the data
   string Word;
   din >> Word;
   while (!din.eof())
   {
      InsertHelper(Word, Root);
      din >> Word;
   }

   // Close the file
   din.close();
}

//-----------------------------------------------------------
// Copy constructor helper function.
//-----------------------------------------------------------
void BinaryTree::CopyHelper(Node * Tree1, Node * &Tree2)
{
   // Check terminating condition
   if (Tree1 == NULL)
      Tree2 = NULL;

   // Copy node and it's children
   else
   {
      Tree2 = new Node;
      Tree2->Word = Tree1->Word;
      Tree2->Count = Tree1->Count;
      CopyHelper(Tree1->Left, Tree2->Left);
      CopyHelper(Tree1->Right, Tree2->Right);
   }
}

//-----------------------------------------------------------
// Copy constructor.
//-----------------------------------------------------------
BinaryTree::BinaryTree(const BinaryTree & B)
{
   // Call tree copy function
   CopyHelper(B.Root, Root);
}

//-----------------------------------------------------------
// Destructor function helper function.
//-----------------------------------------------------------
void BinaryTree::DestroyHelper(Node * Tree)
{
   // Delete node and it's children
   if (Tree != NULL)
   {
      DestroyHelper(Tree->Left);
      DestroyHelper(Tree->Right);
      delete Tree;
   }
}

//-----------------------------------------------------------
// Destructor function.
//-----------------------------------------------------------
BinaryTree::~BinaryTree()
{
   // Call tree destroy function
   DestroyHelper(Root);
}

//-----------------------------------------------------------
// Search helper function.
//-----------------------------------------------------------
bool BinaryTree::SearchHelper(string Word, Node * Tree)
{
   // Data value not found 
   if (Tree == NULL)
      return false;

   // Data value found 
   else if (Tree->Word == Word)
      return true;

   // Recursively search for data value
   else if (Tree->Word > Word)
      return (SearchHelper(Word, Tree->Left));
   else if (Tree->Word < Word)
      return (SearchHelper(Word, Tree->Right));
   else
      return false;
}

//-----------------------------------------------------------
// Search for data in the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Search(string Word)
{
   // Call tree searching function
   return (SearchHelper(Word, Root));
}

//-----------------------------------------------------------
// Insert helper function.
//-----------------------------------------------------------
bool BinaryTree::InsertHelper(string Word, Node * &Tree)
{
   // Insert data into the tree
   if (Tree == NULL)
   {
      Tree = new Node;
      Tree->Word = Word;
      Tree->Count = 1;
      Tree->Left = NULL;
      Tree->Right = NULL;
      return true;
   }

   // Data value already inserted
   else if (Tree->Word == Word)
   {
      Tree->Count++;
      return true;
   }

   // Recursively search for insertion position
   else if (Tree->Word > Word)
      return (InsertHelper(Word, Tree->Left));
   else if (Tree->Word <= Word)
      return (InsertHelper(Word, Tree->Right));
   else
      return false;
}

//-----------------------------------------------------------
// Insert data into the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Insert(string Word)
{
   // Call tree insertion function
   return (InsertHelper(Word, Root));
}

//-----------------------------------------------------------
// Delete a single node from the binary tree.
//-----------------------------------------------------------
bool BinaryTree::DeleteNode(Node * &Tree)
{
   Node *Temp = Tree;

   // Node has 0 children
   if ((Tree->Left == NULL) && (Tree->Right == NULL))
      Tree = NULL;

   // Node has 1 child
   else if (Tree->Left == NULL)
      Tree = Tree->Right;
   else if (Tree->Right == NULL)
      Tree = Tree->Left;


   // Node has 2 children
   else
   {
      // Find leftmost node in right subtree
      Node *Parent = Tree;
      Temp = Tree->Right;
      while (Temp->Left != NULL)
      {
	 Parent = Temp;
	 Temp = Parent->Left;
      }

      // Replace deleted data with leftmost value
      if (Parent == Tree)
	 Parent->Right = Temp->Right;
      else
	 Parent->Left = Temp->Right;
      Tree->Word = Temp->Word;
      Tree->Count = Temp->Count;
   }

   // Delete node
   delete Temp;
   return true;
}

//-----------------------------------------------------------
// Delete helper function.
//-----------------------------------------------------------
bool BinaryTree::DeleteHelper(string Word, Node * &Tree)
{
   // Data value not found
   if (Tree == NULL)
      return false;

   // Data value found and deleted
   else if (Tree->Word == Word)
      return (DeleteNode(Tree));

   // Recursively search for node to delete
   else if (Tree->Word > Word)
      return (DeleteHelper(Word, Tree->Left));
   else if (Tree->Word < Word)
      return (DeleteHelper(Word, Tree->Right));
   else
      return false;
}

//-----------------------------------------------------------
// Delete data from the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Delete(string Word)
{
   // Call tree deletion function
   return (DeleteHelper(Word, Root));
}

//-----------------------------------------------------------
// Print helper function.
//-----------------------------------------------------------
void BinaryTree::PrintHelper(Node * Tree)
{
   // Check terminating condition
   if (Tree != NULL)
   {
      // Print left subtree
      PrintHelper(Tree->Left);

      // Print node value
      cout << Tree->Count << " '" << Tree->Word << "'" << endl;

      // Print right subtree
      PrintHelper(Tree->Right);
   }
}

//-----------------------------------------------------------
// Print all records in the binary tree.
//-----------------------------------------------------------
void BinaryTree::Print()
{
   // Call tree printing function
   PrintHelper(Root);
}

//-----------------------------------------------------------
// Print helper function.
//-----------------------------------------------------------
void BinaryTree::PrintHelper(Node * Tree, ofstream & dout)
{
   // Check terminating condition
   if (Tree != NULL)
   {
      // Print left subtree
      PrintHelper(Tree->Left, dout);

      // Print node value
      dout << Tree->Count << "\t'" << Tree->Word << "'" << endl;

      // Print right subtree
      PrintHelper(Tree->Right, dout);
   }
}

//-----------------------------------------------------------
// Print all records in the binary tree.
//-----------------------------------------------------------
void BinaryTree::Print(ofstream & dout)
{
   // Call tree printing function
   PrintHelper(Root, dout);
}
