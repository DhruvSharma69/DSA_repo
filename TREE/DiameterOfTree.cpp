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
// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

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

pair<int,int> Diameter_Of_Tree(node* root)
{
    if(root == NULL)
    {
        pair<int,int> p = make_pair(0,0);
        return p ;
    }
    pair<int,int> left  = Diameter_Of_Tree(root->left);
    pair<int,int> right  = Diameter_Of_Tree(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 =(left.second + right.second) + 1 ;

    pair<int,int> ans;
    ans.first = max(op1, max(op2,op3));
    ans.second = max(left.second,right.second) + 1;

    return ans;

}

int main()
{
    pair<int, int> p;
    node* r = NULL;
    r = BT();
    cout<<"DIAMETER is ->"<<Diameter_Of_Tree(r).first;
}