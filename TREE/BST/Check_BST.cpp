#include<iostream>
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

bool check_bst(node* root,int u, int l)

{
    if(root == NULL)
    return true;

    if(root->data < u && root->data > l)
    {
        
        
      bool right = check_bst(root->right,u,root->data);
        
     bool  left = check_bst(root->left,root->data,l);
        return right && left;
    }
    else
    {
        return false;
    }
}

int main()
{
    node* root = new node(5);
    root->right = new node(6);
    root->left = new node(4);

    cout<<check_bst(root,INT_MAX,INT_MIN);
    return 0;
}
