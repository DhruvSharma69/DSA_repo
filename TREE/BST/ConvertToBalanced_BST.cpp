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
        if(temp->right)
        q.push(temp->right);

        if(temp->left)
        q.push(temp->left);

    }

    
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


void in(node* root, vector<int> &v)         // inorder sorted in array "v" 
{
    if(root->left)
    in(root->left, v);

    v.push_back(root->data);

    if(root->right)
    {
        in(root->right,v);
    }

    return ;

}

node* create_BST(int s, int e, vector<int> &v)
{
    if(s > e)
    return NULL;

    int mid = (s+e) / 2;
    node* root = new node(v[mid]);

    root->left = create_BST(s, mid-1, v);
    root->right = create_BST(mid+1, e, v);
    

    return root;

}

node* solution(node* root)
{
    vector<int> store_inorder;
     in(root,store_inorder);
     node* ans = create_BST(0,store_inorder.size() -1,store_inorder);
     return ans;
}

int main()
{
    int arr[] = {10,5,15,20,25};
    node* root_BST = BST(arr,5);

    node* root_EBST = solution(root_BST);

    cout<<"\n print \n \n";
    root_EBST->Tree_display(root_EBST);

    return 0;
}