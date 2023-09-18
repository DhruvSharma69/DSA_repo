#include<iostream>
#include<queue>
using namespace std;
class node
{
        public:
        int data;
        node* left,*right;

        node(int data)
        {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }

};

node* BST( int arr[], int size)
{
    node* root = new node(arr[0]);       
    
    for(int i=1; i<size; i++)
    {
        node* temp = root;
        bool place_found = false;
       while(place_found == false)
       {
           // cout<<"hello";
            if(arr[i] < temp -> data)
            {
                if(temp->left != NULL)
                temp = temp->left;
                else
               {
                 temp ->left = new node(arr[i]);
                 place_found = true;
                 
                }
            }

             if(arr[i] > temp -> data)
            {
                if(temp->right != NULL)
                temp = temp->right;
                else
               {
                 temp ->right = new node(arr[i]);
                 place_found = true;
                 
                }
            }

       }
    }
    return root;
}


void in(node* root, node* &list)
{
    if(root->left)
    in(root->left, list);


    if(list == NULL)
    list = new node(root->data);
    else
    {
            node* temp = list;
        while(temp->right != NULL)
        {
            temp = temp->right;
        }
        temp->right = new node(root->data);
    }
   
    if(root->right)
    in(root->right,list);

    return;


}

node* BST_to_list(node* root)
{
    if(root == NULL)
    return NULL;

    node* list = NULL;
    in(root,list);

    return list;
}

int main()
{
     int arr[] = {6,2,8,0,4,7,9,3,5};
    node* root = BST(arr,9);
   node* list = BST_to_list(root);
   
   while(list != NULL)
   {
    cout<<list->data<<" ";
    list = list->right;
   }
    return 0;
}