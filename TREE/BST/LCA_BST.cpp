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



node* LCA(node* root, node* A , node* B)
{
    node* ans;
    if(root->data < max(A->data,B->data) && root->data > min(A->data,B->data))
    {
        return root; 
    }
     if(root->data >max(A->data,B->data))
    {
        ans = LCA(root->left,A,B);
    }
    if(root->data < min(A->data,B->data) )
    {
        ans =  LCA(root->right, A, B);
    }

    return ans;
}

int main()
{
    int arr[] = {6,2,8,0,4,7,9,3,5};
    node* root = BST(arr,9);
    lvl_traversal(root);
    cout<<endl<<endl;
    cout<< LCA(root,root->right,root->left)->data;
    return 0;
}
