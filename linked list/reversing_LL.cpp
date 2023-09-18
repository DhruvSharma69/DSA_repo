#include <iostream>
using namespace std;

class node{
    public:
    //for storing data and address in node
    int data;
    node* next;
    // make constructor so it can always store value while creating new node
    node(int data)
    {
        this->data=data;
        this->next=NULL;
        
    }
    
};
//function to print linked list 
void plist(node* head)
{
    
    while(head!=NULL)
    {
    cout<<head->data<<"   "<<head->next<<endl;
    head=head->next;
    }   
}

//function to add at end of ]
void insertend(node* &head,int data)
{
    node* temp = head;
    if(head==NULL)
    {
        node* newnode = new node(data);
        head = newnode;
        return ;
    }
    node* node2=new node(data);
    while (temp->next!=NULL)
    {
        temp=temp->next;
        
    }
    temp->next=node2;
}

//function to reverse list
void reversel(node* &head,node* &temp)
{
    node* curr=head;
    if(head->next==NULL)
    {
        cout<<"base case \n";
        
        curr->next=temp;
        return ;
        }
    
   head= head->next;
   curr->next=temp;
   temp=curr;

    //cout<<" head  "<<head->data<<"  head next  "<<head->next->data<<endl;
    
   reversel(head,temp);
}
int main()
{
    node* head = NULL;
    node* temp=NULL;
    for(int i = 0; i < 5; i++)
    {
        insertend(head,i);
    }

    plist(head);
    cout<<endl<<endl;
    reversel(head,temp);
    plist(head);
    
    
    return 0;
}