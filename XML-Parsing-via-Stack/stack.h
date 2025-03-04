//declaration of an array-based stack class 
#ifndef STACK_H
#define STACK_H
#include <string> 
#include <iostream> 
using namespace std; 
class Stack
{
    public:
        Stack();
        ~Stack();
        bool isEmpty(); //check if stack is empty 
        void push(string value); //push onto stack 
        string peek(); //peek at the top of the stack 
        string pop(); //pop from the stack 
        bool isFull(); //check if stack is full 
        string ifError(); //returns the tag with an error if an error is found 
        void print(); //print stack 
    
    private:
        const int ARRAY_LENGTH=100;
        string array[100];
        int top=-1; //index containing the top data 
};
#endif 