#include "UserList.h"

/*----------Default Constructor----------*/
UserList::UserList()
{
    head = NULL;
    numUsers = 0; 
}

//No copy constructor implemented

/*----------Destructor----------*/
UserList::~UserList()
{
    //Starting at the head, delete each node 
    while (head!=NULL)
    {
        UserNode *ptr = head; 
        //Reassign head to point to the next node 
        head = head->getNextNode();
        //Delete ptr, so head node is deleted 
        delete ptr;
    }
    //No users in the list when the list is deleted 
    numUsers = 0; 
}

//COMPLETED | Add a user to the end of the linked list 
void UserList::addUser(string FName, string LName, string UName, string PNumber, int MessageCount) 
{
    //cout<<"UserList::addUser() was called"<<endl; 
    //Create a temporary pointer called ptr, set it to the head of the list 
    UserNode *ptr = head;
    
    //Search until end of list is found 
    while ((ptr != NULL) && (ptr->getNextNode() != NULL))
    {
        ptr = ptr->getNextNode(); 
    }
    
    //Create a new node called tmp 
    UserNode *tmp = new UserNode(); 
    
    //Assign attributes for node tmp
    tmp->setfName(FName);
    tmp->setlName(LName);
    tmp->setuName(UName);
    tmp->setpNumber(PNumber);
    tmp->setMessageCount(MessageCount);
    tmp->setNextNode(NULL);
    
    //Add the new node to the end of the list
    if (ptr != NULL)
        ptr->setNextNode(tmp); //Set "next" at memory location ptr == Node tmp 
    
    //Special case if list is empty 
    else if (ptr == NULL)
        head = tmp; //Head == memory location of tmp 
    
    //Increment number of users in the group 
    numUsers++;
}

//COMPLETE - Search the list for a username and increment their message count 
void UserList::incrementCount(string UName)
{
    //cout<<"UserList::incrementCount() was called"<<endl;
    //Pointer to the first node in the list 
    UserNode *ptr = head;
    //Store the user's current message count 
    int currMC = 0; 
    
    //Search the linked list for the desired user name
    while ((ptr!=NULL))
    {
        //If user found, increment message count variable
        //Update message count node attribute = message count variable 
        if (ptr->getuName() == UName)
        {
            currMC = ptr->getMessageCount();
            currMC++;
            ptr->setMessageCount(currMC);
        }
        //Go to the next node  
        ptr = ptr->getNextNode(); 
    }
}

//COMPLETED | Search for the user with largest message count and print the user's info  
void UserList::largestCount()
{
    //cout<<"UserList::largestCount() was called"<<endl; 
    //Create a pointer to the first node
    UserNode *ptr = head;
    //Pointer to the user with largest message count 
    UserNode *largestMCUser = NULL; 
    //Stores the largest messageCount value found 
    int largestValue = 0; 
    //Stores the user name of the user with most messages 
    string uname = "";
    
    //Search each node in the linked list
    while (ptr!=NULL)
    {
        //If message count at ptr > largest value, update largest value and user 
        if (ptr->getMessageCount() > largestValue)
        {
            largestValue = ptr->getMessageCount(); 
            uname = ptr->getuName(); 
            largestMCUser = ptr; 
        }
        //Go to the next node in the list 
        ptr = ptr->getNextNode(); 
    }
    //Print the user with most messages 
    cout<<largestMCUser->getuName()<<" is the user with the most messages.\n";
    largestMCUser->print(); 
}

//COMPLETED | Print method 
void UserList::printList() const
{
    //cout<<"UserList::printList() was called"<<endl; 
    //Create a node to start at the head of the linked list 
    UserNode *ptr = head;
    //Print all node attributes until the end of the list is reached (ptr==NULL)
    while (ptr != NULL)
    {
        cout<<"First name:    "<<ptr->getfName()<<endl;
        cout<<"Last name:     "<<ptr->getlName()<<endl;
        cout<<"User name:     "<<ptr->getuName()<<endl;
    
        cout<<"Phone number:  "<<ptr->getpNumber()<<endl;
        cout<<"Message count: "<<ptr->getMessageCount()<<endl; 
        cout<<endl; 
        //Get the next node and store it in ptr for checking if == NULL 
        ptr = ptr->getNextNode();
    }
    cout<<"There are currently "<<numUsers<<" users in the group.\n"<<endl; 
}
