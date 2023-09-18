#include<iostream>
#include<queue>

using namespace std; 

class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;  
    }
};

// INPUT ->  1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

node* BT()
{
    cout<<"Enter the data for root node \n";
    int d;
    cin>>d;

    if(d== -1)
    return NULL;

    node* root = new node(d);
    cout<<"\n Enter left  of  "<<d<<endl;
    root ->left = BT();

    cout<<"\n Enter right of  "<<d<<endl;
    root ->right = BT();

    return root;

}

void printT(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty())
            q.push(NULL);
        }
        else

        {
            cout<<temp->data;
            if(temp->left)
            {
                q.push(temp->left);
            }

             if(temp->right)
            {
                q.push(temp->right);
            }
        }


    }
}

void INORDER(node* root)
{
    if(root == NULL)
    {
        return ;
    }

    INORDER(root->left);
    cout<<root->data<<" ";
    INORDER(root->right);
}

void PREORDER(node* root)
{
    if(root == NULL)
    {
        return ;
    }
    cout<<root->data<<" ";

    PREORDER(root->left);
    
    PREORDER(root->right);
}

void POSTORDER(node* root)
{
    if(root == NULL)
    {
        return ;
    }

    POSTORDER(root->left);
    
    POSTORDER(root->right);

    cout<<root->data<<" ";
}

void INORDER_2(node* root, int & count)
{
     if(root == NULL)
    {
        return ;
    }

    INORDER_2(root->left,count);
  if(root->right == NULL && root->left == NULL)
  {
    count++;
  }
    INORDER_2(root->right,count);
}



int COUNT_lEAF(node* root)
{
    int c= 0;
   
 INORDER_2(root,c);

    return c;
}



int main()
{
    node* r = NULL;
    r = BT();
    // printT(r);

    // cout<<"\n Now INORDER traversal \n";
    // INORDER(r);

    // cout<<"\n Now PREORDER traversal \n";
    // PREORDER(r);

    // cout<<"\n Now POSTORDER traversal \n";
    // POSTORDER(r);

    cout<<COUNT_lEAF(r);

    return 0;
}