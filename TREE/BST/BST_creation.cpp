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
void lvl_traversal(node* root)
{
    queue<node*> q;
    q.push(root);
     q.push(NULL);
    while(!q.empty())
    {
        node* temp = q.front();
        if(temp == NULL)
        {
            cout<<endl;
            q.pop();
            if(!q.empty())
            q.push(NULL);
        }
        else
        {
            cout<<temp->data<<" "; 
             q.pop();
             if(temp->left)
             q.push(temp->left);
             if(temp->right)
             q.push(temp->right);
        }
       

    }

}

bool search(node* root, int d)
{
    bool ans;
    if(root->data == d)
    {
        return true;
    }
    if(d<root->data)
    {
        if(root->left)
        {
           ans = search(root->left,d);
        }
        else
        return false;
    }
    else if(d> root->data)
    {
        if(root ->right)
        {
            ans = search(root->right, d);
        }
        else
        return false;
    }
    return ans;
}
int main()
{
  //  cout<<"hellow" ;
    int arr[] = {10 , 8 , 12, 15,7 ,11};
    node* root = NULL;
  root =   BST(arr,6);
  lvl_traversal(root);
  bool ans = search(root,7);
  cout<<"ans-> "<<ans;
    return 0;
}