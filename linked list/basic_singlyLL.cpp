
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


//function to add node at beg
void insertbeg(node* &head,int data)
{
    node* node2=new node(data);
    node2->next=head;
   head=node2;
}

//function to add at end of ]
void insertend(node* head,int data)
{
    node* node2=new node(data);
    while (head->next!=NULL)
    {
        head=head->next;
        
    }
    head->next=node2;
}

//function to add after specific position
void insertloc(node* head, int pos,int data)
{
	if(pos==0)
	{
		insertbeg(head,data);
		return;
	}
    node* node2 = new node(data);
    node* loc=head;
    for(int j=1;j<pos;j++)
    {
        loc=loc->next;
    }
    node2->next=loc->next;
    loc->next=node2;
    
}

//function to delete a specific pos
void deletepos(node* head, int pos)
{
    node* temp=head;
    for(int j=1;j<pos;j++)
    {
        temp=head;
        head = head -> next;
        
    }
    temp = head -> next;
    delete temp;
    
}

int main() {
   //creaing new node named "node1" with value 15
   node* node1=new node(15);
   int n;
   //head pointer always point to first node
  node* head=node1;
  
  /* 
  ********uncomment for insertion at beg of ll
   //inserting a node at begining
   
   cout<<"\n enter value u want to insert \n ";
   cin>>n;
    insertbeg(head,n);
    plist(head);
   
   */
   
   
   /*
   uncomment for insertion at end
   //insertion at end of ll
   cout<<"\n enter value u want to insert \n ";
   cin>>n;
   insertend(head, n);
   plist(head);
    
   */
   
////***** uncomment for  insertion after loc and deletion at pos
//   //insertion after any specific node
//   insertend(head,20);
//   insertend(head,25);
//   plist(head);
//   int pos;
//   cout<<" \nenter pos after which u want node and data \n";
//   cin>>pos>>n;
//   insertloc(head,pos,n);
//   plist(head);
//   deletepos(head,3);
   
    return 0;
}



