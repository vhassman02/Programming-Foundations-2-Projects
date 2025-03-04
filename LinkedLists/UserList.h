//The UserList class manipulates the linked list 
//It can add nodes at the head of the list 
#ifndef USERLIST_H
#define USERLIST_H

#include <iostream> 
#include "UserNode.h"
using namespace std; 

class UserList
{
    public:
        UserList(); //Default Constructor
        ~UserList(); //Destructor 
        
        //General methods 
        void addUser(string FName, string LName, 
            string UName, string PNumber, int MessageCount); 
        void incrementCount(string UName);
        void largestCount();
        
        //Print method 
        void printList() const;
        
    private:
        UserNode *head; //Pointer to the head of the linked list 
        int numUsers; //The number of users in the list 
        long totalMessages; //The total number of messages user sent/received 
};
#endif 
