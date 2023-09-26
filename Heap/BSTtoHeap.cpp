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
node* BST(int arr[],int size)
{
    node* root = new node(arr[0]);  //first element is set as node
    for(int i=1; i<size; i++)
    {
        node* temp = root;
        bool placeFound = false;
        while(placeFound == false)
        {
            if(arr[i] > temp->data)
            {
                if(temp->right)
                temp = temp->right;

                else{
                    temp->right = new node(arr[i]);
                    placeFound = true;
                }
            }

            else{
                if(temp ->left)
                temp = temp->left;

                else{
                    temp->left = new node(arr[i]);
                    placeFound = true;
                }
            }
        }
    }
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
    if(index < 0)
    return;
    else{
        heap = new node(inorder[index]);
        int left = 2*index + 1;
        int right = 2*index +2;
        if(left<inorder.size())
        {
            createHeap(heap->left,inorder,left);
        }
        if(right < inorder.size())
        {
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
    int arr[] = {5,4,8,6,7};
    node* root = NULL;
    root = BST(arr,5);

    node* minHeap = NULL;
    minHeap = getminHeap(root);
    cout<<minHeap->data<<" "<<minHeap->left->data<<" "<<minHeap->right->data;
    cout<<" "<<minHeap->left->left->data<<" "<<minHeap->left->right->data;
    return 0;

}