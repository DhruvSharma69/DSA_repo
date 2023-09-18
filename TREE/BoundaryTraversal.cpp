#include<iostream>
#include<queue>
#include<vector>
#include<stack>

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

// INPUT ->  1 2 4 -1 -1 5 8 -1 -1 9 -1 -1 3 6 -1 -1 7 -1 10 -1 -1

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

void Boundary_Traversal(node* root)

{

    cout<<" \n start the Bournary traversal \n";
    if(root == NULL)
    {
        return ;
    }
    node* temp  = root;
    vector<int> ans;
    // first include only left part of tree excluding leaf node
    while(temp->left != NULL && temp->right != NULL)
    {
        ans.push_back(temp->data);
        temp = temp->left;
    }

    cout<<"\n now only leaf nodes should be included";
    temp = root;
    queue<node*> q; //for iterative traversal of tree
    q.push(temp);
    while(!q.empty())
    {
        cout<<" * ";
        node* tempp = q.front();  // node tempp is being traversed

        if(tempp->left == NULL && tempp->right == NULL)
        ans.push_back(tempp->data);

        q.pop();
      if(tempp->left)
        q.push(tempp->left);

         if(tempp->right)
        q.push(tempp->right);
    }

    cout<<" \n now traversal of right sub tree excluding root node in reverse order";
    temp = root->right;
    stack<node*> s;
    while(temp->left != NULL && temp->right != NULL)
    {
        s.push(temp);
        temp = temp->right;

    }
    
    while(!s.empty())
    {
        ans.push_back(s.top() ->data);
        s.pop();
    }


    cout<<" \n now vector 'ans' is ready for traversal ";
    for(int i=0; i<ans.size(); i++)
    cout<<ans[i]<<" ";

}

int main()
{
     node* r = NULL;
    r = BT();
     //printT(r);
     Boundary_Traversal(r);
     return 0;
}