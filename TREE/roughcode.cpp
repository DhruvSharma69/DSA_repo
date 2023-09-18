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

// INPUT ->  1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1             1 2 -1 -1 3 -1 -1

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

void pp(node* root)
{
    vector<int> ans;
   node*  temp = root;
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
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
}
int main()
{
    node* r = NULL;
     r = BT();
     pp(r);
     return 0;
}