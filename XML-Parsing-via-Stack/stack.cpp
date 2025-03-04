//implementation of a stack class 
#include "stack.h"
Stack::Stack()
{
    for (int i=0; i<ARRAY_LENGTH; i++)
    {
        //initialize the stack with empty strings 
        array[i]="**";
    }
}

Stack::~Stack()
{
    //empty 
}

void Stack::print()
{
    cout<<"\nPrinting the stack..."<<endl; 
    for (int i = 0; i<ARRAY_LENGTH; i++)
    {
        cout<<array[i]<<endl; 
    }
}

void Stack::push(string value)
{
    //check if full 
    if (isFull())
    {
        cout<<"stack is full"<<endl;
    }
    
    else
    {
        //move top right by 1 
        top = top+1; 
        //put value at new top index 
        array[top]=value;
        //cout<<"top:"<<top<<endl; 
    }
}

string Stack::peek()
{
    //if empty, don't execute 
    if (isEmpty())
    {
        return "stack is empty";
    }
    
    else
    {
        //check value at top index 
        return (array[top]);
    }
}

string Stack::pop()
{
    //check if empty 
    if (isEmpty())
    {
        return "stack is empty. nothing to pop\n"; 
    }
    
    else
    {
        //retrieve value at top index
        string popValue = array[top];
        //remove the value at top and decrement top 
        array[top]="**";
        top--;
        //cout<<top<<endl; 
        //return the value at top before decrement 
        return popValue;
    }
}

bool Stack::isFull()
{
    if (top==ARRAY_LENGTH-1)
        return true;
    else
        return false; 
}

bool Stack::isEmpty()
{
    if (top==-1)
    {
        return true;
    }
    else
        return false; 
}

string Stack::ifError()
{
    //(top+1)/2 will be the index containing the tag with an error in it 
    return array[(top+1)/2];
}
