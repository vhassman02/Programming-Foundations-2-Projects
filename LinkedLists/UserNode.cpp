#include "UserNode.h"

/*----------Default Constructor----------*/
UserNode::UserNode()
{
    //Initializes the first node with nothing in it 
    fName = "";
    lName = "";
    uName = "";
    pNumber = "";
    messageCount = 0;
    /*The default value of the Next pointer is NULL
    because the default state of the linked list is with one node*/
    next = NULL; 
}

/*----------Constructor----------*/
UserNode::UserNode(string FName, string LName, string UName, string PNumber, int MessageCount)
{
    fName = FName;
    lName = LName;
    uName = UName;
    pNumber = PNumber;
    messageCount = MessageCount;
}

//No copy constructor implemented 

/*----------Destructor----------*/
UserNode::~UserNode()
{
    //empty 
}

/*----------Getter methods----------*/
string UserNode::getfName() const
{
    return fName;
}

string UserNode::getlName() const
{
    return lName;
}

string UserNode::getuName() const
{
    return uName;    
}

string UserNode::getpNumber() const
{
    return pNumber;
}

int UserNode::getMessageCount() const
{
    return messageCount;
}

UserNode *UserNode::getNextNode() const
{
    return next; 
}

/*----------Setter methods----------*/
void UserNode::setfName(string FName)
{
    fName = FName;
}

void UserNode::setlName(string LName)
{
    lName = LName;
}

void UserNode::setuName(string UName)
{
    uName = UName;
}

void UserNode::setpNumber(string PNumber)
{
    pNumber = PNumber;    
}

void UserNode::setMessageCount(int MessageCount)
{
    messageCount = MessageCount; 
}
void UserNode::setNextNode(UserNode *Next)
{
    next = Next; 
}

/*----------Print method----------*/
void UserNode::print() const 
{
    cout<<"First name:    "<<fName<<endl;
    cout<<"Last name:     "<<lName<<endl;
    cout<<"User name:     "<<uName<<endl;
    cout<<"Phone number:  "<<pNumber<<endl;
    cout<<"Message count: "<<messageCount<<endl; 
}
