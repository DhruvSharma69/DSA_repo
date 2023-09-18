#include<iostream>
#include<queue>
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

// INPUT ->  1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

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

void ZigZag(node* root)
{
    if(root == NULL)
    return;

    bool leftToRight = true;
    vector<int> ans;
    queue<node*> q;
    q.push(root);

    while(!q.empty())
    {
        int size = q.size();
        vector<int> v(size);
        for(int i=0; i<size; i++)
        {
            node* temp = q.front();
            q.pop();
            int index = leftToRight ? i : size-1-i;
            v[index] = temp->data;
            
            if(temp->left)
            {
                q.push(temp->left);
            }
             if(temp->right)
            {
                q.push(temp->right);
            }
        }

        leftToRight = !leftToRight;
        for(auto i: v)
        {
            ans.push_back(i);
        }
    }

    for(int i=0; i< ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }


}

int main()
{
    node* r = NULL;
    r = BT();
    ZigZag(r);
    return 0;
}