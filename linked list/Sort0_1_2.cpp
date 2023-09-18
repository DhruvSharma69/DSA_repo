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

void Sort_0_1_2(node* &head)
{
    node* temp = head;
    while(temp->next != NULL)
    {
          node* temp2 = temp;
       while(temp2->next!=NULL)
       {
        if(temp->data==temp2->data)
        {
            temp->next=temp2->next;
        }
       }
    }
    temp = head;
    while(temp->next!=NULL)
    {
        if(head->data!=0 && temp->data == 0)
        head=temp;
        if(temp->data)
        temp=temp->next;
    }
    
}   
int main()
{
    node* head = NULL;
    for(int i=0;i<5;i++)
    {
        int j;
        cin>>j;
        insertend(head,j);
    }
    plist(head);
    return 0;
}