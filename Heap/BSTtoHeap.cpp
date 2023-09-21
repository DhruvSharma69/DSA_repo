#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* right;
    node* left;
    node(int d){
        this->data = d;
        this->right = NULL;
        this->left = NULL;
    }
};
node* BST()
{
    int data;
    cout<<" Enter data ";
    cin>>data;
    if( data == -1)
    data = NULL;
    node* root = new node(data);
    if(data == NULL)
    return root;

    root->left = BST();
    root->right = BST();

    return root;
}


void getinorder(node* root,vector<int> &inorder)
{
    if(root == NULL)
    return;
    else{
        getinorder(root->left,inorder);

        inorder.push_back(root->data);

        getinorder(root->right,inorder);
    }
    
}
void createHeap(node* &heap, vector<int> inorder,int index)
{
    if(index <= 0)
    return;
    else{
        heap = new node(inorder[index]);
        int left = 2*index + 1;
        int right = 2*index +2;
        if(left<inorder.size() && right < inorder.size())
        {
            createHeap(heap->left,inorder,left);
            createHeap(heap->right,inorder,right);

        }
    }
}
node* getminHeap(node* root)
{
    vector<int> inorder;
     getinorder(root,inorder);
     node* heap = NULL;
     createHeap(heap,inorder,0);
     return heap;
}
int main()
{
    node* root = NULL;
    root = BST();

    // node* minHeap = NULL;
    // minHeap = getminHeap(root);

   // cout<<minHeap->data<<" "<<minHeap->left->data<<" "<<minHeap->right->data;
   cout<<root->data<<" "<<root->left->data<<" "<<root->right->data;

    return 0;

}