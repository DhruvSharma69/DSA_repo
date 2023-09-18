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

pair<bool,int> isBalanced(node* root)
{
    if(root == NULL)
    {
        pair <bool,int> p = make_pair(true,0);

        return p;
    }

   pair<bool,int> left =  isBalanced(root->left);
   pair<bool,int> right =  isBalanced(root->right);
    bool diff = abs(left.second - right.second ) <=1;
    pair<bool , int> ans;
    ans.second = max(left.second , right.second) + 1;
    if(left.first == true && left.second == true && diff == true)
    ans.first = true;
    else
    ans.first = false;

    return ans;

}

bool Answer(pair<bool,int> p)
{
    return p.first;
}
// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
int main()
{
    node* r = NULL;
    r = BT();

    cout<<" the amswer is \n"<<Answer(isBalanced(r));
    return 0;
}