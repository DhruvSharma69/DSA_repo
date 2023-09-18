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

int Height_of_tree(node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int left = Height_of_tree(root->left);
    int right = Height_of_tree(root->right);

    int ans = max(left,right) + 1;

    return ans;

}
// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
int main()
{
    node* r = NULL;
    r = BT();
   cout<<"HEIGHT->"<< Height_of_tree(r);
return 0 ;
}