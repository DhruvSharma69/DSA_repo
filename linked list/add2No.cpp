#include <bits\stdc++.h>
#include<vector>
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

vector<int> add2num(node* &head1, node* &head2)
{
    node* t1 = head1;
    node* t2 = head2;
    node* tn= NULL;
    reversel(t1,tn);
    tn=NULL;
    reversel(t2,tn);

    int carry = 0,store;
    vector<int> ans;
    while(t1!=NULL &&  t2 != NULL)
    {
        store =( (  (t1->data + t2->data) + carry) % 10 );
        carry = (t1->data + t2->data + carry) / 10;
        ans.push_back(store);
        t1 = t1->next;
        t2 = t2->next;
    }
    if(t1 == NULL && t2 != NULL)
    {
        while(t2 !=NULL)
        {
            store =( (  t1->data) + carry) %10;
            carry = ( t2->data + carry) / 10;
            ans.push_back(store);
            t2 = t2 ->next;
        }
        ans.push_back(carry);
    }
    else if(t2 == NULL && t1 != NULL)
    {
        while(t1 !=NULL)
        {
            store =( (  t1->data) + carry) %10 ;
            carry = ( t1->data + carry) / 10;
            ans.push_back(store);
            t1 = t1 ->next;
        }
        ans.push_back(carry);
    }
    else
    ans.push_back(carry);
    reverse( ans.begin() , ans.end());
    return ans;


}
 int main()
 {
    node* head1 = NULL;
    node* head2 = NULL;
    cout<<" enter size and first ll \n";
    int size1;
    cin>>size1;
    for(int i=1;i<=size1;i++)
    {
        int j;
        cin>>j;
        insertend(head1,j);
    }
     cout<<" enter size and 2nd ll \n";
      int size2;
    cin>>size2;
       for(int i=1;i<=size2;i++)
    {
        int j;
        cin>>j;
        insertend(head2,j);
    }
    vector<int> ans = add2num(head1,head2);
    for(int i = 0; i<ans.size();i++)
    cout<<ans[i]<<" ";

    return 0;
 }