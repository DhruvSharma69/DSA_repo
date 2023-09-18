#include<iostream>
#include<map>
using namespace std;
// ********** there are two methods mentioned in this program for loop detection ********
class node
{
    public:
    int data;
    node* next;
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};


// function to add at end of ]
void insertend(node *&head, int data)
{
    node *temp = head;
    if (head == NULL)
    {
        node *newnode = new node(data);
        head = newnode;
        return;
    }
    node *node2 = new node(data);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next=node2;
}


// function to print linked list
void plist(node *&head)
{
    node* temp= head;
    while (temp != NULL)
    {
       
        cout << temp->data << "   " ;
        temp = temp->next;
    }
}

//explicitly insrting loop by pointing last node to 3rd node
void insertloop(node* head)
{
   
    node* temp=head;
    while(temp->next != NULL)
    {
        temp=temp-> next;
    }
    temp->next=head->next->next;
   
    cout<<"loop inserted \n";
}

// function to detect loop 
void detectloop(node* head)
{
    node* temp = head ;
    map<node*,bool> check;
    while(temp->next != NULL)
    {
        if(check[temp]==true)
        {
            cout<<" \n loop is detected \n";
            return ;
        }
        check[temp] = true;
        temp = temp->next;

    }
    cout<<" \n no loop detected \n";
}


// ***********detecting loop using Floyd's Loop detection ************

void Fdetect(node* &head)
{
    node* slow = head;
    node* fast = head;
    do
    {
        slow = slow ->next;
        fast = fast->next->next;
    }
    while((slow != fast) && ( slow != NULL) && (fast != NULL));
    if( slow == fast)
   {
     cout<<" loop detected ";
     return;
   }
   
    cout<<" loop not detected ";
        
    
}


int main()
{
    node* head= NULL;
    for(int i=0; i<10;i++)
    {
        insertend(head,i);
    }

    plist(head);
    insertloop(head);
    //detectloop(head);
    Fdetect(head);
    return 0;
}