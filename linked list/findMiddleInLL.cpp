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
        cout << head->data << "   " << head->next << endl;
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

node *findmid(node *head, int n)
{
    // even
    if (n % 2 == 0)
    {
        int count = 1;
        while (count <= (n / 2))
        {
            head = head->next;
            count++;
        }
        return head;
    }
    else
    {
        int count = 1;
        while (count <= (n / 2))
           { head = head->next;
            count++;
           }
        return head;
    }
}
int main()
{
    node *head = NULL;
    cout << " enter no. of elements in list:  ";
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        insertend(head, i);
    }

    plist(head);

    node* ans= findmid(head,n);
    cout<<ans->data;

    return 0;
}