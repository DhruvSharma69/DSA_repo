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

};

node* BST( int arr[], int size)
{
    node* root = new node(arr[0]);       
    
    for(int i=1; i<size; i++)
    {
        node* temp = root;
        bool place_found = false;
       while(place_found == false)
       {
           // cout<<"hello";
            if(arr[i] < temp -> data)
            {
                if(temp->left != NULL)
                temp = temp->left;
                else
               {
                 temp ->left = new node(arr[i]);
                 place_found = true;
                 
                }
            }

             if(arr[i] > temp -> data)
            {
                if(temp->right != NULL)
                temp = temp->right;
                else
               {
                 temp ->right = new node(arr[i]);
                 place_found = true;
                 
                }
            }

       }
    }
    return root;
}




void it(node* root, vector<int> &v)
{
  
    if(root ->left)
     it(root->left, v);

    v.push_back(root->data);

    if(root->right)
     it(root->right,v);

    return;


}

bool TWOsum(node* root, int target)
{
    if(root == NULL)
    {
        return false;
    }

    vector<int> v ;
    it(root, v);

    int i=0, j = v.size()-1;
    while(i<=j)
    {
        if(v[i] + v[j] == target )
        return true;

        else if(v[i] + v[j] < target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    return false;
}


int main()

{
    int arr[] = {6,2,8,0,4,7,9,3,5};
    node* root = BST(arr,9);
    cout<<TWOsum(root,16);
    return 0;
}