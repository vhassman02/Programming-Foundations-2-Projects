#include <iostream>
#include "UserList.h"

using namespace std; 

void deleteList(UserList list); 
int main()
{
    cout<<"Testing the linked list..."<<endl;
    
    //Create a linked list
    UserList Llist; 
    
    //Add users to the list 
    Llist.addUser("Lightning", "McQueen", "kachow", "123-456-7890", 597);
    Llist.addUser("Tow", "Mater", "dadgum", "980-765-4321", 60);
    Llist.addUser("Chick", "Hicks", "kachiga", "304-729-5026", 5008);
    
    //Print the entire list in the order entered 
    Llist.printList(); 
    
    //Search for user with the most messages
    Llist.largestCount(); 
    
    cout<<endl; 
    
    //Add 1 to a user's message count 
    cout<<"Incrementing message count of user kachow..."<<endl; 
    Llist.incrementCount("kachow");
    
    //Print the list after user's message count has been updated 
    Llist.printList(); 
    
    //Call to delete the linked list
    cout<<"Deleting list..."<<endl; 
    Llist.~UserList(); 
    
    //Print linked list again to verify it is deleted 
    Llist.printList(); 
    return 0;
}
