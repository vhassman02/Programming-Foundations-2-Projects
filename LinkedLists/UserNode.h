//The UserNode class stores user attributes 
//It gives access to private variables of a node 
#ifndef USERNODE_H
#define USERNODE_H

#include <iostream> 
#include <string>
using namespace std; 

class UserNode
{
    public:
        UserNode(); //Default constructor
        UserNode(string FName, string LName, 
            string UName, string PNumber, int MessageCount); //constructor 
        ~UserNode(); //Destructor 
    
        //Getter methods
        string getfName() const;
        string getlName() const;
        string getuName() const;
        string getpNumber() const;
        int getMessageCount() const;
        UserNode *getNextNode() const;
        
        //Setter methods
        void setfName(string FName);
        void setlName(string LName);
        void setuName(string UName);
        void setpNumber(string PNumber);
        void setMessageCount(int MessageCount);
        void setNextNode(UserNode *Next);
    
        //Print method 
        void print() const;
    
    private:
        //User attributes
        string fName;
        string lName;
        string uName;
        string pNumber;
        int messageCount;
        
        //Pointer to the next node 
        UserNode *next; 
};
#endif 
