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

void reversel(node* &head,node* &temp)
{
    node* curr=head;
    if(head->next==NULL)
    {
       
        
        curr->next=temp;
        return ;
        }
    
   head= head->next;
   curr->next=temp;
   temp=curr;  
   reversel(head,temp);
}

bool check_pal(node* head)
{
    
    node* temp= head;
    int count=1;
    while(temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }

   

    temp =head;
    count = count/2;
    while(count>1)
    {
        temp = temp->next;
        count--;
    }
    

    node* temp2 = NULL;
    temp=temp->next;
    reversel(temp,temp2);
    
    
    node* temp3=temp;
    node* temp4=head;
    while(temp4 != temp3 && temp!= NULL)
    {
        
        if(temp4->data !=temp->data)
        return false;
            temp4=temp4->next;
            temp=temp->next;
    }
    return true;
 }
int main()
{
    node* head=NULL;
    int size;
    cout<<" enter size of LL \n";
    cin>>size;
    for(int i=0;i<size;i++)
    {
        int j;
        cin>>j;
        insertend(head,j);
    }
    plist(head);
    cout<<endl;
    cout<<" the answer is "<< check_pal(head);
    return 0;
}