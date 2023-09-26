#include<iostream>
#include<vector>
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

// INPUT ->  50 30 -1 -1 49 -1 -1           isHeap
// INPUT ->  50 30 -1 -1 49 -1 15  -1 -1         not Heap
// INPUT ->  50 30 -1 -1 51 -1 -1           not Heap

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
void countNodes(node* root, int &total)
{
    if(root == NULL)
    {
        return ;
    }

    else{
        total++;
        countNodes(root->left,total);
        countNodes(root->right,total);
        return;
    }
}
bool isCT(node* root,int total)
{
    if(root == NULL)
    return true;

    else if(root->left == NULL && root->right!=NULL)
        return false;
        
    else
    {
            bool left = isCT(root->left,total);
            bool right = isCT(root->right,total);
            return (right && left); 
    }
}
bool isMaxOrder(node* root, int total)
{
    if(root == NULL)
    {
        return true;
    }
   else if(root->left && (root->data < root->left->data) )
   return false;

   else if(root->right && (root->data < root->right->data))
   return false;

   else{
        bool left = isMaxOrder(root->left,total);
        bool right = isMaxOrder(root->right,total);

        return (left && right);
   }
            
    

}
bool isHeap(node* root)
{    int total = 0;   
    countNodes(root,total);       // will get the total number of nodes in a tree
    if( isCT(root,total) && isMaxOrder(root,total))  // will check if tree is both complete tree and Maxorder
    return true;
    else
    return false;
}

int main()
{
    node* root = NULL;
    root = BT();
    // now we have a BT with root
    cout<<"\nAnswer  "<<isHeap(root);
    return 0;

}