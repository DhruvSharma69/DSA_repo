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

void Vertical_traversal(node* root)
{
    if(root == NULL)
    return;

    vector<pair<node*,int>> ans;
    int c = 0;
    queue<pair<node*,int>> q;
    pair<node*,int> p = make_pair(root,c);
    q.push(p);
    while(!q.empty())
    {
        node* temp = q.front().first;
        c = q.front().second;
        ans.push_back(q.front());
        q.pop();
        if(temp->left)
        {
            int j = c-1;
            pair<node*,int> p = make_pair(temp->left,j);
            q.push(p);
        }
        if(temp->right)
        {
            int j = c+1;
            pair<node*,int> p = make_pair(temp->right,j);
            q.push(p);
        }
    }

    // vector 'ans' contains all the nodes with a integer attached to it
    // we have to print in ascending order

    for(int i=0; i<ans.size(); i++)
    {
        for(int j = i+1; j<ans.size(); j++)
        {
            if(ans[j].second  < ans[i].second)
            swap(ans[i],ans[j]);
        }
    }

    // now sorting is done
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i].first->data<<"   "<<ans[i].second<<" "<<endl;
       
    }
}

void TOP_View(node* root)
{
        if(root == NULL)
    return;

    vector<pair<node*,int>> ans;
    int c = 0;
    queue<pair<node*,int>> q;
    pair<node*,int> p = make_pair(root,c);
    q.push(p);
    while(!q.empty())
    {
        node* temp = q.front().first;
        c = q.front().second;
        ans.push_back(q.front());
        q.pop();
        if(temp->left)
        {
            int j = c-1;
            pair<node*,int> p = make_pair(temp->left,j);
            q.push(p);
        }
        if(temp->right)
        {
            int j = c+1;
            pair<node*,int> p = make_pair(temp->right,j);
            q.push(p);
        }
    }

    // vector 'ans' contains all the nodes with a integer attached to it
    // we have to print in ascending order

    for(int i=0; i<ans.size(); i++)
    {
        for(int j = i+1; j<ans.size(); j++)
        {
            if(ans[j].second  < ans[i].second)
            swap(ans[i],ans[j]);
        }
    }

    // now sorting is done
    for(int i=0; i<ans.size(); i++)
    {
        if(i == 0)
        {
            cout<<ans[i].first->data<<" ";
        }
       else if( ans[i].second != ans[i-1].second )
        cout<<ans[i].first->data<<" ";
        
       
    }
}

void BOTTOM_VIEW(node* root)
{
    {
        if(root == NULL)
    return;

    vector<pair<node*,int>> ans;
    int c = 0;
    queue<pair<node*,int>> q;
    pair<node*,int> p = make_pair(root,c);
    q.push(p);
    while(!q.empty())
    {
        node* temp = q.front().first;
        c = q.front().second;
        ans.push_back(q.front());
        q.pop();
        if(temp->left)
        {
            int j = c-1;
            pair<node*,int> p = make_pair(temp->left,j);
            q.push(p);
        }
        if(temp->right)
        {
            int j = c+1;
            pair<node*,int> p = make_pair(temp->right,j);
            q.push(p);
        }
    }

    // vector 'ans' contains all the nodes with a integer attached to it
    // we have to print in ascending order

    for(int i=0; i<ans.size(); i++)
    {
        for(int j = i+1; j<ans.size(); j++)
        {
            if(ans[j].second  < ans[i].second)
            swap(ans[i],ans[j]);
        }
    }

    // now sorting is done
    for(int i=0; i<ans.size(); i++)
    {
        if(i == ans.size() - 1)
        {
            cout<<ans[i].first->data<<" ";
        }
       else if( ans[i].second != ans[i+1].second )
        cout<<ans[i].first->data<<" ";
        
       
    }
}
}
int main()
{
    node* r = NULL;
    r = BT();
    Vertical_traversal(r);
    cout<<endl<<endl;
    TOP_View(r);
    cout<<endl<<endl;
    BOTTOM_VIEW(r);
    return 0 ;
}