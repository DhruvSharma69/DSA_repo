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

        //member func
         void  Tree_display(node* root)
{
    queue<node*> q ;
    q.push(root);
    while(!q.empty())
    {
        node* temp = q.front();
        cout<<" node -> "<<temp->data;
        if(temp->left == NULL)
        cout <<" left  "<<"-1";
        else
       cout <<" left  "<<temp->left->data;
        if(temp->right == NULL)
        cout <<" right  "<<"-1"<<endl;
        else
        cout<<"  right  "<<temp->right->data<<endl;


        q.pop();
        if(temp->left)
        q.push(temp->left);

        if(temp->right)
        q.push(temp->right);

    }

    
}

};

node* solve(int mini, int maxi , int &i, vector<int> Preorder)
{
    if(i>= Preorder.size())
    return NULL;

    if(Preorder[i] > maxi || Preorder[i] < mini)
    return NULL;

    node* root = new node(Preorder[i++]);
    root->left = solve(mini, root->data, i , Preorder);

    root->right = solve(root->data, maxi,i,Preorder);
    
    return root;
}

node* Answer(vector<int> Preorder)
{
    int mini = INT_MIN, maxi = INT_MAX;
    int i=0;
    return solve(mini,maxi,i,Preorder);
}

int main()
{
    vector<int> Preorder = {20,10,5,15,13,35,30,42};

    node* root_BST = Answer(Preorder);
    node obj(NULL);
    obj.Tree_display(root_BST);
    return 0; 
}