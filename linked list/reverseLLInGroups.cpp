#include <iostream>
using namespace std;

class node
{
public:
    // for storing data and address in node
    int data;
    node *next;
    // make constructor so it can always store value while creating new node
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// function to print linked list
void plist(node *head)
{

    while (head != NULL)
    {
        
        cout << head->data << "   " ;
        head = head->next;
    }
}

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
    temp->next = node2;
}

// function to reverse in groups
node* kReverse(node* head, int k) {
    //base call
    if(head == NULL) {
        return NULL;
    }
    
    //step1: reverse first k nodes
    node* next = NULL;
    node* curr = head;
    node* prev = NULL;
    int count= 0;
    
    while( curr != NULL && count < k ) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    //step2: Recursion dekhlega aage ka 
    if(next != NULL) {
        head -> next = kReverse(next,k);
    }
    
    //step3: return head of reversed list
    return prev;
}
int main()
{
    node *head = NULL;
    node *temp = NULL;
    int k;
    cout << " enter k \n";
    cin >> k;

    for (int i = 0; i < 10; i++)
    {
        insertend(head, i);
    }

    plist(head);
    cout << endl
         << endl;
     kReverse(head,k);
    plist(head);

    return 0;
}