#include <iostream>
#include <fstream> 
#include <sstream>
#include "stack.h"
using namespace std;

void test(); 
void checkXML(string filename);
int main()
{
    //test(); 
    cout<<"Enter the file you would like to check XML formatting on: ";
    string file;
    cin>>file;
    checkXML(file);
    return 0;
}

void checkXML(string filename)
{
    cout<<"Testing "<<filename<<endl;
    Stack s; //declare a stack 
    ifstream fin; //create a file input stream object 
    fin.open(filename); //open the file called filename 
    
    if (fin.fail())
    {
        cout<<filename<<" could not be opened. "<<endl;
        cout<<"Check that the file exists and is in the root directory."<<endl;
        return; 
    }

    string foo; //unused string for removing undesired characters 
    string tag; //XML tag string 
    
    //read until a space or a > character is found
    while (!fin.eof())
    {
        getline(fin, foo, '<');
        getline(fin, tag, '>');
        fin.ignore();
        
        //if the tag just read matches / + top of the stack, pop from the stack
        if ("/"+s.peek()==tag)
            s.pop(); 
        
        //else a new tag was found, push it onto stack 
        else 
        {
            //if tag is in format <tag DESCRIPTION="string">
            //only push the string up to the first space onto the stack 
            //tag will contain "=" if it is in this format 
            if (tag.find('='))
            {
                stringstream ss; //create a string stream called ss to remove non-tag characters in the tag string 
                ss.str(tag); //initialize the string stream to tag 
                getline(ss, tag, ' '); //trim to only the first word 
                s.push(tag); //push the first word onto the stack 
            }
            else
                s.push(tag);
        }
    }
    //stack will be empty if XML is ok 
    if (s.isEmpty())
        cout<<"XML file is OK"<<endl; 
    
    else
    {
        //the formatting error will be at the midway point in the stack 
        cout<<"\nERROR FOUND! \nError synopsis: "<<s.ifError()<<endl;
        cout<<"Resolve this error to check for additional errors."<<endl; 
    }
}

void test()
{
    Stack stack; 
    //attempt to push 11 items into a stack 
    stack.push("50");
    stack.push("51");
    stack.push("52");
    stack.push("53");
    stack.push("54");
    stack.push("55");
    stack.push("56");
    stack.push("57");
    stack.push("58");
    stack.push("59");
    stack.push("60");
    stack.print(); 
    
    //pop 3 items off the stack and print stack when done 
    cout<<"a "<<stack.pop()<<" was popped off the stack"<<endl;
    cout<<"a "<<stack.pop()<<" was popped off the stack"<<endl;
    cout<<"a "<<stack.pop()<<" was popped off the stack"<<endl;
    stack.print(); 
    
    cout<<"Top of stack: ";
    cout<<stack.peek()<<endl; 
}
