// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// function to print linked list
void plist(node *&head)
{
    cout<<" calling";
    node*temp=head;
    cout<<" head is "<< head->data<<endl;
    while (temp->next != head)
    {
        cout << temp->data<<"  " ;
        temp = temp->next;
       
    }
   cout<<"" <<temp->data;
}
// function to add at end of ]
void insertend(node *&head, int data)
{
    
    if (head == NULL)
    {
        node *newnode = new node(data);
        head=newnode;
        
        return ;
    }
    node* temp = head;
    node *node2 = new node(data);
    
    while (temp->next != NULL && temp->next!= head)
    {
        temp = temp->next;
        
    }
    temp->next = node2;
    node2->next= head;
   
    
}
bool is_circular(node* &head)
{
    if(head==NULL)
    return true;
    else if( head ->next==head)
    return true;
    else
    {
        node* temp= head;
        while(temp->next!=head)
        {
            temp=temp->next;
            if(temp->next==NULL)
            return false;
        }
        return true;
    }
}
int main()
{
    
    node *head = NULL;
    for (int i = 0; i < 10; i++)
    {
        insertend(head, i);
    }
    plist(head);
    cout<<"the answer is"<<is_circular(head);
    

    return 0;
}

