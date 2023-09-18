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

bool isIdentical(node* r1, node* r2)
{
    if(r1==NULL && r2 == NULL)
    return true;

    else if((r1 == NULL && r2 != NULL)  || (r1 != NULL && r2 == NULL))
    return false;

    else
    {
        bool left =  isIdentical(r1->left , r2 ->left);

        bool right = isIdentical(r1->right , r2 ->right);
        if(r1->data == r2 ->data && right && left)
        {
          return true;
        }
        else
        {
            return false;
        }
    }
}
// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
int main()
{
    node* r1 = NULL;
    node* r2 = NULL;
    r1 = BT();
    r2 = BT();
    cout<<"\nANSWEr\n"<<isIdentical(r1,r2);
}