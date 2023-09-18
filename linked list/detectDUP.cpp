
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
    cout<<head->data<<"   ";
    head=head->next;
    }   
}
void insertend(node* &header,int data)
{
    node* head = header;
    if(head == NULL)
    {
        node* node1=new node(data);
        header = node1;
        return ;
    }
    node* node2=new node(data);
    while (head->next!=NULL)
    {
        head=head->next;
        
    }
    head->next=node2;
}
void detectdup(node* &head)
{
    node* temp = head;
    while( temp -> next != NULL)
    {
        if(temp->next->data == temp ->data)
        cout<<" duplication of "<<temp->data<<endl;
        temp=temp->next;
    }
}
void removed(node* &head)
{
     node* temp = head;
    while( temp -> next != NULL)
    {
        if(temp->next->data == temp ->data)
        {temp->next= temp->next->next;
        continue;}
        temp=temp->next;
    }
}
int main() {
    node* head =NULL;
    for(int i=0;i<5;i++)
  {
      int j;
      cin>>j;
      insertend(head, j);
  }
    plist(head);
    detectdup(head);
    removed(head);
    plist(head);
    return 0;
}

