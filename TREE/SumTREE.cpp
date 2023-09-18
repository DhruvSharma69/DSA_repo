#include<iostream>
using namespace std;

class node
{
     public:
    int data;
    node*left;
    node*right;

   
    node (int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

node* BT()
{
    cout<<" Enter the root node\n";
    int data;
    cin>>data;
    if(data == -1)
    return NULL;

    node* root = new node(data);
    
    cout<<"\n Enter left of "<<data<<endl;
    root->left = BT();

    cout<<"\n Enter right of "<<data<<endl;
    root->right = BT();

    return root;

}

pair<bool,int> isSUM(node* r)
{
    if(r == NULL)
    {
        pair<bool,int> o = make_pair(true,0);
        return o;
    }

    pair<bool,int> left = isSUM(r->left);
    pair<bool,int> right = isSUM(r->right);

    pair<bool,int> ans;
    int val = left.second + right.second;
    ans.second = val + r->data;
    
    if(r->left == NULL && r->right == NULL)
    {
        ans.first = true;
    }
    else
    {
        if(left.first && right.first && (val == r->data))
        {
                ans.first = true;
        }
        else 
        ans.first =  false;
    }

    return ans;

    
}
// 5 4 -1 -1 1 -1 -1 
int main()
{
    node* r = NULL;
    r = BT();
    pair<bool,int> p = isSUM(r);
    cout<<"\nAnswer\n"<<p.first;
    return 0;
}