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
